#ifndef PROTOBETTERDYNAMIC_H
#define PROTOBETTERDYNAMIC_H

#include <map>
#include <string>
#include <vector>
#include <memory>
#include <cstdint>

#include <json/json.h>

// TODO: update this so that you pass your strings and similar types around
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

    struct PrototypeMember
    {
        std::string name;
        std::string type;
        int arrayLength = 0;
        int bits = 0;
    };

    // this is the c++ object corresponding to a single 'ProtoType'
    // json object defined in a *.ptype file
    class Prototype
    {
    public:

        Prototype();
        Prototype(const std::string& name);

        Json::Value ToJsonObject();

        bool HasMember(const std::string& memberName);
        PrototypeMember GetMember(const std::string& memberName);

        std::string name;
        std::vector<PrototypeMember> members;
    };

    // just a lightweight wrapper around a list of prototypes
    class PrototypeCollection
    {
    public:

        bool HasType(const std::string& typeName) const;
        Prototype GetType(const std::string& typeName) const;
        Prototype GetType(const int index) const;

        void AddPrototype(const Prototype &prototype);

        // TODO: do some validation on things like making sure bitfield widths are <= size of the word they are packed into,
        //      "bits" and "arraylen" aren't simultaneously specified for same member, and if "bits" is specified,
        //      the "type" better be an acceptable primitive type...
        void LoadPrototypesFromPType(const std::string& filePath);

        void LoadPrototypesFromXTCE(const std::string& filePath);

        void LoadPrototypesFromPType(const Json::Value &root);

        std::size_t Size() const;

        // TODO: add API methods to modify elements already added to this collection

    private:

        std::vector<Prototype> rootTypes;
    };

    struct FieldAccessor
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

    class DynamicType
    {
    public:

        typedef std::shared_ptr<DynamicType> Ptr;

        // returns size in bytes
        virtual std::size_t Size() = 0;

        virtual std::shared_ptr<std::map<std::string, FieldAccessor> > GetMemberMap() = 0;

        virtual std::size_t MemberCount() = 0;

        virtual bool IsComplete() = 0;

        virtual ProtobetterFieldType GetFieldType(const std::string& name) = 0;

        std::string Name();
        bool IsRoot();

    protected:

        DynamicType(const std::string& name, bool isRoot = false);

        virtual ~DynamicType() {};

        bool isRoot;

        std::string name;
    };

    class DynamicTypeCollection
    {
    public:

        bool HasType(const std::string& typeName);
        DynamicType::Ptr GetType(const std::string& typeName);
        DynamicType::Ptr GetType(int index);

        std::size_t Size() const;

        void AddDynamicType(const DynamicType::Ptr ptr);

        static DynamicTypeCollection FromPrototypeCollection(const PrototypeCollection &prototypes);

        std::vector<std::string> GetRootTypeNames();

        // TODO: add API methods to modify elements already added to this collection

    private:

        static void CreateDynamicTypeFromPrototypeRecursive(const PrototypeCollection &prototypes, DynamicTypeCollection &dynamicTypes, const Protobetter::Prototype &ptype);

        std::vector<DynamicType::Ptr> rootTypes;
    };

    class PrimitiveField : public DynamicType
    {
    public:

        typedef std::shared_ptr<PrimitiveField> Ptr;

        static std::shared_ptr<PrimitiveField> CreateNewPrimitiveField(const std::string& name, ProtobetterFieldType type, std::size_t size);

        std::size_t Size();
        std::shared_ptr<std::map<std::string, FieldAccessor> > GetMemberMap();
        std::size_t MemberCount();
        bool IsComplete();

        ProtobetterFieldType GetFieldType(const std::string& name);

    private:

        PrimitiveField(const std::string& name, ProtobetterFieldType type, std::size_t size);

        ProtobetterFieldType type;
        std::size_t size;

        std::shared_ptr<std::map<std::string, FieldAccessor> > memberAccessors;
    };

    class FieldCollection : public DynamicType
    {
    public:

        typedef std::shared_ptr<FieldCollection> Ptr;

        // User must create types through this interface
        static std::shared_ptr<FieldCollection> CreateNewRootType(const std::string& typeName);
        static std::shared_ptr<FieldCollection> CreateFieldFromRootType(const std::string&  fieldName, std::shared_ptr<FieldCollection> root, bool finalize = false);

        std::size_t Size();
        std::shared_ptr<std::map<std::string, FieldAccessor> > GetMemberMap();
        std::size_t MemberCount();
        bool IsComplete();

        void AddField(std::shared_ptr<DynamicType> field);
        std::shared_ptr<DynamicType> GetField(int fieldIndex);

        void Finalize();

        ProtobetterFieldType GetFieldType(const std::string& name);

    private:

        FieldCollection(const std::string& name, bool isRoot = false);

        std::vector<std::shared_ptr<DynamicType> > fields;

        bool isComplete;

        std::shared_ptr<std::map<std::string, FieldAccessor> > memberAccessors;
    };

    class BitfieldCollection : public DynamicType
    {
    public:

        typedef std::shared_ptr<BitfieldCollection> Ptr;

        // Use factory method to create BitfieldCollections
        static std::shared_ptr<BitfieldCollection> CreateNewBitfieldCollection(std::size_t size);

        std::size_t BitsUsed();
        std::size_t BitsAvailable();

        std::size_t Size();
        std::shared_ptr<std::map<std::string, FieldAccessor> > GetMemberMap();
        std::size_t MemberCount();
        bool IsComplete();

        void Finalize();

        void AddField(const std::string& name, std::size_t width, bool isSigned);

        ProtobetterFieldType GetFieldType(const std::string& name);

    private:

        struct Bitfield
        {
            Bitfield();
            Bitfield(const std::string& name, std::size_t bitOffset, std::size_t length, bool isSigned);

            std::string name;
            std::size_t bitOffset;
            std::size_t length;
            bool isSigned;
        };

        BitfieldCollection(std::size_t size);

        std::size_t size;
        std::vector<Bitfield> bitfields;

        bool isComplete;
        std::shared_ptr<std::map<std::string, FieldAccessor> > memberAccessors;
    };

    class DynamicObject
    {
    public:

        typedef std::shared_ptr<DynamicObject> Ptr;

        DynamicObject(std::shared_ptr<DynamicType> type);
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

        DynamicObject GetObject(std::shared_ptr<DynamicType> type, const Protobetter::FieldAccessor &accessor);

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
        uint8_t GetUInt8(const std::string& memberName);
        uint16_t GetUInt16(const std::string& memberName);
        uint32_t GetUInt32(const std::string& memberName);
        uint64_t GetUInt64(const std::string& memberName);

        int8_t GetInt8(const std::string& memberName);
        int16_t GetInt16(const std::string& memberName);
        int32_t GetInt32(const std::string& memberName);
        int64_t GetInt64(const std::string& memberName);

        float GetFloat(const std::string& memberName);
        double GetDouble(const std::string& memberName);

        uint64_t GetUnsignedBitfield(const std::string& memberName);
        int64_t GetSignedBitfield(const std::string& memberName);

        DynamicObject GetObject(std::shared_ptr<DynamicType> type, const std::string& memberName);

        void SetUInt8(const std::string& memberName, uint8_t value);
        void SetUInt16(const std::string& memberName, uint16_t value);
        void SetUInt32(const std::string& memberName, uint32_t value);
        void SetUInt64(const std::string& memberName, uint64_t value);

        void SetInt8(const std::string& memberName, int8_t value);
        void SetInt16(const std::string& memberName, int16_t value);
        void SetInt32(const std::string& memberName, int32_t value);
        void SetInt64(const std::string& memberName, int64_t value);

        void SetFloat(const std::string& memberName, float value);
        void SetDouble(const std::string& memberName, double value);

        void SetUnsignedBitfield(const std::string& memberName, uint64_t value);
        void SetSignedBitfield(const std::string& memberName, int64_t value);

        const char * GetByteArray(const std::string& memberName);
        void SetByteArray(const std::string& memberName, const char *value);

        void SetObject(const std::string& memberName, const DynamicObject &object);

        const char * Data() const;
        void SetData(const char *data);

        std::size_t Size();

    private:

        DynamicObject(std::shared_ptr<DynamicType>, char *data);

        bool isLittleEndian;
        bool ownsData;
        char *data;
        std::size_t size;

        std::string typeName;
        std::shared_ptr<std::map<std::string, FieldAccessor> > memberAccessors;
    };
}

#endif // PROTOBETTERDYNAMIC_H
