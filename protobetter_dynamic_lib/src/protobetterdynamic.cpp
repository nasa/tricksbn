#include <cstring>
#include <bitset>

#include <QtGlobal>

#include <QtEndian>
#include <QFile>
#include <QTextStream>

#include <stdexcept>

#include "protobetterdynamic.h"

namespace
{
    Protobetter::Prototype BuildPrototypeFromJsonObject(QJsonObject object)
    {
        QString typeName = object["typeName"].toString();

        Protobetter::Prototype prototype(typeName);

        QJsonArray members = object["members"].toArray();

        for (int i = 0; i < members.count(); ++i)
        {
            QJsonObject member = members.at(i).toObject();

            Protobetter::PrototypeMember ptypeMember;
            ptypeMember.name = member["name"].toString();
            ptypeMember.type = member["type"].toString();

            if (member.contains("name"))
            {
                ptypeMember.arrayLength = member["arraylen"].toInt();
            }

            if (member.contains("bits"))
            {
                ptypeMember.bits = member["bits"].toInt();
            }

            prototype.members.push_back(ptypeMember);
        }

        return prototype;
    }

    static uint64_t CalculatePackingMask(std::size_t bitOffset, std::size_t fieldWidth)
    {
        uint64_t mask = 0;

        for (uint64_t i = 0; i < 64; ++i)
        {
            uint64_t one = 1;

            if ((i < bitOffset) || (i >= (bitOffset + fieldWidth)))
            {
                mask |= (one << i);
            }
        }

        return mask;
    }

    uint64_t GetTwosComplementUnsignedEquivalent(int64_t value, std::size_t bitfieldWidth)
    {
        bool isNegative = (value < 0) ? true : false;

        uint64_t magnitude;

        if (isNegative)
        {
            magnitude = (~value + 1);

            // I just want to freaking thank whoever thought to add the
            // 'bitset' type to the standard template library in c++...
            // somebody give that wonderful human being an award!
            std::bitset<64> bits(magnitude);

            for (int i = 0; i < bitfieldWidth; ++i)
            {
                bits[i] = bits[i] ? 0 : 1;
            }

            return bits.to_ullong() + 1;
        }
        else
        {
            return value;
        }
    }

    int64_t GetTwosComplementSignedEquivalent(uint64_t value, std::size_t bitfieldWidth)
    {
        std::bitset<64> bits(value);

        bool isNegative = bits[bitfieldWidth-1];

        if (isNegative)
        {
            for (int i = 0; i < bitfieldWidth; ++i)
            {
                bits[i] = bits[i] ? 0 : 1;
            }

            uint64_t magnitude = bits.to_ullong() + 1;

            int64_t signedRepresentation = magnitude;

            return signedRepresentation * -1;
        }
        else
        {
            return bits.to_ullong();
        }
    }
}

Protobetter::FieldAccessor::FieldAccessor()
    : size(0), byteOffset(0), bitOffset(0), packingMask(0), type(ProtobetterFieldType::Object)
{
}

Protobetter::FieldAccessor::FieldAccessor(ProtobetterFieldType type, std::size_t size)
    : size(size), byteOffset(0), bitOffset(0), packingMask(0), type(type)
{
}

Protobetter::DynamicType::DynamicType(QString name, bool isRoot)
    : name(name), isRoot(isRoot)
{
}

bool Protobetter::PrototypeCollection::HasType(QString typeName) const
{
    for (int i = 0; i < this->rootTypes.size(); ++i)
    {
        if (this->rootTypes[i].name == typeName)
            return true;
    }

    return false;
}

bool Protobetter::Prototype::HasMember(QString memberName)
{
    for (int i = 0; i < this->members.size(); ++i)
    {
        if (this->members[i].name == memberName)
        {
            return true;
        }
    }

    return false;
}

Protobetter::PrototypeMember Protobetter::Prototype::GetMember(QString memberName)
{
    for (int i = 0; i < this->members.size(); ++i)
    {
        if (this->members[i].name == memberName)
        {
            return this->members[i];
        }
    }

    QString msg = QString("Prototype::GetMember() ERROR: prototype has no member named ") + memberName;
    throw std::runtime_error(msg.toStdString().c_str());
}

Protobetter::Prototype Protobetter::PrototypeCollection::GetType(QString typeName) const
{
    for (int i = 0; i < this->rootTypes.size(); ++i)
    {
        if (this->rootTypes[i].name == typeName)
        {
            return this->rootTypes[i];
        }
    }

    QString msg = QString("PrototypeCollection::GetType() ERROR: collection has no type named ") + typeName;
    throw std::runtime_error(msg.toStdString().c_str());
}

void Protobetter::PrototypeCollection::AddPrototype(const Prototype &prototype)
{
    this->rootTypes.append(prototype);
}

bool Protobetter::DynamicTypeCollection::HasType(QString typeName)
{
    for (int i = 0; i < this->rootTypes.size(); ++i)
    {
        if (this->rootTypes[i]->Name() == typeName)
        {
            return true;
        }
    }

    return false;
}

std::size_t Protobetter::DynamicTypeCollection::Size() const
{
    return this->rootTypes.size();
}

Protobetter::Prototype Protobetter::PrototypeCollection::GetType(const int index) const
{
    return this->rootTypes.at(index);
}

Protobetter::DynamicType::Ptr Protobetter::DynamicTypeCollection::GetType(int index)
{
    return this->rootTypes.at(index);
}

Protobetter::DynamicType::Ptr Protobetter::DynamicTypeCollection::GetType(QString typeName)
{
    for (int i = 0; i < this->rootTypes.size(); ++i)
    {
        if (this->rootTypes[i]->Name() == typeName)
        {
            return this->rootTypes[i];
        }
    }

    QString msg = QString("DynamicTypeCollection::GetType() ERROR: collection has no type named ") + typeName;
    throw std::runtime_error(msg.toStdString().c_str());
}

void Protobetter::DynamicTypeCollection::AddDynamicType(const DynamicType::Ptr ptr)
{
    this->rootTypes.append(ptr);
}

void Protobetter::DynamicTypeCollection::CreateDynamicTypeFromPrototypeRecursive(const PrototypeCollection &prototypes, DynamicTypeCollection &dynamicTypes, const Protobetter::Prototype &ptype)
{
    if (dynamicTypes.HasType(ptype.name))
    {
        return;
    }

    auto newDynamicType = Protobetter::FieldCollection::CreateNewRootType(ptype.name);

    Protobetter::BitfieldCollection::Ptr currentBitfieldCollection = nullptr;

    for (int i = 0; i < ptype.members.size(); ++i)
    {
        std::size_t memberSize = 0;
        bool isPrimitiveType = true;

        ProtobetterFieldType type;

        if (ptype.members[i].type == "uint8_t")
        {
            type = ProtobetterFieldType::UInt8;
            memberSize = 1;
        }
        else if (ptype.members[i].type == "int8_t")
        {
            type = ProtobetterFieldType::Int8;
            memberSize = 1;
        }
        else if (ptype.members[i].type == "uint16_t")
        {
            type = ProtobetterFieldType::UInt16;
            memberSize = 2;
        }
        else if (ptype.members[i].type == "int16_t")
        {
            type = ProtobetterFieldType::Int16;
            memberSize = 2;
        }
        else if (ptype.members[i].type == "uint32_t")
        {
            type = ProtobetterFieldType::UInt32;
            memberSize = 4;
        }
        else if (ptype.members[i].type == "int32_t")
        {
            type = ProtobetterFieldType::Int32;
            memberSize = 4;
        }
        else if (ptype.members[i].type == "float")
        {
            type = ProtobetterFieldType::Float;
            memberSize = 4;
        }
        else if (ptype.members[i].type == "uint64_t")
        {
            type = ProtobetterFieldType::UInt64;
            memberSize = 8;
        }
        else if (ptype.members[i].type == "int64_t")
        {
            type = ProtobetterFieldType::Int64;
            memberSize = 8;
        }
        else if (ptype.members[i].type == "double")
        {
            type = ProtobetterFieldType::Double;
            memberSize = 8;
        }
        else if (ptype.members[i].type == "bytearray")
        {
            type = ProtobetterFieldType::ByteArray;
            memberSize = ptype.members[i].arrayLength;
        }
        else // it's be a user-defined type
        {
            isPrimitiveType = false;

            // first check to see if we already have a complete root type for this ptype member
            if (!dynamicTypes.HasType(ptype.members[i].type))
            {
                // if a dynamic type wasn't already created for this member type, let's look for a prototype def that matches and create one recursively
                if (prototypes.HasType(ptype.members[i].type))
                {
                    const Prototype newPrototype = prototypes.GetType(ptype.members[i].type);
                    CreateDynamicTypeFromPrototypeRecursive(prototypes, dynamicTypes, newPrototype);
                }
                else
                {
                    // this is definitely an 'exceptional' error at this point - everything should've been sanitized before you started building the graph... if condition is met, go ahead and throw it.
                    QString msg = QString("Protobetter::FieldCollection::CreateDynamicTypeFromPrototypeRecursive() ERROR: No prototype definition found for root type ") + ptype.members[i].type;
                    throw std::runtime_error(msg.toStdString().c_str());
                }
            }

            memberSize = dynamicTypes.GetType(ptype.members[i].type)->Size();
        }

        if (ptype.members[i].bits > 0) // it's a bitfield...
        {
            if (currentBitfieldCollection.isNull())
            {
                currentBitfieldCollection = Protobetter::BitfieldCollection::CreateNewBitfieldCollection(memberSize);
            }
            else if (currentBitfieldCollection->Size() != memberSize || currentBitfieldCollection->BitsAvailable() < ptype.members[i].bits)
            {
                currentBitfieldCollection->Finalize();
                newDynamicType->AddField(currentBitfieldCollection);
                currentBitfieldCollection = nullptr;

                currentBitfieldCollection = Protobetter::BitfieldCollection::CreateNewBitfieldCollection(memberSize);
            }

            bool isSigned = ptype.members[i].type.startsWith("i") ? true : false;

            currentBitfieldCollection->AddField(ptype.members[i].name, ptype.members[i].bits, isSigned);

            if (i == ptype.members.size() - 1)
            {
                currentBitfieldCollection->Finalize();
                newDynamicType->AddField(currentBitfieldCollection);
            }
        }
        else if (ptype.members[i].arrayLength > 0 && ptype.members[i].type != "bytearray") // it's an array
        {
            if (!currentBitfieldCollection.isNull())
            {
                currentBitfieldCollection->Finalize();
                newDynamicType->AddField(currentBitfieldCollection);
                currentBitfieldCollection = nullptr;
            }

            for (int j = 0; j < ptype.members[i].arrayLength; ++j)
            {
                QString memberName = ptype.members[i].name + QString("[") + QString::number(j) + QString("]");

                if (isPrimitiveType)
                {
                    newDynamicType->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField(memberName, type, memberSize));
                }
                else
                {
                    auto rootType = qSharedPointerCast<Protobetter::FieldCollection>(dynamicTypes.GetType(ptype.members[i].type));
                    newDynamicType->AddField(Protobetter::FieldCollection::CreateFieldFromRootType(memberName, rootType, true));
                }
            }
        }
        else // it's just a normal field
        {
            if (!currentBitfieldCollection.isNull())
            {
                currentBitfieldCollection->Finalize();
                newDynamicType->AddField(currentBitfieldCollection);
                currentBitfieldCollection = nullptr;
            }

            if (isPrimitiveType)
            {
                newDynamicType->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField(ptype.members[i].name, type, memberSize));
            }
            else
            {
                auto rootType = qSharedPointerCast<Protobetter::FieldCollection>(dynamicTypes.GetType(ptype.members[i].type));
                newDynamicType->AddField(Protobetter::FieldCollection::CreateFieldFromRootType(ptype.members[i].name, rootType, true));
            }
        }
    }

    newDynamicType->Finalize();

    dynamicTypes.AddDynamicType(newDynamicType);
}

QStringList Protobetter::DynamicTypeCollection::GetRootTypeNames()
{
    QStringList names;

    for (int i = 0; i < rootTypes.size(); ++i)
    {
        names << rootTypes[i]->Name();
    }

    return names;
}

Protobetter::DynamicTypeCollection Protobetter::DynamicTypeCollection::FromPrototypeCollection(const Protobetter::PrototypeCollection &prototypes)
{
    Protobetter::DynamicTypeCollection dynamicTypes;

    // recursively build up your DynamicTypeCollection
    for (int i = 0; i < prototypes.Size(); ++i)
    {
        Protobetter::DynamicTypeCollection::CreateDynamicTypeFromPrototypeRecursive(prototypes, dynamicTypes, prototypes.GetType(i));
    }

    return dynamicTypes;
}

QString Protobetter::DynamicType::Name()
{
    return this->name;
}

bool Protobetter::DynamicType::IsRoot()
{
    return this->isRoot;
}

Protobetter::FieldCollection::FieldCollection(QString name, bool isRoot)
    : DynamicType(name, isRoot), isComplete(false), memberAccessors(new QMap<QString, Protobetter::FieldAccessor>())
{
}

bool Protobetter::FieldCollection::IsComplete()
{
    return this->isComplete;
}

QSharedPointer<QMap<QString, Protobetter::FieldAccessor> > Protobetter::FieldCollection::GetMemberAccessors()
{
    return this->memberAccessors;
}

Protobetter::ProtobetterFieldType Protobetter::FieldCollection::GetFieldType(QString name)
{
    if (!this->isComplete)
    {
        throw std::runtime_error("Protobetter::FieldCollection::GetFieldType ERROR: can't access field type info until type is complete!");
    }

    // TODO: some validation for debug builds...
    return this->memberAccessors->value(name).type;
}

void Protobetter::FieldCollection::Finalize()
{
    if (!this->isComplete)
    {
        std::size_t currentOffset = 0;

        if (!this->IsRoot())
        {
            Protobetter::FieldAccessor accessor(ProtobetterFieldType::Object, this->Size());
            accessor.byteOffset = 0;

            this->memberAccessors->insert(this->name, accessor);
        }

        for (int i = 0; i < this->fields.size(); ++i)
        {
            auto currentMemberAccessors = this->fields[i]->GetMemberAccessors();

            for (auto iter = currentMemberAccessors->constBegin();
                 iter != currentMemberAccessors->constEnd();
                 iter++)
            {
                QString fieldPath;

                if (this->isRoot)
                {
                    fieldPath = iter.key();
                }
                else
                {
                    fieldPath = this->name + QString(".") + iter.key();
                }

                Protobetter::FieldAccessor accessor = iter.value();

                accessor.byteOffset += currentOffset;

                this->memberAccessors->insert(fieldPath, accessor);
            }

            currentOffset += this->fields[i]->Size();
        }

        this->isComplete = true;
    }
}

std::size_t Protobetter::FieldCollection::MemberCount()
{
    return this->fields.size();
}

std::size_t Protobetter::FieldCollection::Size()
{
    std::size_t size = 0;

    for (int i = 0; i < this->fields.size(); ++i)
    {
        size += this->fields[i]->Size();
    }

    return size;
}

Protobetter::BitfieldCollection::Bitfield::Bitfield()
    : name(""), bitOffset(0), length(0), isSigned(true)
{
}

Protobetter::BitfieldCollection::Bitfield::Bitfield(QString name, std::size_t bitOffset, std::size_t length, bool isSigned)
    : name(name), bitOffset(bitOffset), length(length), isSigned(isSigned)
{
}

Protobetter::BitfieldCollection::BitfieldCollection(std::size_t size)
    : DynamicType("", false), size(size), isComplete(false), memberAccessors(new QMap<QString, FieldAccessor>())
{
}

bool Protobetter::BitfieldCollection::IsComplete()
{
    return this->isComplete;
}

QSharedPointer<QMap<QString, Protobetter::FieldAccessor> > Protobetter::BitfieldCollection::GetMemberAccessors()
{
    return this->memberAccessors;
}

void Protobetter::BitfieldCollection::Finalize()
{
    if (!this->isComplete)
    {
        for (int i = 0; i < this->bitfields.size(); ++i)
        {
            ProtobetterFieldType type = this->bitfields[i].isSigned ? ProtobetterFieldType::SignedBitfield : ProtobetterFieldType::UnsignedBitfield;

            Protobetter::FieldAccessor accessor(type, this->size);
            accessor.bitOffset = this->bitfields[i].bitOffset;
            accessor.byteOffset = 0; // always a '0' byte offset within this field
            accessor.bitfieldSize = this->bitfields[i].length;

            accessor.packingMask = CalculatePackingMask(this->bitfields[i].bitOffset, this->bitfields[i].length);

            this->memberAccessors->insert(this->bitfields[i].name, accessor);
        }

        this->isComplete = true;
    }
}

Protobetter::ProtobetterFieldType Protobetter::BitfieldCollection::GetFieldType(QString name)
{
    if (!this->isComplete)
    {
        throw std::runtime_error("Protobetter::BitfieldCollection::GetFieldType ERROR: can't access field type info until type is complete!");
    }

    // TODO: some validation for debug builds and return the right sign...
    return Protobetter::SignedBitfield;
}

QSharedPointer<Protobetter::BitfieldCollection> Protobetter::BitfieldCollection::CreateNewBitfieldCollection(std::size_t size)
{
    if (!(size == 1 || size == 2 || size == 4 || size == 8))
    {
        throw std::invalid_argument("Protobetter::BitfieldCollection can only be created with a size of 1, 2, 4, or 8 bytes!");
    }

    return QSharedPointer<Protobetter::BitfieldCollection>(new Protobetter::BitfieldCollection(size));
}

std::size_t Protobetter::BitfieldCollection::BitsUsed()
{
    std::size_t bitsUsed = 0;

    for (int i = 0; i < this->bitfields.size(); ++i)
    {
        bitsUsed += this->bitfields.value(i).length;
    }

    return bitsUsed;
}

std::size_t Protobetter::BitfieldCollection::BitsAvailable()
{
    return (this->Size() * 8) - this->BitsUsed();
}

void Protobetter::BitfieldCollection::AddField(QString name, std::size_t width, bool isSigned)
{
    if (this->BitsAvailable() < width)
    {
        throw std::invalid_argument(std::string("Protobetter::BitfieldCollection doesn't have space for field: ") + name.toStdString());
    }
    else if (this->isComplete)
    {
        throw std::runtime_error("Protobetter::BitfieldCollection::AddField() can not be called once it has been finalized!");
    }

    for (int i = 0; i < this->bitfields.size(); ++i)
    {
        if (this->bitfields[i].name == name)
        {
            throw std::invalid_argument("Protobetter::BitfieldCollection::AddField() ERROR: can not add two bitfields with same name to a collection");
        }
    }

    this->bitfields.append(Bitfield(name, this->BitsUsed(), width, isSigned));
}

std::size_t Protobetter::BitfieldCollection::Size()
{
    return this->size;
}

std::size_t Protobetter::BitfieldCollection::MemberCount()
{
    return this->bitfields.size();
}

Protobetter::Prototype::Prototype(QString name)
    : name(name)
{

}

Protobetter::Prototype::Prototype()
{
}

QSharedPointer<Protobetter::PrimitiveField> Protobetter::PrimitiveField::CreateNewPrimitiveField(QString name, ProtobetterFieldType type, std::size_t size)
{
    if (size == 0)
    {
        throw std::invalid_argument("Cannot create a Protobetter::PrimitiveField w/ size = 0!");
    }

    return QSharedPointer<Protobetter::PrimitiveField>(new Protobetter::PrimitiveField(name, type, size));
}

Protobetter::ProtobetterFieldType Protobetter::PrimitiveField::GetFieldType(QString name)
{
    return this->type;
}

Protobetter::PrimitiveField::PrimitiveField(QString name, ProtobetterFieldType type, std::size_t size)
    : DynamicType(name, false), size(size), type(type), memberAccessors(new QMap<QString, Protobetter::FieldAccessor>())
{
    this->memberAccessors->insert(this->name, Protobetter::FieldAccessor(type, this->size));
}

std::size_t Protobetter::PrimitiveField::Size()
{
    return this->size;
}

bool Protobetter::PrimitiveField::IsComplete()
{
    return true; // a primitive field is always a complete type
}

QSharedPointer<QMap<QString, Protobetter::FieldAccessor> > Protobetter::PrimitiveField::GetMemberAccessors()
{
    return this->memberAccessors;
}

std::size_t Protobetter::PrimitiveField::MemberCount()
{
    return 1;
}

QSharedPointer<Protobetter::FieldCollection> Protobetter::FieldCollection::CreateNewRootType(QString typeName)
{
    return QSharedPointer<Protobetter::FieldCollection>(new Protobetter::FieldCollection(typeName, true));
}

QSharedPointer<Protobetter::FieldCollection> Protobetter::FieldCollection::CreateFieldFromRootType(QString fieldName, QSharedPointer<Protobetter::FieldCollection> root, bool finalize)
{
    if (!(root->IsRoot()))
    {
        throw std::invalid_argument("Protobetter::FieldCollection::CreateFieldFromRootType() called w/ non-root type!");
    }

    Protobetter::FieldCollection *newField = new Protobetter::FieldCollection(fieldName, 0);

    for (int i = 0; i < root->MemberCount(); ++i)
    {
        newField->AddField(root->GetField(i));
    }

    if (finalize)
    {
        newField->Finalize();
    }

    return QSharedPointer<Protobetter::FieldCollection>(newField);
}

void Protobetter::FieldCollection::AddField(QSharedPointer<Protobetter::DynamicType> field)
{
    if (field->IsRoot())
    {
        throw std::invalid_argument("Protobetter::FieldCollection::AddField() called with a root-type!");
    }
    else if (!field->IsComplete())
    {
        throw std::runtime_error("Protobetter::FieldCollection::AddField() can not be called with an incomplete type!");
    }
    else if (this->IsComplete())
    {
        throw std::runtime_error("Protobetter::FieldCollection can not be modified once it has been finalized!");
    }
    else if (this->memberAccessors->contains(field->Name()))
    {
        QString msg = QString("Protobetter::FieldCollection already has a member named") + field->Name();
        throw std::invalid_argument(msg.toStdString().c_str());
    }

    this->fields.append(field);
}

QSharedPointer<Protobetter::DynamicType> Protobetter::FieldCollection::GetField(int fieldIndex)
{
    if (fieldIndex < 0 || fieldIndex > this->fields.size() - 1)
    {
        throw std::invalid_argument("Protobetter::FieldCollection::GetField() called with out-of-range fieldIndex!");
    }

    return this->fields.value(fieldIndex);
}

Protobetter::DynamicObject::DynamicObject(QSharedPointer<Protobetter::DynamicType> type)
    : memberAccessors(type->GetMemberAccessors()), typeName(type->Name()), ownsData(true)
{
    if (!type->IsComplete())
    {
        throw std::runtime_error("Protobetter::DynamicObject can not be instantiated from an incomplete type!");
    }

    std::size_t size = type->Size();

    this->data = new char[size];
    memset(this->data, 0, size);
    this->size = size;
}

Protobetter::DynamicObject::DynamicObject(QSharedPointer<Protobetter::DynamicType> type, char *data)
    : memberAccessors(type->GetMemberAccessors()), typeName(type->Name()), size(size), data(data), ownsData(false)
{
}

Protobetter::DynamicObject::DynamicObject(const DynamicObject &other)
{
    this->memberAccessors = other.memberAccessors;
    this->size = size;
    this->ownsData = false;
    this->data = other.data;
    this->typeName = other.typeName;
}

Protobetter::DynamicObject& Protobetter::DynamicObject::operator=(const DynamicObject &other)
{
    if (this != &other)
    {
        this->memberAccessors = other.memberAccessors;
        this->typeName = other.typeName;
        this->size = size;
        this->ownsData = false;
        this->data = other.data;
    }

    return *this;
}

Protobetter::DynamicObject::~DynamicObject()
{
    if (data != NULL && this->ownsData)
    {
        delete[] data;
    }

    data = NULL;
}

uint8_t Protobetter::DynamicObject::GetUInt8(QString memberName)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    Protobetter::FieldAccessor accessor = this->memberAccessors->value(memberName);

    char *start = this->data + accessor.byteOffset;

    uint8_t value = 0;

    memcpy(&value, start, 1);

    return value;
}

int8_t Protobetter::DynamicObject::GetInt8(QString memberName)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    Protobetter::FieldAccessor accessor = this->memberAccessors->value(memberName);

    char *start = this->data + accessor.byteOffset;

    int8_t value = 0;

    memcpy(&value, start, 1);

    return value;
}

uint16_t Protobetter::DynamicObject::GetUInt16(QString memberName)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    return qFromBigEndian<quint16>(this->data + this->memberAccessors->value(memberName).byteOffset);
}

int16_t Protobetter::DynamicObject::GetInt16(QString memberName)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    return qFromBigEndian<qint16>(this->data + this->memberAccessors->value(memberName).byteOffset);
}

uint32_t Protobetter::DynamicObject::GetUInt32(QString memberName)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    return qFromBigEndian<quint32>(this->data + this->memberAccessors->value(memberName).byteOffset);
}

int32_t Protobetter::DynamicObject::GetInt32(QString memberName)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    return qFromBigEndian<qint32>(this->data + this->memberAccessors->value(memberName).byteOffset);
}

uint64_t Protobetter::DynamicObject::GetUInt64(QString memberName)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    return qFromBigEndian<quint64>(this->data + this->memberAccessors->value(memberName).byteOffset);
}

int64_t Protobetter::DynamicObject::GetInt64(QString memberName)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    return qFromBigEndian<qint64>(this->data + this->memberAccessors->value(memberName).byteOffset);
}

float Protobetter::DynamicObject::GetFloat(QString memberName)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    Protobetter::FieldAccessor accessor = this->memberAccessors->value(memberName);

    char *start = this->data + accessor.byteOffset;

    qint32 swappedData = qFromBigEndian<qint32>(start);

    float value = 0.0f;

    memcpy(&value, &swappedData, 4);

    return value;
}

double Protobetter::DynamicObject::GetDouble(QString memberName)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    Protobetter::FieldAccessor accessor = this->memberAccessors->value(memberName);

    char *start = this->data + accessor.byteOffset;

    qint64 swappedData = qFromBigEndian<qint64>(start);

    double value = 0.0f;

    memcpy(&value, &swappedData, 8);

    return value;
}

void Protobetter::DynamicObject::SetUInt8(QString memberName, uint8_t value)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    Protobetter::FieldAccessor accessor = this->memberAccessors->value(memberName);

    char *start = this->data + accessor.byteOffset;

    memcpy(start, &value, 1);
}

void Protobetter::DynamicObject::SetInt8(QString memberName, int8_t value)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    Protobetter::FieldAccessor accessor = this->memberAccessors->value(memberName);

    char *start = this->data + accessor.byteOffset;

    memcpy(start, &value, 1);
}

void Protobetter::DynamicObject::SetUInt16(QString memberName, uint16_t value)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    uint16_t swappedValue = 0;

    qToBigEndian<quint16>(value, &swappedValue);

    Protobetter::FieldAccessor accessor = this->memberAccessors->value(memberName);

    char *start = this->data + accessor.byteOffset;

    memcpy(start, &swappedValue, 2);
}

void Protobetter::DynamicObject::SetInt16(QString memberName, int16_t value)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    int16_t swappedValue = 0;

    qToBigEndian<qint16>(value, &swappedValue);

    Protobetter::FieldAccessor accessor = this->memberAccessors->value(memberName);

    char *start = this->data + accessor.byteOffset;

    memcpy(start, &swappedValue, 2);
}

void Protobetter::DynamicObject::SetUInt32(QString memberName, uint32_t value)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    uint32_t swappedValue = 0;

    qToBigEndian<quint32>(value, &swappedValue);

    Protobetter::FieldAccessor accessor = this->memberAccessors->value(memberName);

    char *start = this->data + accessor.byteOffset;

    memcpy(start, &swappedValue, 4);
}

void Protobetter::DynamicObject::SetInt32(QString memberName, int32_t value)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    int32_t swappedValue = 0;

    qToBigEndian<qint32>(value, &swappedValue);

    Protobetter::FieldAccessor accessor = this->memberAccessors->value(memberName);

    char *start = this->data + accessor.byteOffset;

    memcpy(start, &swappedValue, 4);
}

void Protobetter::DynamicObject::SetUInt64(QString memberName, uint64_t value)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    uint64_t swappedValue = 0;

    qToBigEndian<quint64>(value, &swappedValue);

    Protobetter::FieldAccessor accessor = this->memberAccessors->value(memberName);

    char *start = this->data + accessor.byteOffset;

    memcpy(start, &swappedValue, 8);
}

void Protobetter::DynamicObject::SetInt64(QString memberName, int64_t value)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    int64_t swappedValue = 0;

    qToBigEndian<qint64>(value, &swappedValue);

    Protobetter::FieldAccessor accessor = this->memberAccessors->value(memberName);

    char *start = this->data + accessor.byteOffset;

    memcpy(start, &swappedValue, 8);
}

void Protobetter::DynamicObject::SetFloat(QString memberName, float value)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    uint32_t packedValue = 0;

    uint32_t unpackedValue = 0;
    memcpy(&unpackedValue, &value, 4);

    qToBigEndian<qint32>(unpackedValue, &packedValue);

    Protobetter::FieldAccessor accessor = this->memberAccessors->value(memberName);

    char *start = this->data + accessor.byteOffset;

    memcpy(start, &packedValue, 4);
}

void Protobetter::DynamicObject::SetDouble(QString memberName, double value)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    uint64_t packedValue = 0;

    uint64_t unpackedValue = 0;
    memcpy(&unpackedValue, &value, 8);

    qToBigEndian<qint64>(unpackedValue, &packedValue);

    Protobetter::FieldAccessor accessor = this->memberAccessors->value(memberName);

    char *start = this->data + accessor.byteOffset;

    memcpy(start, &packedValue, 8);
}

const char * Protobetter::DynamicObject::GetByteArray(QString memberName)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    Protobetter::FieldAccessor accessor = this->memberAccessors->value(memberName);

    return (this->data + accessor.byteOffset);
}

void Protobetter::DynamicObject::SetByteArray(QString memberName, const char *value)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    Protobetter::FieldAccessor accessor = this->memberAccessors->value(memberName);

    memcpy(this->data + accessor.byteOffset, value, accessor.size);
}

uint64_t Protobetter::DynamicObject::GetUnsignedBitfield(QString memberName)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    Protobetter::FieldAccessor accessor = this->memberAccessors->value(memberName);

    char *fieldStart = this->data + accessor.byteOffset;

    if (accessor.size == 1)
    {
        uint8_t value;

        memcpy(&value, fieldStart, 1);

        return (value & ~accessor.packingMask) >> accessor.bitOffset;
    }
    else if (accessor.size == 2)
    {
        uint16_t value = qFromBigEndian<quint16>(fieldStart);

        return (value & ~accessor.packingMask) >> accessor.bitOffset;
    }
    else if (accessor.size == 4)
    {
        uint32_t value = qFromBigEndian<quint32>(fieldStart);

        return (value & ~accessor.packingMask) >> accessor.bitOffset;
    }
    else if (accessor.size == 8)
    {
        uint64_t value = qFromBigEndian<quint64>(fieldStart);

        return (value & ~accessor.packingMask) >> accessor.bitOffset;
    }

    return -1;
}

int64_t Protobetter::DynamicObject::GetSignedBitfield(QString memberName)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    Protobetter::FieldAccessor accessor = this->memberAccessors->value(memberName);

    char *fieldStart = this->data + accessor.byteOffset;

    if (accessor.size == 1)
    {
        uint8_t value;

        memcpy(&value, fieldStart, 1);

        return (value & ~accessor.packingMask) >> accessor.bitOffset;
    }
    else if (accessor.size == 2)
    {
        uint16_t value = qFromBigEndian<quint16>(fieldStart);

        value = (value & ~accessor.packingMask) >> accessor.bitOffset;

        return GetTwosComplementSignedEquivalent(value, accessor.bitfieldSize);
    }
    else if (accessor.size == 4)
    {
        uint32_t value = qFromBigEndian<quint32>(fieldStart);

        value = (value & ~accessor.packingMask) >> accessor.bitOffset;

        return GetTwosComplementSignedEquivalent(value, accessor.bitfieldSize);
    }
    else if (accessor.size == 8)
    {
        uint64_t value = qFromBigEndian<quint64>(fieldStart);

        value = (value & ~accessor.packingMask) >> accessor.bitOffset;

        return GetTwosComplementSignedEquivalent(value, accessor.bitfieldSize);
    }

    return -1;
}

void Protobetter::DynamicObject::SetSignedBitfield(QString memberName, int64_t value)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    Protobetter::FieldAccessor accessor = this->memberAccessors->value(memberName);

    char *fieldStart = this->data + accessor.byteOffset;

    uint64_t unsignedContainer = GetTwosComplementUnsignedEquivalent(value, accessor.bitfieldSize);

    if (accessor.size == 1)
    {
        int8_t buffer;

        memcpy(&buffer, fieldStart, 1);

        buffer = (buffer & accessor.packingMask) | (unsignedContainer << accessor.bitOffset);

        memcpy(fieldStart, &buffer, 1);
    }
    else if (accessor.size == 2)
    {
        int16_t buffer = qFromBigEndian<qint16>(fieldStart);

        buffer = (buffer & accessor.packingMask) | (unsignedContainer << accessor.bitOffset);

        qToBigEndian<qint16>(buffer, fieldStart);
    }
    else if (accessor.size == 4)
    {
        int32_t buffer = qFromBigEndian<qint32>(fieldStart);

        buffer = (buffer & accessor.packingMask) | (unsignedContainer << accessor.bitOffset);

        qToBigEndian<qint32>(buffer, fieldStart);
    }
    else if (accessor.size == 8)
    {
        int64_t buffer = qFromBigEndian<qint64>(fieldStart);

        buffer = (buffer & accessor.packingMask) | (unsignedContainer << accessor.bitOffset);

        qToBigEndian<qint64>(buffer, fieldStart);
    }
}

void Protobetter::DynamicObject::SetUnsignedBitfield(QString memberName, uint64_t value)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    Protobetter::FieldAccessor accessor = this->memberAccessors->value(memberName);

    char *fieldStart = this->data + accessor.byteOffset;

    if (accessor.size == 1)
    {
        uint8_t buffer;

        memcpy(&buffer, fieldStart, 1);

        buffer = (buffer & accessor.packingMask) | (value << accessor.bitOffset);

        memcpy(fieldStart, &buffer, 1);
    }
    else if (accessor.size == 2)
    {
        uint16_t buffer;

        buffer = qFromBigEndian<quint16>(fieldStart);

        buffer = (buffer & accessor.packingMask) | (value << accessor.bitOffset);

        qToBigEndian<quint16>(buffer, fieldStart);
    }
    else if (accessor.size == 4)
    {
        uint32_t buffer;

        buffer = qFromBigEndian<quint32>(fieldStart);

        buffer = (buffer & accessor.packingMask) | (value << accessor.bitOffset);

        qToBigEndian<quint32>(buffer, fieldStart);
    }
    else if (accessor.size == 8)
    {
        uint64_t buffer;

        buffer = qFromBigEndian<quint64>(fieldStart);

        buffer = (buffer & accessor.packingMask) | (value << accessor.bitOffset);

        qToBigEndian<quint64>(buffer, fieldStart);
    }
}

Protobetter::DynamicObject Protobetter::DynamicObject::GetObject(QSharedPointer<DynamicType> type, QString memberName)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }
    else if ((!type->IsComplete()) || (!type->IsRoot()))
    {
        throw std::invalid_argument("Protobetter::DynamicObject::GetObject() must only be called on a complete root type!");
    }

#endif

    Protobetter::FieldAccessor accessor = this->memberAccessors->value(memberName);

    char *fieldStart = this->data + accessor.byteOffset;

    return Protobetter::DynamicObject(type, fieldStart);
}

void Protobetter::DynamicObject::SetObject(QString memberName, QSharedPointer<DynamicType> type, const DynamicObject &object)
{
#ifndef QT_NO_DEBUG

    if (!this->memberAccessors->contains(memberName))
    {
        QString errMsg = QString("No member named ") + memberName;
        throw std::invalid_argument(errMsg.toStdString().c_str());
    }

#endif

    Protobetter::FieldAccessor accessor = this->memberAccessors->value(memberName);

    char *fieldStart = this->data + accessor.byteOffset;

    memcpy(fieldStart, object.Data(), accessor.size);
}

const char * Protobetter::DynamicObject::Data() const
{
    return this->data;
}

void Protobetter::DynamicObject::SetData(const char *data)
{
    memcpy(this->data, data, this->size);
}

std::size_t Protobetter::DynamicObject::Size()
{
    return this->size;
}

std::size_t Protobetter::PrototypeCollection::Size() const
{
    return this->rootTypes.size();
}

void Protobetter::PrototypeCollection::LoadPrototypesFromFile(QString filePath)
{
    QFile f(filePath);

    if (!f.open(QFile::ReadOnly | QFile::Text))
    {
        qInfo("Unable to open ptype file: %s", filePath.toStdString().c_str());
        return;
    }

    QTextStream in(&f);
    QByteArray jsonData(in.readAll().toUtf8());

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);

    if (jsonDoc.isNull())
    {
        qInfo( "Unable to parse json document: %s", filePath.toStdString().c_str());
    }
    else if (jsonDoc.isArray())
    {
        // we're expecting an array of json objects
        for (int i = 0; i < jsonDoc.array().count(); ++i)
        {
            QJsonObject object = jsonDoc.array().at(i).toObject();

            Prototype prototype = BuildPrototypeFromJsonObject(object);

            this->rootTypes.append(prototype);
        }
    }
    else if (jsonDoc.isObject())
    {
        // we're expecting a single json object
        QJsonObject object = jsonDoc.object();

        Prototype prototype = BuildPrototypeFromJsonObject(object);

        this->rootTypes.append(prototype);
    }

    f.close();
}

QJsonObject Protobetter::Prototype::ToJsonObject()
{
    QJsonObject object;

    object.insert("name", this->name);

    QJsonArray membersArray;

    for (int i = 0; i < this->members.count(); ++i)
    {
        QJsonObject member;

        member.insert("name", this->members[i].name);
        member.insert("type", this->members[i].type);

        if (this->members[i].arrayLength != 0)
        {
            member.insert("arraylen", this->members[i].arrayLength);
        }

        if (this->members[i].bits != 0)
        {
            member.insert("bits", this->members[i].bits);
        }

        membersArray.append(member);
    }

    object.insert("members", membersArray);

    return object;
}
