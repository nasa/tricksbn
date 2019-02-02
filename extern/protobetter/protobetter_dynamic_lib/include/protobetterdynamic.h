#ifndef PROTOBETTERDYNAMIC_H
#define PROTOBETTERDYNAMIC_H

#include <cstring>

#include <stdint.h>

#include <QString>
#include <QMap>
#include <QList>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QSharedPointer>

#include "protobetter_dynamic_lib_global.h"

// TODO: update this so that you pass your QStrings and similar types around
// by const reference for better performance where possible

namespace Protobetter
{
    enum ProtobetterFieldType
    {
        UInt8,
        UInt16,
        UInt32,
        UInt64,
        Int8,
        Int16,
        Int32,
        Int64,
        UnsignedBitfield,
        SignedBitfield,
        Float,
        Double,
        ByteArray,
        Object
    };

    struct PROTOBETTER_DYNAMIC_LIBSHARED_EXPORT PrototypeMember
    {
        QString name;
        QString type;
        int arrayLength = 0;
        int bits = 0;
    };

    // this is the c++ object corresponding to a single 'ProtoType'
    // json object defined in a *.ptype file
    class PROTOBETTER_DYNAMIC_LIBSHARED_EXPORT Prototype
    {
    public:

        Prototype();
        Prototype(QString name);

        QJsonObject ToJsonObject();

        bool HasMember(QString memberName);
        PrototypeMember GetMember(QString memberName);

        QString name;
        QList<PrototypeMember> members;
    };

    // just a lightweight wrapper around a list of prototypes
    class PROTOBETTER_DYNAMIC_LIBSHARED_EXPORT PrototypeCollection
    {
    public:

        bool HasType(QString typeName) const;
        Prototype GetType(QString typeName) const;
        Prototype GetType(const int index) const;

        void AddPrototype(const Prototype &prototype);

        // TODO: do some validation on things like making sure bitfield widths are <= size of the word they are packed into,
        //      "bits" and "arraylen" aren't simultaneously specified for same member, and if "bits" is specified,
        //      the "type" better be an acceptable primitive type...
        void LoadPrototypesFromPType(QString filePath);

        void LoadPrototypesFromXTCE(QString filePath);

        void LoadPrototypesFromPType(const QJsonDocument &jsonDoc);

        std::size_t Size() const;

        // TODO: add API methods to modify elements already added to this collection

    private:

        QList<Prototype> rootTypes;
    };

    struct PROTOBETTER_DYNAMIC_LIBSHARED_EXPORT FieldAccessor
    {        
        FieldAccessor();
        FieldAccessor(ProtobetterFieldType type, std::size_t size);

        std::size_t byteOffset;
        std::size_t size; // in bytes

        std::size_t bitfieldSize; // in bits - '0' means it's not a bitfield :P
        std::size_t bitOffset; // always 0 for non-bitfield members
        uint64_t packingMask; // all bits = false if not a bitfield o/

        ProtobetterFieldType type;
    };

    class PROTOBETTER_DYNAMIC_LIBSHARED_EXPORT DynamicType
    {
    public:

        typedef QSharedPointer<DynamicType> Ptr;

        // returns size in bytes
        virtual std::size_t Size() = 0;

        virtual QSharedPointer<QMap<QString, FieldAccessor> > GetMemberMap() = 0;

        virtual std::size_t MemberCount() = 0;

        virtual bool IsComplete() = 0;

        virtual ProtobetterFieldType GetFieldType(QString name) = 0;

        QString Name();
        bool IsRoot();

    protected:

        DynamicType(QString name, bool isRoot = false);

        bool isRoot;

        QString name;
    };

    class PROTOBETTER_DYNAMIC_LIBSHARED_EXPORT DynamicTypeCollection
    {
    public:

        bool HasType(QString typeName);
        DynamicType::Ptr GetType(QString typeName);
        DynamicType::Ptr GetType(int index);

        std::size_t Size() const;

        void AddDynamicType(const DynamicType::Ptr ptr);

        static DynamicTypeCollection FromPrototypeCollection(const PrototypeCollection &prototypes);

        QStringList GetRootTypeNames();

        // TODO: add API methods to modify elements already added to this collection

    private:

        static void CreateDynamicTypeFromPrototypeRecursive(const PrototypeCollection &prototypes, DynamicTypeCollection &dynamicTypes, const Protobetter::Prototype &ptype);

        QList<DynamicType::Ptr> rootTypes;
    };

    class PROTOBETTER_DYNAMIC_LIBSHARED_EXPORT PrimitiveField : public DynamicType
    {
    public:

        typedef QSharedPointer<PrimitiveField> Ptr;

        static QSharedPointer<PrimitiveField> CreateNewPrimitiveField(QString name, ProtobetterFieldType type, std::size_t size);

        std::size_t Size();
        QSharedPointer<QMap<QString, FieldAccessor> > GetMemberMap();
        std::size_t MemberCount();
        bool IsComplete();

        ProtobetterFieldType GetFieldType(QString name);

    private:

        PrimitiveField(QString name, ProtobetterFieldType type, std::size_t size);

        ProtobetterFieldType type;
        std::size_t size;

        QSharedPointer<QMap<QString, FieldAccessor> > memberAccessors;
    };

    class PROTOBETTER_DYNAMIC_LIBSHARED_EXPORT FieldCollection : public DynamicType
    {
    public:

        typedef QSharedPointer<FieldCollection> Ptr;

        // User must create types through this interface
        static QSharedPointer<FieldCollection> CreateNewRootType(QString typeName);
        static QSharedPointer<FieldCollection> CreateFieldFromRootType(QString fieldName, QSharedPointer<FieldCollection> root, bool finalize = false);

        std::size_t Size();
        QSharedPointer<QMap<QString, FieldAccessor> > GetMemberMap();
        std::size_t MemberCount();
        bool IsComplete();

        void AddField(QSharedPointer<DynamicType> field);
        QSharedPointer<DynamicType> GetField(int fieldIndex);

        void Finalize();

        ProtobetterFieldType GetFieldType(QString name);

    private:

        FieldCollection(QString name, bool isRoot = false);

        QList<QSharedPointer<DynamicType> > fields;

        bool isComplete;

        QSharedPointer<QMap<QString, FieldAccessor> > memberAccessors;
    };

    class PROTOBETTER_DYNAMIC_LIBSHARED_EXPORT BitfieldCollection : public DynamicType
    {
    public:

        typedef QSharedPointer<BitfieldCollection> Ptr;

        // Use factory method to create BitfieldCollections
        static QSharedPointer<BitfieldCollection> CreateNewBitfieldCollection(std::size_t size);

        std::size_t BitsUsed();
        std::size_t BitsAvailable();

        std::size_t Size();
        QSharedPointer<QMap<QString, FieldAccessor> > GetMemberMap();
        std::size_t MemberCount();
        bool IsComplete();

        void Finalize();

        void AddField(QString name, std::size_t width, bool isSigned);

        ProtobetterFieldType GetFieldType(QString name);

    private:

        struct Bitfield
        {
            Bitfield();
            Bitfield(QString name, std::size_t bitOffset, std::size_t length, bool isSigned);

            QString name;
            std::size_t bitOffset;
            std::size_t length;
            bool isSigned;
        };

        BitfieldCollection(std::size_t size);

        std::size_t size;
        QList<Bitfield> bitfields;

        bool isComplete;
        QSharedPointer<QMap<QString, FieldAccessor> > memberAccessors;
    };

    class PROTOBETTER_DYNAMIC_LIBSHARED_EXPORT DynamicObject
    {
    public:

        typedef QSharedPointer<DynamicObject> Ptr;

        DynamicObject(QSharedPointer<DynamicType> type);
        ~DynamicObject();

        DynamicObject(const DynamicObject &other);

        DynamicObject& operator=(const DynamicObject &other);

        // APIs for accessing field data via FieldAccessors
        // which can be obtained from the associated DynamicType
        uint8_t GetUInt8(const Protobetter::FieldAccessor &accessor);
        uint16_t GetUInt16(const Protobetter::FieldAccessor &accessor);
        uint32_t GetUInt32(const Protobetter::FieldAccessor &accessor);
        uint64_t GetUInt64(const Protobetter::FieldAccessor &accessor);

        int8_t GetInt8(const Protobetter::FieldAccessor &accessor);
        int16_t GetInt16(const Protobetter::FieldAccessor &accessor);
        int32_t GetInt32(const Protobetter::FieldAccessor &accessor);
        int64_t GetInt64(const Protobetter::FieldAccessor &accessor);

        float GetFloat(const Protobetter::FieldAccessor &accessor);
        double GetDouble(const Protobetter::FieldAccessor &accessor);

        uint64_t GetUnsignedBitfield(const Protobetter::FieldAccessor &accessor);
        int64_t GetSignedBitfield(const Protobetter::FieldAccessor &accessor);

        DynamicObject GetObject(QSharedPointer<DynamicType> type, const Protobetter::FieldAccessor &accessor);

        void SetUInt8(const Protobetter::FieldAccessor &accessor, uint8_t value);
        void SetUInt16(const Protobetter::FieldAccessor &accessor, uint16_t value);
        void SetUInt32(const Protobetter::FieldAccessor &accessor, uint32_t value);
        void SetUInt64(const Protobetter::FieldAccessor &accessor, uint64_t value);

        void SetInt8(const Protobetter::FieldAccessor &accessor, int8_t value);
        void SetInt16(const Protobetter::FieldAccessor &accessor, int16_t value);
        void SetInt32(const Protobetter::FieldAccessor &accessor, int32_t value);
        void SetInt64(const Protobetter::FieldAccessor &accessor, int64_t value);

        void SetFloat(const Protobetter::FieldAccessor &accessor, float value);
        void SetDouble(const Protobetter::FieldAccessor &accessor, double value);

        void SetUnsignedBitfield(const Protobetter::FieldAccessor &accessor, uint64_t value);
        void SetSignedBitfield(const Protobetter::FieldAccessor &accessor, int64_t value);

        const char * GetByteArray(const Protobetter::FieldAccessor &accessor);
        void SetByteArray(const Protobetter::FieldAccessor &accessor, const char *value);

        void SetObject(const Protobetter::FieldAccessor &accessor, const DynamicObject &object);

        // convenience methods for grabbing member data by name
        uint8_t GetUInt8(QString memberName);
        uint16_t GetUInt16(QString memberName);
        uint32_t GetUInt32(QString memberName);
        uint64_t GetUInt64(QString memberName);

        int8_t GetInt8(QString memberName);
        int16_t GetInt16(QString memberName);
        int32_t GetInt32(QString memberName);
        int64_t GetInt64(QString memberName);

        float GetFloat(QString memberName);
        double GetDouble(QString memberName);

        uint64_t GetUnsignedBitfield(QString memberName);
        int64_t GetSignedBitfield(QString memberName);

        DynamicObject GetObject(QSharedPointer<DynamicType> type, QString memberName);

        void SetUInt8(QString memberName, uint8_t value);
        void SetUInt16(QString memberName, uint16_t value);
        void SetUInt32(QString memberName, uint32_t value);
        void SetUInt64(QString memberName, uint64_t value);

        void SetInt8(QString memberName, int8_t value);
        void SetInt16(QString memberName, int16_t value);
        void SetInt32(QString memberName, int32_t value);
        void SetInt64(QString memberName, int64_t value);

        void SetFloat(QString memberName, float value);
        void SetDouble(QString memberName, double value);

        void SetUnsignedBitfield(QString memberName, uint64_t value);
        void SetSignedBitfield(QString memberName, int64_t value);

        const char * GetByteArray(QString memberName);
        void SetByteArray(QString memberName, const char *value);

        void SetObject(QString memberName, const DynamicObject &object);

        const char * Data() const;
        void SetData(const char *data);

        std::size_t Size();

    private:

        DynamicObject(QSharedPointer<DynamicType>, char *data);

        bool ownsData;
        char *data;
        std::size_t size;

        QString typeName;
        QSharedPointer<QMap<QString, FieldAccessor> > memberAccessors;
    };
}

#endif // PROTOBETTERDYNAMIC_H
