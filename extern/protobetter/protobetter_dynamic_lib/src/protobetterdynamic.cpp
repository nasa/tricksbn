#include <bitset>
#include <cstring>
#include <algorithm>

#include <byteswap.h>

#include <fstream>
#include <sstream>
#include <iostream>

#include <libxml/parser.h>
#include <libxml/tree.h>

#include <stdexcept>

#include "protobetterdynamic.h"

namespace
{
    Protobetter::Prototype BuildPrototypeFromJsonObject(Json::Value &object)
    {
        std::string typeName = object["typeName"].asString();
        
        Protobetter::Prototype prototype(typeName);

        Json::Value members = object["members"];
        for (Json::Value::iterator it = members.begin(); it != members.end(); ++it)
        {
            Json::Value member = *it;

            Protobetter::PrototypeMember ptypeMember;
            ptypeMember.name = member["name"].asString();
            ptypeMember.type = member["type"].asString();

            if (member.isMember("name"))
            {
                ptypeMember.arrayLength = member["arraylen"].asInt();
            }

            if (member.isMember("bits"))
            {
                ptypeMember.bits = member["bits"].asInt();
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

            std::bitset<64> bits(magnitude);

            for (std::size_t i = 0; i < bitfieldWidth; ++i)
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
            for (std::size_t i = 0; i < bitfieldWidth; ++i)
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
    : byteOffset(0), size(0), bitOffset(0), packingMask(0), type(ProtobetterFieldType::Object)
{
}

Protobetter::FieldAccessor::FieldAccessor(ProtobetterFieldType type, std::size_t size)
    : byteOffset(0), size(size), bitOffset(0), packingMask(0), type(type)
{
}

Protobetter::DynamicType::DynamicType(const std::string& name, bool isRoot)
    : isRoot(isRoot), name(name)
{
}

bool Protobetter::PrototypeCollection::HasType(const std::string& typeName) const
{
    for (unsigned int i = 0; i < this->rootTypes.size(); ++i)
    {
        if (this->rootTypes[i].name == typeName)
            return true;
    }

    return false;
}

bool Protobetter::Prototype::HasMember(const std::string& memberName)
{
    for (unsigned int i = 0; i < this->members.size(); ++i)
    {
        if (this->members[i].name == memberName)
        {
            return true;
        }
    }

    return false;
}

Protobetter::PrototypeMember Protobetter::Prototype::GetMember(const std::string& memberName)
{
    for (unsigned int i = 0; i < this->members.size(); ++i)
    {
        if (this->members[i].name == memberName)
        {
            return this->members[i];
        }
    }

    std::string msg = std::string("Prototype::GetMember() ERROR: prototype has no member named ") + memberName;

    throw std::runtime_error(msg.c_str());
}

Protobetter::Prototype Protobetter::PrototypeCollection::GetType(const std::string& typeName) const
{
    for (unsigned int i = 0; i < this->rootTypes.size(); ++i)
    {
        if (this->rootTypes[i].name == typeName)
        {
            return this->rootTypes[i];
        }
    }

    std::string msg = std::string("PrototypeCollection::GetType() ERROR: collection has no type named ") + typeName;
    throw std::runtime_error(msg.c_str());
}

void Protobetter::PrototypeCollection::AddPrototype(const Prototype &prototype)
{
    this->rootTypes.push_back(prototype);
}

bool Protobetter::DynamicTypeCollection::HasType(const std::string& typeName)
{
    for (unsigned int i = 0; i < this->rootTypes.size(); ++i)
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

Protobetter::DynamicType::Ptr Protobetter::DynamicTypeCollection::GetType(const std::string& typeName)
{
    for (unsigned int i = 0; i < this->rootTypes.size(); ++i)
    {
        if (this->rootTypes[i]->Name() == typeName)
        {
            return this->rootTypes[i];
        }
    }

    std::string msg = std::string("DynamicTypeCollection::GetType() ERROR: collection has no type named ") + typeName;
    throw std::runtime_error(msg.c_str());
}

void Protobetter::DynamicTypeCollection::AddDynamicType(const DynamicType::Ptr ptr)
{
    this->rootTypes.push_back(ptr);
}

void Protobetter::DynamicTypeCollection::CreateDynamicTypeFromPrototypeRecursive(const PrototypeCollection &prototypes, DynamicTypeCollection &dynamicTypes, const Protobetter::Prototype &ptype)
{
    if (dynamicTypes.HasType(ptype.name))
    {
        return;
    }

    auto newDynamicType = Protobetter::FieldCollection::CreateNewRootType(ptype.name);

    Protobetter::BitfieldCollection::Ptr currentBitfieldCollection = nullptr;

    for (unsigned int i = 0; i < ptype.members.size(); ++i)
    {
        std::size_t memberSize = 0;
        bool isPrimitiveType = true;

        ProtobetterFieldType type = ProtobetterFieldType::Object;

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
                    std::string msg = std::string("Protobetter::FieldCollection::CreateDynamicTypeFromPrototypeRecursive() ERROR: No prototype definition found for root type ") + ptype.members[i].type;
                    throw std::runtime_error(msg.c_str());
                }
            }

            memberSize = dynamicTypes.GetType(ptype.members[i].type)->Size();
        }

        if (ptype.members[i].bits > 0) // it's a bitfield...
        {
            if (!currentBitfieldCollection)
            {
                currentBitfieldCollection = Protobetter::BitfieldCollection::CreateNewBitfieldCollection(memberSize);
            }
            else if (currentBitfieldCollection->Size() != memberSize || (int)currentBitfieldCollection->BitsAvailable() < ptype.members[i].bits)
            {
                currentBitfieldCollection->Finalize();
                newDynamicType->AddField(currentBitfieldCollection);
                currentBitfieldCollection = nullptr;

                currentBitfieldCollection = Protobetter::BitfieldCollection::CreateNewBitfieldCollection(memberSize);
            }

            bool isSigned = ptype.members[i].type.rfind("i", 0) == 0;

            currentBitfieldCollection->AddField(ptype.members[i].name, ptype.members[i].bits, isSigned);
            if (i == ptype.members.size() - 1)
            {
                currentBitfieldCollection->Finalize();
                newDynamicType->AddField(currentBitfieldCollection);
            }
        }
        else if (ptype.members[i].arrayLength > 0 && ptype.members[i].type != "bytearray") // it's an array
        {
            if (currentBitfieldCollection)
            {
                currentBitfieldCollection->Finalize();
                newDynamicType->AddField(currentBitfieldCollection);
                currentBitfieldCollection = nullptr;
            }

            for (int j = 0; j < ptype.members[i].arrayLength; ++j)
            {
                
                std::stringstream ss;
                ss << ptype.members[i].name << "[" << j << "]";
                std::string memberName = ss.str(); 

                if (isPrimitiveType)
                {
                    newDynamicType->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField(memberName, type, memberSize));
                }
                else
                {
                    auto rootType = std::static_pointer_cast<Protobetter::FieldCollection>(dynamicTypes.GetType(ptype.members[i].type));
                    newDynamicType->AddField(Protobetter::FieldCollection::CreateFieldFromRootType(memberName, rootType, true));
                }
            }
        }
        else // it's just a normal field
        {
            if (currentBitfieldCollection)
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
                auto rootType = std::static_pointer_cast<Protobetter::FieldCollection>(dynamicTypes.GetType(ptype.members[i].type));
                newDynamicType->AddField(Protobetter::FieldCollection::CreateFieldFromRootType(ptype.members[i].name, rootType, true));
            }
        }
    }

    newDynamicType->Finalize();

    dynamicTypes.AddDynamicType(newDynamicType);
}

std::vector<std::string> Protobetter::DynamicTypeCollection::GetRootTypeNames()
{
    std::vector<std::string> names;

    for (unsigned int i = 0; i < rootTypes.size(); ++i)
    {
        names.push_back(rootTypes[i]->Name());
    }

    return names;
}

Protobetter::DynamicTypeCollection Protobetter::DynamicTypeCollection::FromPrototypeCollection(const Protobetter::PrototypeCollection &prototypes)
{
    Protobetter::DynamicTypeCollection dynamicTypes;

    // recursively build up your DynamicTypeCollection
    for (std::size_t i = 0; i < prototypes.Size(); ++i)
    {
        Protobetter::DynamicTypeCollection::CreateDynamicTypeFromPrototypeRecursive(prototypes, dynamicTypes, prototypes.GetType(i));
    }

    return dynamicTypes;
}

std::string Protobetter::DynamicType::Name()
{
    return this->name;
}

bool Protobetter::DynamicType::IsRoot()
{
    return this->isRoot;
}

Protobetter::FieldCollection::FieldCollection(const std::string& name, bool isRoot)
    : DynamicType(name, isRoot), isComplete(false), memberAccessors(new std::map<std::string, Protobetter::FieldAccessor>())
{
}

bool Protobetter::FieldCollection::IsComplete()
{
    return this->isComplete;
}

std::shared_ptr<std::map<std::string, Protobetter::FieldAccessor> > Protobetter::FieldCollection::GetMemberMap()
{
    return this->memberAccessors;
}

Protobetter::ProtobetterFieldType Protobetter::FieldCollection::GetFieldType(const std::string& name)
{
    if (!this->isComplete)
    {
        throw std::runtime_error("Protobetter::FieldCollection::GetFieldType ERROR: can't access field type info until type is complete!");
    }

    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(name);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + name;
        throw std::invalid_argument(errMsg.c_str());
    }

    return this->memberAccessors->at(name).type;
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

            this->memberAccessors->insert(std::pair<std::string, FieldAccessor>(this->name, accessor));
        }

        for (unsigned int i = 0; i < this->fields.size(); ++i)
        {
            auto currentMemberAccessors = this->fields[i]->GetMemberMap();

            for (auto iter = currentMemberAccessors->begin();
                 iter != currentMemberAccessors->end();
                 iter++)
            {
                std::string fieldPath;

                if (this->isRoot)
                {
                    fieldPath = iter->first;
                }
                else
                {
                    std::stringstream ss;
                    ss << this->name << "." << iter->first;
                    fieldPath = ss.str();
                }

                Protobetter::FieldAccessor accessor = iter->second;

                accessor.byteOffset += currentOffset;

                this->memberAccessors->insert(std::pair<std::string, FieldAccessor>(fieldPath, accessor));
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

    for (unsigned int i = 0; i < this->fields.size(); ++i)
    {
        size += this->fields[i]->Size();
    }

    return size;
}

Protobetter::BitfieldCollection::Bitfield::Bitfield()
    : name(""), bitOffset(0), length(0), isSigned(true)
{
}

Protobetter::BitfieldCollection::Bitfield::Bitfield(const std::string& name, std::size_t bitOffset, std::size_t length, bool isSigned)
    : name(name), bitOffset(bitOffset), length(length), isSigned(isSigned)
{
}

Protobetter::BitfieldCollection::BitfieldCollection(std::size_t size)
    : DynamicType("", false), size(size), isComplete(false), memberAccessors(new std::map<std::string, FieldAccessor>())
{
}

bool Protobetter::BitfieldCollection::IsComplete()
{
    return this->isComplete;
}

std::shared_ptr<std::map<std::string, Protobetter::FieldAccessor> > Protobetter::BitfieldCollection::GetMemberMap()
{
    return this->memberAccessors;
}

void Protobetter::BitfieldCollection::Finalize()
{
    if (!this->isComplete)
    {
        for (unsigned int i = 0; i < this->bitfields.size(); ++i)
        {
            ProtobetterFieldType type = this->bitfields[i].isSigned ? ProtobetterFieldType::SignedBitfield : ProtobetterFieldType::UnsignedBitfield;

            Protobetter::FieldAccessor accessor(type, this->size);
            accessor.bitOffset = this->bitfields[i].bitOffset;
            accessor.byteOffset = 0; // always a '0' byte offset within this field
            accessor.bitfieldSize = this->bitfields[i].length;

            accessor.packingMask = CalculatePackingMask(this->bitfields[i].bitOffset, this->bitfields[i].length);

            this->memberAccessors->insert(std::pair<std::string, FieldAccessor>(this->bitfields[i].name, accessor));
        }

        this->isComplete = true;
    }
}

Protobetter::ProtobetterFieldType Protobetter::BitfieldCollection::GetFieldType(const std::string&)
{
    if (!this->isComplete)
    {
        throw std::runtime_error("Protobetter::BitfieldCollection::GetFieldType ERROR: can't access field type info until type is complete!");
    }

    // TODO: some validation for debug builds and return the right sign...
    return Protobetter::SignedBitfield;
}

std::shared_ptr<Protobetter::BitfieldCollection> Protobetter::BitfieldCollection::CreateNewBitfieldCollection(std::size_t size)
{
    if (!(size == 1 || size == 2 || size == 4 || size == 8))
    {
        throw std::invalid_argument("Protobetter::BitfieldCollection can only be created with a size of 1, 2, 4, or 8 bytes!");
    }

    return std::shared_ptr<Protobetter::BitfieldCollection>(new Protobetter::BitfieldCollection(size));
}

std::size_t Protobetter::BitfieldCollection::BitsUsed()
{
    std::size_t bitsUsed = 0;

    for (unsigned int i = 0; i < this->bitfields.size(); ++i)
    {
        bitsUsed += this->bitfields.at(i).length;
    }

    return bitsUsed;
}

std::size_t Protobetter::BitfieldCollection::BitsAvailable()
{
    return (this->Size() * 8) - this->BitsUsed();
}

void Protobetter::BitfieldCollection::AddField(const std::string& name, std::size_t width, bool isSigned)
{
    if (this->BitsAvailable() < width)
    {
        throw std::invalid_argument(std::string("Protobetter::BitfieldCollection doesn't have space for field: ") + name);
    }
    else if (this->isComplete)
    {
        throw std::runtime_error("Protobetter::BitfieldCollection::AddField() can not be called once it has been finalized!");
    }

    for (unsigned int i = 0; i < this->bitfields.size(); ++i)
    {
        if (this->bitfields[i].name == name)
        {
            throw std::invalid_argument("Protobetter::BitfieldCollection::AddField() ERROR: can not add two bitfields with same name to a collection");
        }
    }

    this->bitfields.push_back(Bitfield(name, this->BitsUsed(), width, isSigned));
}

std::size_t Protobetter::BitfieldCollection::Size()
{
    return this->size;
}

std::size_t Protobetter::BitfieldCollection::MemberCount()
{
    return this->bitfields.size();
}

Protobetter::Prototype::Prototype(const std::string& name)
    : name(name)
{

}

Protobetter::Prototype::Prototype()
{
}

std::shared_ptr<Protobetter::PrimitiveField> Protobetter::PrimitiveField::CreateNewPrimitiveField(const std::string& name, ProtobetterFieldType type, std::size_t size)
{
    if (size == 0)
    {
        throw std::invalid_argument("Cannot create a Protobetter::PrimitiveField w/ size = 0!");
    }

    return std::shared_ptr<Protobetter::PrimitiveField>(new Protobetter::PrimitiveField(name, type, size));
}

Protobetter::ProtobetterFieldType Protobetter::PrimitiveField::GetFieldType(const std::string&)
{
    return this->type;
}

Protobetter::PrimitiveField::PrimitiveField(const std::string& name, ProtobetterFieldType type, std::size_t size)
    : DynamicType(name, false), type(type), size(size), memberAccessors(new std::map<std::string, Protobetter::FieldAccessor>())
{
    this->memberAccessors->insert(std::pair<std::string, FieldAccessor>(this->name, Protobetter::FieldAccessor(type, this->size)));
}

std::size_t Protobetter::PrimitiveField::Size()
{
    return this->size;
}

bool Protobetter::PrimitiveField::IsComplete()
{
    return true; // a primitive field is always a complete type
}

std::shared_ptr<std::map<std::string, Protobetter::FieldAccessor> > Protobetter::PrimitiveField::GetMemberMap()
{
    return this->memberAccessors;
}

std::size_t Protobetter::PrimitiveField::MemberCount()
{
    return 1;
}

std::shared_ptr<Protobetter::FieldCollection> Protobetter::FieldCollection::CreateNewRootType(const std::string& typeName)
{
    return std::shared_ptr<Protobetter::FieldCollection>(new Protobetter::FieldCollection(typeName, true));
}

std::shared_ptr<Protobetter::FieldCollection> Protobetter::FieldCollection::CreateFieldFromRootType(const std::string& fieldName, std::shared_ptr<Protobetter::FieldCollection> root, bool finalize)
{
    if (!(root->IsRoot()))
    {
        throw std::invalid_argument("Protobetter::FieldCollection::CreateFieldFromRootType() called w/ non-root type!");
    }

    Protobetter::FieldCollection *newField = new Protobetter::FieldCollection(fieldName, 0);

    for (std::size_t i = 0; i < root->MemberCount(); ++i)
    {
        newField->AddField(root->GetField(i));
    }

    if (finalize)
    {
        newField->Finalize();
    }

    return std::shared_ptr<Protobetter::FieldCollection>(newField);
}

void Protobetter::FieldCollection::AddField(std::shared_ptr<Protobetter::DynamicType> field)
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
    else
    {
        std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->begin();
        bool found = false;
        while (it != this->memberAccessors->end())
        {
            if (it->first == field->Name())
            {
                found = true;
            }
        }
        if (found)
        {
            std::string msg = std::string("Protobetter::FieldCollection already has a member named") + field->Name();
            throw std::invalid_argument(msg.c_str());
        }
    }

    this->fields.push_back(field);
}

std::shared_ptr<Protobetter::DynamicType> Protobetter::FieldCollection::GetField(int fieldIndex)
{
    if (fieldIndex < 0 || fieldIndex > static_cast<int>(this->fields.size()) - 1)
    {
        throw std::invalid_argument("Protobetter::FieldCollection::GetField() called with out-of-range fieldIndex!");
    }

    return this->fields.at(fieldIndex);
}

Protobetter::DynamicObject::DynamicObject(std::shared_ptr<Protobetter::DynamicType> type)
    : isLittleEndian(false), ownsData(true), typeName(type->Name()), memberAccessors(type->GetMemberMap())
{
    if (!type->IsComplete())
    {
        throw std::runtime_error("Protobetter::DynamicObject can not be instantiated from an incomplete type!");
    }

    // Check endianness
    short int number = 0x1;
    char *numPtr = (char*)&number;
    if (numPtr[0] == 1)
    {
        this->isLittleEndian = true;
    }

    std::size_t size = type->Size();

    this->data = new char[size];
    memset(this->data, 0, size);
    this->size = size;
}

Protobetter::DynamicObject::DynamicObject(std::shared_ptr<Protobetter::DynamicType> type, char *_data)
    : isLittleEndian(false), ownsData(false), data(_data), size(type->Size()), typeName(type->Name()), memberAccessors(type->GetMemberMap())
{
    short int number = 0x1;
    char *numPtr = (char*)&number;
    if (numPtr[0] == 1)
    {
        this->isLittleEndian = true;
    }
}

Protobetter::DynamicObject::DynamicObject(const DynamicObject &other)
{
    this->memberAccessors = other.memberAccessors;
    this->size = size;
    this->isLittleEndian = other.isLittleEndian;
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
        this->isLittleEndian = other.isLittleEndian;
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

uint8_t Protobetter::DynamicObject::GetUInt8(const Protobetter::FieldAccessor &accessor)
{
    char *start = this->data + accessor.byteOffset;

    uint8_t value = 0;

    memcpy(&value, start, 1);

    return value;
}

uint8_t Protobetter::DynamicObject::GetUInt8(const std::string& memberName)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    Protobetter::FieldAccessor accessor = this->memberAccessors->at(memberName);

    return this->GetUInt8(accessor);
}

int8_t Protobetter::DynamicObject::GetInt8(const Protobetter::FieldAccessor &accessor)
{
    char *start = this->data + accessor.byteOffset;

    int8_t value = 0;

    memcpy(&value, start, 1);

    return value;
}

int8_t Protobetter::DynamicObject::GetInt8(const std::string& memberName)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    Protobetter::FieldAccessor accessor = this->memberAccessors->at(memberName);

    return this->GetInt8(accessor);
}

uint16_t Protobetter::DynamicObject::GetUInt16(const Protobetter::FieldAccessor &accessor)
{
    uint16_t value;
    memcpy(&value, this->data + accessor.byteOffset, 2);
    
    if (this->isLittleEndian)
    {
        value = bswap_16(value);        
    }

    return value;
}

uint16_t Protobetter::DynamicObject::GetUInt16(const std::string& memberName)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    return GetUInt16(this->memberAccessors->at(memberName));    
}

int16_t Protobetter::DynamicObject::GetInt16(const Protobetter::FieldAccessor &accessor)
{
    int16_t value;
    memcpy(&value, this->data + accessor.byteOffset, 2);

    if (this->isLittleEndian)
    {
        value = bswap_16(value);
    }

    return value;
}

int16_t Protobetter::DynamicObject::GetInt16(const std::string& memberName)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    return GetInt16(this->memberAccessors->at(memberName));
}

uint32_t Protobetter::DynamicObject::GetUInt32(const Protobetter::FieldAccessor &accessor)
{
    uint32_t value;
    memcpy(&value, this->data + accessor.byteOffset, 4);

    if (this->isLittleEndian)
    {
        value = bswap_32(value);
    }

    return value;
}

uint32_t Protobetter::DynamicObject::GetUInt32(const std::string& memberName)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    return GetUInt32(this->memberAccessors->at(memberName));
}

int32_t Protobetter::DynamicObject::GetInt32(const Protobetter::FieldAccessor &accessor)
{
    int32_t value;
    memcpy(&value, this->data + accessor.byteOffset, 4);

    if (this->isLittleEndian)
    {
        value = bswap_32(value);
    }

    return value;    
}

int32_t Protobetter::DynamicObject::GetInt32(const std::string& memberName)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    return GetInt32(this->memberAccessors->at(memberName));
}

uint64_t Protobetter::DynamicObject::GetUInt64(const Protobetter::FieldAccessor &accessor)
{
    uint64_t value;
    memcpy(&value, this->data + accessor.byteOffset, 8);

    if (this->isLittleEndian)
    {
        value = bswap_64(value);
    }
 
    return value;
}

uint64_t Protobetter::DynamicObject::GetUInt64(const std::string& memberName)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    return GetUInt64(this->memberAccessors->at(memberName));
}

int64_t Protobetter::DynamicObject::GetInt64(const Protobetter::FieldAccessor &accessor)
{
    int64_t value;
    memcpy(&value, this->data + accessor.byteOffset, 8);

    if (this->isLittleEndian)
    {
        value = bswap_64(value);
    }

    return value; 
}

int64_t Protobetter::DynamicObject::GetInt64(const std::string& memberName)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    return GetInt64(this->memberAccessors->at(memberName));
}

float Protobetter::DynamicObject::GetFloat(const Protobetter::FieldAccessor &accessor)
{
    int32_t value;
    memcpy(&value, this->data + accessor.byteOffset, 4);

    if (this->isLittleEndian)
    {
        value = bswap_32(value);
    }

    float fValue = 0.0f;
    memcpy(&fValue, &value, 4);

    return fValue;
}

float Protobetter::DynamicObject::GetFloat(const std::string& memberName)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    return GetFloat(this->memberAccessors->at(memberName));
}

double Protobetter::DynamicObject::GetDouble(const Protobetter::FieldAccessor &accessor)
{
    int64_t value;
    memcpy(&value, this->data + accessor.byteOffset, 8);

    if (this->isLittleEndian)
    {
        value = bswap_64(value);
    }

    double dValue = 0.0;
    memcpy(&dValue, &value, 8);

    return dValue;
}

double Protobetter::DynamicObject::GetDouble(const std::string& memberName)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    return GetDouble(this->memberAccessors->at(memberName));
}

void Protobetter::DynamicObject::SetUInt8(const Protobetter::FieldAccessor &accessor, uint8_t value)
{
    memcpy(this->data + accessor.byteOffset, &value, 1);
}

void Protobetter::DynamicObject::SetUInt8(const std::string& memberName, uint8_t value)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    Protobetter::FieldAccessor accessor = this->memberAccessors->at(memberName);

    this->SetUInt8(accessor, value);
}

void Protobetter::DynamicObject::SetInt8(const Protobetter::FieldAccessor &accessor, int8_t value)
{
    memcpy(this->data + accessor.byteOffset, &value, 1);
}

void Protobetter::DynamicObject::SetInt8(const std::string& memberName, int8_t value)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    Protobetter::FieldAccessor accessor = this->memberAccessors->at(memberName);

    this->SetInt8(accessor, value);
}

void Protobetter::DynamicObject::SetUInt16(const Protobetter::FieldAccessor &accessor, uint16_t value)
{
    uint16_t swappedValue = 0;

    if (this->isLittleEndian)
    {
        swappedValue = bswap_16(value);
    }

    memcpy(this->data + accessor.byteOffset, &swappedValue, 2);
}

void Protobetter::DynamicObject::SetUInt16(const std::string& memberName, uint16_t value)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    this->SetUInt16(this->memberAccessors->at(memberName), value);
}

void Protobetter::DynamicObject::SetInt16(const Protobetter::FieldAccessor &accessor, int16_t value)
{
    int16_t swappedValue = 0;

    if (this->isLittleEndian)
    {
        swappedValue = bswap_16(value);
    }

    memcpy(this->data + accessor.byteOffset, &swappedValue, 2);
}

void Protobetter::DynamicObject::SetInt16(const std::string& memberName, int16_t value)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    this->SetInt16(this->memberAccessors->at(memberName), value);
}

void Protobetter::DynamicObject::SetUInt32(const Protobetter::FieldAccessor &accessor, uint32_t value)
{
    uint32_t swappedValue = 0;

    if (this->isLittleEndian)
    {
        swappedValue = bswap_32(value);
    }

    memcpy(this->data + accessor.byteOffset, &swappedValue, 4);
}

void Protobetter::DynamicObject::SetUInt32(const std::string& memberName, uint32_t value)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    this->SetUInt32(this->memberAccessors->at(memberName), value);
}

void Protobetter::DynamicObject::SetInt32(const Protobetter::FieldAccessor &accessor, int32_t value)
{
    int32_t swappedValue = 0;

    if (this->isLittleEndian)
    {
        swappedValue = bswap_32(value);
    }

    memcpy(this->data + accessor.byteOffset, &swappedValue, 4);
}

void Protobetter::DynamicObject::SetInt32(const std::string& memberName, int32_t value)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    this->SetInt32(this->memberAccessors->at(memberName), value);
}

void Protobetter::DynamicObject::SetUInt64(const Protobetter::FieldAccessor &accessor, uint64_t value)
{
    uint64_t swappedValue = 0;

    if (this->isLittleEndian)
    {
        swappedValue = bswap_64(value);
    }

    memcpy(this->data + accessor.byteOffset, &swappedValue, 8);
}

void Protobetter::DynamicObject::SetUInt64(const std::string& memberName, uint64_t value)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    this->SetUInt64(this->memberAccessors->at(memberName), value);
}

void Protobetter::DynamicObject::SetInt64(const Protobetter::FieldAccessor &accessor, int64_t value)
{
    int64_t swappedValue = 0;

    if (this->isLittleEndian)
    {
        swappedValue = bswap_64(value);
    }

    memcpy(this->data + accessor.byteOffset, &swappedValue, 8);
}

void Protobetter::DynamicObject::SetInt64(const std::string& memberName, int64_t value)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    this->SetInt64(this->memberAccessors->at(memberName), value);
}

void Protobetter::DynamicObject::SetFloat(const Protobetter::FieldAccessor &accessor, float value)
{
    int32_t packedValue = 0;

    int32_t unpackedValue = 0;
    memcpy(&unpackedValue, &value, 4);

    if (this->isLittleEndian)
    {
        packedValue = bswap_32(unpackedValue);
    }

    memcpy(this->data + accessor.byteOffset, &packedValue, 4);
}

void Protobetter::DynamicObject::SetFloat(const std::string& memberName, float value)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    this->SetFloat(this->memberAccessors->at(memberName), value);
}

void Protobetter::DynamicObject::SetDouble(const Protobetter::FieldAccessor &accessor, double value)
{
    int64_t packedValue = 0;

    int64_t unpackedValue = 0;
    memcpy(&unpackedValue, &value, 8);

    if (this->isLittleEndian)
    {
        packedValue = bswap_64(unpackedValue);
    }

    memcpy(this->data + accessor.byteOffset, &packedValue, 8);
}

void Protobetter::DynamicObject::SetDouble(const std::string& memberName, double value)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    this->SetDouble(this->memberAccessors->at(memberName), value);
}

const char * Protobetter::DynamicObject::GetByteArray(const Protobetter::FieldAccessor &accessor)
{
    return (this->data + accessor.byteOffset);
}

const char * Protobetter::DynamicObject::GetByteArray(const std::string& memberName)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    Protobetter::FieldAccessor accessor = this->memberAccessors->at(memberName);

    return (this->data + accessor.byteOffset);
}

void Protobetter::DynamicObject::SetByteArray(const Protobetter::FieldAccessor &accessor, const char *value)
{
    memcpy(this->data + accessor.byteOffset, value, accessor.size);
}

void Protobetter::DynamicObject::SetByteArray(const std::string& memberName, const char *value)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    Protobetter::FieldAccessor accessor = this->memberAccessors->at(memberName);

    memcpy(this->data + accessor.byteOffset, value, accessor.size);
}

uint64_t Protobetter::DynamicObject::GetUnsignedBitfield(const Protobetter::FieldAccessor &accessor)
{
    char *fieldStart = this->data + accessor.byteOffset;

    if (accessor.size == 1)
    {
        uint8_t value;

        memcpy(&value, fieldStart, 1);

        return (value & ~accessor.packingMask) >> accessor.bitOffset;
    }
    else if (accessor.size == 2)
    {
        uint16_t value = 0;
        memcpy(&value, fieldStart, 2);

        if (this->isLittleEndian)
        {
            value = bswap_16(value);
        }

        return (value & ~accessor.packingMask) >> accessor.bitOffset;
    }
    else if (accessor.size == 4)
    {
        uint32_t value = 0;
        memcpy(&value, fieldStart, 4);

        if (this->isLittleEndian)
        {
            value = bswap_32(value);
        }

        return (value & ~accessor.packingMask) >> accessor.bitOffset;
    }
    else if (accessor.size == 8)
    {
        uint64_t value = 0;
        memcpy(&value, fieldStart, 8);

        if (this->isLittleEndian)
        {
            value = bswap_64(value);
        }

        return (value & ~accessor.packingMask) >> accessor.bitOffset;
    }

    return 0;
}

uint64_t Protobetter::DynamicObject::GetUnsignedBitfield(const std::string& memberName)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    Protobetter::FieldAccessor accessor = this->memberAccessors->at(memberName);

    return this->GetUnsignedBitfield(accessor);
}

int64_t Protobetter::DynamicObject::GetSignedBitfield(const Protobetter::FieldAccessor &accessor)
{
    char *fieldStart = this->data + accessor.byteOffset;

    if (accessor.size == 1)
    {
        uint8_t value;

        memcpy(&value, fieldStart, 1);

        return (value & ~accessor.packingMask) >> accessor.bitOffset;
    }
    else if (accessor.size == 2)
    {
        uint16_t value = 0;
        memcpy(&value, fieldStart, 2);

        if (this->isLittleEndian)
        {
            value = bswap_16(value);
        }

        value = (value & ~accessor.packingMask) >> accessor.bitOffset;

        return GetTwosComplementSignedEquivalent(value, accessor.bitfieldSize);
    }
    else if (accessor.size == 4)
    {
        uint32_t value = 0;
        memcpy(&value, fieldStart, 4);

        if (this->isLittleEndian)
        {
            value = bswap_32(value);
        }

        value = (value & ~accessor.packingMask) >> accessor.bitOffset;

        return GetTwosComplementSignedEquivalent(value, accessor.bitfieldSize);
    }
    else if (accessor.size == 8)
    {
        uint64_t value = 0;
        memcpy(&value, fieldStart, 8);

        if (this->isLittleEndian)
        {
            value = bswap_64(value);
        }

        value = (value & ~accessor.packingMask) >> accessor.bitOffset;

        return GetTwosComplementSignedEquivalent(value, accessor.bitfieldSize);
    }

    return -1;
}

int64_t Protobetter::DynamicObject::GetSignedBitfield(const std::string& memberName)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    Protobetter::FieldAccessor accessor = this->memberAccessors->at(memberName);

    return this->GetSignedBitfield(accessor);
}

void Protobetter::DynamicObject::SetSignedBitfield(const Protobetter::FieldAccessor &accessor, int64_t value)
{
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
        int16_t buffer = 0;
        memcpy(&buffer, fieldStart, 2);

        if (this->isLittleEndian)
        {
            buffer = bswap_16(buffer);
        }

        buffer = (buffer & accessor.packingMask) | (unsignedContainer << accessor.bitOffset);

        if (this->isLittleEndian)
        {
            buffer = bswap_16(buffer);
        }

        memcpy(fieldStart, &buffer, 2);
    }
    else if (accessor.size == 4)
    {
        int32_t buffer = 0;
        memcpy(&buffer, fieldStart, 4);

        if (this->isLittleEndian)
        {
            buffer = bswap_32(buffer);
        }   

        buffer = (buffer & accessor.packingMask) | (unsignedContainer << accessor.bitOffset);

        if (this->isLittleEndian)
        {
            buffer = bswap_32(buffer);
        }   

        memcpy(fieldStart, &buffer, 4);
    }
    else if (accessor.size == 8)
    {
        int64_t buffer = 0;
        memcpy(&buffer, fieldStart, 8);

        if (this->isLittleEndian)
        {
            buffer = bswap_64(buffer);
        }

        buffer = (buffer & accessor.packingMask) | (unsignedContainer << accessor.bitOffset);

        if (this->isLittleEndian)
        {
            buffer = bswap_64(buffer);
        }

        memcpy(fieldStart, &buffer, 8);
    }
}

void Protobetter::DynamicObject::SetSignedBitfield(const std::string& memberName, int64_t value)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    Protobetter::FieldAccessor accessor = this->memberAccessors->at(memberName);

    this->SetSignedBitfield(accessor, value);
}

void Protobetter::DynamicObject::SetUnsignedBitfield(const Protobetter::FieldAccessor &accessor, uint64_t value)
{
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
        memcpy(&buffer, fieldStart, 2);

        if (this->isLittleEndian)
        {
            buffer = bswap_16(buffer);
        }

        buffer = (buffer & accessor.packingMask) | (value << accessor.bitOffset);

        if (this->isLittleEndian)
        {
            buffer = bswap_16(buffer);
        }

        memcpy(fieldStart, &buffer, 2);
    }
    else if (accessor.size == 4)
    {
        uint32_t buffer;
        memcpy(&buffer, fieldStart, 4);

        if (this->isLittleEndian)
        {
            buffer = bswap_32(buffer);
        }

        buffer = (buffer & accessor.packingMask) | (value << accessor.bitOffset);

        if (this->isLittleEndian)
        {
            buffer = bswap_32(buffer);
        }

        memcpy(fieldStart, &buffer, 4);
    }
    else if (accessor.size == 8)
    {
        uint64_t buffer;
        memcpy(&buffer, fieldStart, 8);

        if (this->isLittleEndian)
        {
            buffer = bswap_64(buffer);
        }

        buffer = (buffer & accessor.packingMask) | (value << accessor.bitOffset);

        if (this->isLittleEndian)
        {
            buffer = bswap_64(buffer);
        }

        memcpy(fieldStart, &buffer, 8); 
    }
}

void Protobetter::DynamicObject::SetUnsignedBitfield(const std::string& memberName, uint64_t value)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    Protobetter::FieldAccessor accessor = this->memberAccessors->at(memberName);

    this->SetUnsignedBitfield(accessor, value);
}

Protobetter::DynamicObject Protobetter::DynamicObject::GetObject(std::shared_ptr<DynamicType> type, const Protobetter::FieldAccessor &accessor)
{
    return Protobetter::DynamicObject(type, this->data + accessor.byteOffset);
}

Protobetter::DynamicObject Protobetter::DynamicObject::GetObject(std::shared_ptr<DynamicType> type, const std::string& memberName)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }
    else if ((!type->IsComplete()) || (!type->IsRoot()))
    {
        throw std::invalid_argument("Protobetter::DynamicObject::GetObject() must only be called on a complete root type!");
    }

    Protobetter::FieldAccessor accessor = this->memberAccessors->at(memberName);

    char *fieldStart = this->data + accessor.byteOffset;

    return Protobetter::DynamicObject(type, fieldStart);
}

void Protobetter::DynamicObject::SetObject(const Protobetter::FieldAccessor &accessor, const DynamicObject &object)
{
    memcpy(this->data + accessor.byteOffset, object.Data(), accessor.size);
}

void Protobetter::DynamicObject::SetObject(const std::string& memberName, const DynamicObject &object)
{
    std::map<std::string, FieldAccessor>::iterator it = this->memberAccessors->find(memberName);
    if (it == this->memberAccessors->end())
    {
        std::string errMsg = std::string("No member named ") + memberName;
        throw std::invalid_argument(errMsg.c_str());
    }

    Protobetter::FieldAccessor accessor = this->memberAccessors->at(memberName);

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

// TODO: move this to the anonymous namespace at the top of file when done testing
namespace {

//    Protobetter::Prototype BuildPrototypeFromXTCESpaceSystem(QXmlStreamReader &reader)
//    {
//        Protobetter::Prototype newType;

//        // make sure the most recently read token is actually a 'SpaceSystem' element
//        if (reader.tokenType() != QXmlStreamReader::StartElement &&
//                reader.name() != "SpaceSystem")
//        {

//        }


//    }

    void BuildPrototypeFromXTCESpaceSystem(xmlNode *node)
    {
        while (node != NULL)
        {
            if (xmlStrcmp(node->name, (const xmlChar *)"SpaceSystem") == 0)
            {
                xmlChar *name = xmlGetProp(node, (const xmlChar*)"name");
                std::cout << "Found a space system w/ attribute 'name' = " << name << std::endl;
                xmlFree(name);

                xmlNode *child = node->xmlChildrenNode;
                BuildPrototypeFromXTCESpaceSystem(child); 
            }

            node = node->next;
        }
    }
}

void Protobetter::PrototypeCollection::LoadPrototypesFromXTCE(const std::string& filePath)
{
    LIBXML_TEST_VERSION 
    xmlDoc *doc = xmlReadFile(filePath.c_str(), NULL, 0);
    if (doc == NULL)
    {
        std::cout << "Unable to open XTCE file: " << filePath << std::endl;
        return;
    }

    xmlNode *rootElement = xmlDocGetRootElement(doc);
    BuildPrototypeFromXTCESpaceSystem(rootElement);
    
    xmlFreeDoc(doc);
    xmlCleanupParser();
}

void Protobetter::PrototypeCollection::LoadPrototypesFromPType(const Json::Value &root)
{
    for (Json::Value::iterator it = root.begin(); it != root.end(); ++it)
    {
        Prototype prototype = BuildPrototypeFromJsonObject(*it);

        if (this->HasType(prototype.name))
        {
            std::cout << "PROTOBETTER WARNING: multiple definitions found for type: " << prototype.name << "... ignoring all subsequent definitions..." << std::endl;
        }
        else
        {
            this->rootTypes.push_back(prototype);
        }
    }
}

void Protobetter::PrototypeCollection::LoadPrototypesFromPType(const std::string& filePath)
{
    std::ifstream file(filePath);
    
    if (!file.is_open())
    {
        std::cout << "PrototypeCollection ERROR: Unable to open ptype file: " << filePath << std::endl;
        return;
    }

    Json::Value root;
    file >> root;
    
    if (root.isNull())
    {
        std::cout << "PrototypeCollection ERROR: Unable to open ptype file: " << filePath << std::endl;
        return;
    }
    else
    {
        this->LoadPrototypesFromPType(root);
    }

    file.close();
}

Json::Value Protobetter::Prototype::ToJsonObject()
{
    Json::Value object;

    object["name"] = this->name.c_str();

    Json::Value membersArray;

    for (unsigned int i = 0; i < this->members.size(); ++i)
    {
        Json::Value member;

        member["name"] = this->members[i].name.c_str();
        member["type"] = this->members[i].type.c_str();

        if (this->members[i].arrayLength != 0)
        {
            member["arraylen"] = this->members[i].arrayLength;
        }

        if (this->members[i].bits != 0)
        {
            member["bits"] = this->members[i].bits;
        }

        membersArray.append(member);
    }
    
    object["members"] = membersArray;

    return object;
}
