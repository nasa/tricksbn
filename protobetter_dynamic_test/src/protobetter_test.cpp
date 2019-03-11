#include <cstring>
#include <bitset>
#include <iostream>

#include <QtEndian>

#include <QtDebug>
#include <QBitArray>
#include <QByteArray>

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

#include "protobetter_test.h"

#include "protobetter_generated.h"

namespace
{
    void CompareFloats(float a, float b)
    {
        QVERIFY(qFuzzyCompare(a + 1.0f, b + 1.0f));
    }

    void CompareDoubles(double a, double b)
    {
        QVERIFY(qFuzzyCompare(a + 1.0f, b + 1.0f));
    }

    Protobetter::FieldCollection::Ptr CreateVectorRootType()
    {
        auto type = Protobetter::FieldCollection::CreateNewRootType("Vector_c");

        auto bitfieldCollection = Protobetter::BitfieldCollection::CreateNewBitfieldCollection(1);

        bitfieldCollection->AddField("id", 4, false);
        bitfieldCollection->Finalize();

        type->AddField(bitfieldCollection);

        type->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField("x", Protobetter::Float, 4));
        type->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField("y", Protobetter::Float, 4));
        type->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField("z", Protobetter::Float, 4));

        type->Finalize();

        return type;
    }

    Protobetter::FieldCollection::Ptr CreateLilbittyRootType(Protobetter::FieldCollection::Ptr vectorRootType)
    {
        auto type = Protobetter::FieldCollection::CreateNewRootType("LilBitty_c");

        // float
        type->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField("a", Protobetter::Float, 4));

        auto bitfieldCollection = Protobetter::BitfieldCollection::CreateNewBitfieldCollection(4);

        bitfieldCollection->AddField("b", 31, false);
        bitfieldCollection->AddField("c", 1, false);
        bitfieldCollection->Finalize();

        type->AddField(bitfieldCollection);

        bitfieldCollection = Protobetter::BitfieldCollection::CreateNewBitfieldCollection(4);

        bitfieldCollection->AddField("d", 4, false);
        bitfieldCollection->Finalize();

        type->AddField(bitfieldCollection);

        type->AddField(Protobetter::FieldCollection::CreateFieldFromRootType("e[0]", vectorRootType, true));
        type->AddField(Protobetter::FieldCollection::CreateFieldFromRootType("e[1]", vectorRootType, true));
        type->AddField(Protobetter::FieldCollection::CreateFieldFromRootType("e[2]", vectorRootType, true));

        bitfieldCollection = Protobetter::BitfieldCollection::CreateNewBitfieldCollection(2);

        bitfieldCollection->AddField("f", 16, true);
        bitfieldCollection->Finalize();

        type->AddField(bitfieldCollection);

        type->Finalize();

        return type;
    }

    Protobetter::FieldCollection::Ptr CreateBittyliciousRootType(Protobetter::FieldCollection::Ptr vectorRootType, Protobetter::FieldCollection::Ptr lilBittyRootType)
    {
        auto type = Protobetter::FieldCollection::CreateNewRootType("Bittylicious_c");

        type->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField("header", Protobetter::ByteArray, 16));
        type->AddField(qSharedPointerCast<Protobetter::DynamicType>(Protobetter::PrimitiveField::CreateNewPrimitiveField("a", Protobetter::Double, 8)));

        type->AddField(Protobetter::FieldCollection::CreateFieldFromRootType("b[0]", lilBittyRootType, true));
        type->AddField(Protobetter::FieldCollection::CreateFieldFromRootType("b[1]", lilBittyRootType, true));

        type->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField("c[0]", Protobetter::Int16, 2));
        type->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField("c[1]", Protobetter::Int16, 2));
        type->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField("c[2]", Protobetter::Int16, 2));

        type->AddField(Protobetter::FieldCollection::CreateFieldFromRootType("d", vectorRootType, true));

        auto bitfieldCollection = Protobetter::BitfieldCollection::CreateNewBitfieldCollection(1);
        bitfieldCollection->AddField("e", 3, true);
        bitfieldCollection->Finalize();

        type->AddField(bitfieldCollection);

        type->Finalize();

        return type;
    }

    void InitVectorWithExpectedValues(Protobetter::DynamicObject vector)
    {
        vector.SetUnsignedBitfield("id", 15);
        vector.SetFloat("x", 1.2345f);
        vector.SetFloat("y", 97865.4321f);
        vector.SetFloat("z", 867.5309f);
    }

    void VerifyVectorExpectedValues(Protobetter::DynamicObject vector)
    {
        QCOMPARE((int)vector.GetUnsignedBitfield("id"), 15);
        CompareFloats(vector.GetFloat("x"), 1.2345f);
        CompareFloats(vector.GetFloat("y"), 97865.4321f);
        CompareFloats(vector.GetFloat("z"), 867.5309f);
    }

    void InitLilBittyWithExpectedValues(Protobetter::DynamicType::Ptr vectorRootType, Protobetter::DynamicObject lilbitty)
    {
        lilbitty.SetFloat("a", 123.123f);
        lilbitty.SetUnsignedBitfield("b", 134217728);
        lilbitty.SetUnsignedBitfield("c", 1);
        lilbitty.SetUnsignedBitfield("d", 7);

        InitVectorWithExpectedValues(lilbitty.GetObject(vectorRootType, "e[0]"));
        InitVectorWithExpectedValues(lilbitty.GetObject(vectorRootType, "e[1]"));
        InitVectorWithExpectedValues(lilbitty.GetObject(vectorRootType, "e[2]"));

        lilbitty.SetSignedBitfield("f", 25867);
    }

    void VerifyVectorRootTypeDefinition(Protobetter::DynamicType::Ptr vectorRootType)
    {
        QCOMPARE(vectorRootType->GetFieldType("id"), Protobetter::UnsignedBitfield);
        QCOMPARE(vectorRootType->GetFieldType("x"), Protobetter::Float);
        QCOMPARE(vectorRootType->GetFieldType("y"), Protobetter::Float);
        QCOMPARE(vectorRootType->GetFieldType("z"), Protobetter::Float);
    }

    void VerifyLilBittyRootTypeDefinition(Protobetter::DynamicType::Ptr lilBittyRootType)
    {
        QCOMPARE(lilBittyRootType->GetFieldType("a"), Protobetter::Float);
        QCOMPARE(lilBittyRootType->GetFieldType("b"), Protobetter::UnsignedBitfield);
        QCOMPARE(lilBittyRootType->GetFieldType("c"), Protobetter::UnsignedBitfield);
        QCOMPARE(lilBittyRootType->GetFieldType("d"), Protobetter::UnsignedBitfield);
        QCOMPARE(lilBittyRootType->GetFieldType("e[0]"), Protobetter::Object);
        QCOMPARE(lilBittyRootType->GetFieldType("e[1]"), Protobetter::Object);
        QCOMPARE(lilBittyRootType->GetFieldType("e[2]"), Protobetter::Object);
        QCOMPARE(lilBittyRootType->GetFieldType("f"), Protobetter::SignedBitfield);
    }

    void VerifyBittyliciousRootTypeDefinition(Protobetter::DynamicType::Ptr bittyliciousRootType)
    {
        QCOMPARE(bittyliciousRootType->GetFieldType("header"), Protobetter::ByteArray);
        QCOMPARE(bittyliciousRootType->GetFieldType("b[0]"), Protobetter::Object);
        QCOMPARE(bittyliciousRootType->GetFieldType("b[1]"), Protobetter::Object);
        QCOMPARE(bittyliciousRootType->GetFieldType("c[0]"), Protobetter::Int16);
        QCOMPARE(bittyliciousRootType->GetFieldType("c[1]"), Protobetter::Int16);
        QCOMPARE(bittyliciousRootType->GetFieldType("c[2]"), Protobetter::Int16);
        QCOMPARE(bittyliciousRootType->GetFieldType("d"), Protobetter::Object);
        QCOMPARE(bittyliciousRootType->GetFieldType("e"), Protobetter::SignedBitfield);
    }

    void VerifyLilBittyExpectedValues(Protobetter::DynamicType::Ptr vectorRootType, Protobetter::DynamicObject lilbitty)
    {
        CompareFloats(lilbitty.GetFloat("a"), 123.123f);
        QCOMPARE((int)lilbitty.GetUnsignedBitfield("b"), 134217728);
        QCOMPARE((int)lilbitty.GetUnsignedBitfield("c"), 1);
        QCOMPARE((int)lilbitty.GetUnsignedBitfield("d"), 7);

        VerifyVectorExpectedValues(lilbitty.GetObject(vectorRootType, "e[0]"));
        VerifyVectorExpectedValues(lilbitty.GetObject(vectorRootType, "e[1]"));
        VerifyVectorExpectedValues(lilbitty.GetObject(vectorRootType, "e[2]"));

        QCOMPARE(lilbitty.GetSignedBitfield("f"), 25867);
    }

    void InitBittyliciousWithExpectedValues(Protobetter::DynamicType::Ptr lilBittyRootType, Protobetter::DynamicType::Ptr vectorRootType, Protobetter::DynamicObject bittylicious)
    {
        bittylicious.SetByteArray("header", "The quick brown");
        bittylicious.SetDouble("a", 42.123456l);

        InitLilBittyWithExpectedValues(vectorRootType, bittylicious.GetObject(lilBittyRootType, "b[0]"));
        InitLilBittyWithExpectedValues(vectorRootType, bittylicious.GetObject(lilBittyRootType, "b[1]"));

        bittylicious.SetInt16("c[0]", 12);
        bittylicious.SetInt16("c[1]", 9);
        bittylicious.SetInt16("c[2]", 6);

        InitVectorWithExpectedValues(bittylicious.GetObject(vectorRootType, "d"));

        bittylicious.SetSignedBitfield("e", 3);
    }

    void VerifyBittyliciousExpectedValues(Protobetter::DynamicType::Ptr lilBittyRootType, Protobetter::DynamicType::Ptr vectorRootType, Protobetter::DynamicObject bittylicious)
    {
        QVERIFY(strcmp(bittylicious.GetByteArray("header"), "The quick brown") == 0);

        CompareDoubles(bittylicious.GetDouble("a"), 42.123456l);

        VerifyLilBittyExpectedValues(vectorRootType, bittylicious.GetObject(lilBittyRootType, "b[0]"));
        VerifyLilBittyExpectedValues(vectorRootType, bittylicious.GetObject(lilBittyRootType, "b[1]"));

        QCOMPARE(bittylicious.GetInt16("c[0]"), 12);
        QCOMPARE(bittylicious.GetInt16("c[1]"), 9);
        QCOMPARE(bittylicious.GetInt16("c[2]"), 6);

        VerifyVectorExpectedValues(bittylicious.GetObject(vectorRootType, "d"));

        QCOMPARE(bittylicious.GetSignedBitfield("e"), 3);
    }
}

void ProtobetterTest::TestPrototypeJsonDeserialization()
{
    Protobetter::PrototypeCollection prototypes;

    prototypes.LoadPrototypesFromPType(QString(":/protobetter_test/data/test_c.ptype"));

    QVERIFY(prototypes.HasType("Vector_c"));
    QVERIFY(prototypes.HasType("LilBity_c"));
    QVERIFY(prototypes.HasType("Bittylicious_c"));
}

void ProtobetterTest::TestAmpsPrototypeJsonDeserialization()
{
    Protobetter::PrototypeCollection prototypes;

    prototypes.LoadPrototypesFromPType(QString(":/protobetter_test/data/habitat_ptypes/protobetter_AMPS.ptype"));

    QVERIFY(prototypes.HasType("PDU1"));
    QVERIFY(prototypes.HasType("MBSU1"));
    QVERIFY(prototypes.HasType("SET_PDU1_INPUT_BUS_SELECT_t"));
}

void ProtobetterTest::TestXTCEDeserialization()
{
    Protobetter::PrototypeCollection prototypes;

    prototypes.LoadPrototypesFromXTCE(":/protobetter_test/data/habitat_1.xtce");
}

void ProtobetterTest::TestDynamicAPI()
{
    try
    {
        /* Define a DynamicType at runtime */
        Protobetter::FieldCollection::Ptr type = Protobetter::FieldCollection::CreateNewRootType("LilBitty_c");

        type->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField("fieldA", Protobetter::Float, 4));

        type->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField("fieldB", Protobetter::Double, 8));

        auto vectorRootType = CreateVectorRootType();

        // type: "Vector"
        type->AddField(Protobetter::FieldCollection::CreateFieldFromRootType("vectorField[0]", vectorRootType, true));

        auto bitfieldCollection = Protobetter::BitfieldCollection::CreateNewBitfieldCollection(4);

        bitfieldCollection->AddField("bitfieldA", 3, false);
        bitfieldCollection->AddField("bitfieldB", 2, false);
        bitfieldCollection->AddField("bitfieldC", 5, true);
        bitfieldCollection->Finalize();

        // bitfield collection
        type->AddField(bitfieldCollection);

        type->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField("fieldC", Protobetter::Int32, 4));

        auto lilBittyRootType = CreateLilbittyRootType(vectorRootType);

        type->AddField(Protobetter::FieldCollection::CreateFieldFromRootType("myLilBitty", lilBittyRootType, true));

        type->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField("fieldD", Protobetter::UInt32, 4));

        bitfieldCollection = Protobetter::BitfieldCollection::CreateNewBitfieldCollection(2);

        bitfieldCollection->AddField("bitfieldD", 11, true);
        bitfieldCollection->AddField("bitfieldE", 4, true);
        bitfieldCollection->AddField("bitfieldF", 1, false);
        bitfieldCollection->Finalize();

        // bitfield collection
        type->AddField(bitfieldCollection);

        bitfieldCollection = Protobetter::BitfieldCollection::CreateNewBitfieldCollection(1);

        bitfieldCollection->AddField("tinyBits", 2, false);
        bitfieldCollection->AddField("tinyBitsRollover", 5, false);
        bitfieldCollection->Finalize();

        // bitfield collection
        type->AddField(bitfieldCollection);

        type->Finalize();

        /* Instantiate of DynamicObject with DynamicType we just created and initialize it's values */
        Protobetter::DynamicObject myStructInstance(type);

        myStructInstance.SetFloat("fieldA", 123.456f);
        myStructInstance.SetDouble("fieldB", 9876.5432f);
        myStructInstance.SetInt32("fieldC", -421234);
        myStructInstance.SetUInt32("fieldD", 678910);

        myStructInstance.SetFloat("vectorField[0].x", 42.0f);
        myStructInstance.SetFloat("vectorField[0].y", 43.0f);
        myStructInstance.SetFloat("vectorField[0].z", 44.0f);

        myStructInstance.SetUnsignedBitfield("bitfieldA", 3);
        myStructInstance.SetUnsignedBitfield("bitfieldB", 1);
        myStructInstance.SetSignedBitfield("bitfieldC", -5);

        myStructInstance.SetSignedBitfield("bitfieldD", -1024);
        myStructInstance.SetSignedBitfield("bitfieldE", 7);
        myStructInstance.SetUnsignedBitfield("bitfieldF", 1);

        myStructInstance.SetSignedBitfield("myLilBitty.f", -32768);

        myStructInstance.SetFloat("myLilBitty.e[1].x", -987.0f);
        myStructInstance.SetFloat("myLilBitty.e[1].y", -654.0f);
        myStructInstance.SetFloat("myLilBitty.e[1].z", -321.0f);

        myStructInstance.SetUnsignedBitfield("tinyBitsRollover", 32);
        myStructInstance.SetSignedBitfield("tinyBits", 3);

        /* Verify that you can read back all of the fields from the dynamic object */

        // first make sure your DynamicType has the right expected size
        QVERIFY(type->Size() == 93);

        QCOMPARE(type->GetFieldType("bitfieldA"), Protobetter::UnsignedBitfield);
        QCOMPARE(type->GetFieldType("bitfieldB"), Protobetter::UnsignedBitfield);
        QCOMPARE(type->GetFieldType("bitfieldC"), Protobetter::SignedBitfield);
        QCOMPARE(type->GetFieldType("bitfieldD"), Protobetter::SignedBitfield);
        QCOMPARE(type->GetFieldType("bitfieldE"), Protobetter::SignedBitfield);
        QCOMPARE(type->GetFieldType("bitfieldF"), Protobetter::UnsignedBitfield);

        QCOMPARE((int)myStructInstance.GetUnsignedBitfield("bitfieldA"), 3);
        QCOMPARE((int)myStructInstance.GetUnsignedBitfield("bitfieldB"), 1);
        QCOMPARE((int)myStructInstance.GetSignedBitfield("bitfieldC"), -5);
        QCOMPARE((int)myStructInstance.GetSignedBitfield("bitfieldD"), -1024);
        QCOMPARE((int)myStructInstance.GetSignedBitfield("bitfieldE"), 7);
        QCOMPARE((int)myStructInstance.GetUnsignedBitfield("bitfieldF"), 1);

        QCOMPARE(type->GetFieldType("fieldA"), Protobetter::Float);
        QCOMPARE(type->GetFieldType("fieldB"), Protobetter::Double);

        CompareFloats(myStructInstance.GetFloat("fieldA"), 123.456f);
        CompareDoubles(myStructInstance.GetDouble("fieldB"), 9876.5432f);

        QCOMPARE(myStructInstance.GetInt32("fieldC"), -421234);
        QCOMPARE((long)myStructInstance.GetUInt32("fieldD"), 678910);

        QCOMPARE(type->GetFieldType("vectorField[0].x"), Protobetter::Float);
        QCOMPARE(type->GetFieldType("vectorField[0].y"), Protobetter::Float);
        QCOMPARE(type->GetFieldType("vectorField[0].z"), Protobetter::Float);

        CompareFloats(myStructInstance.GetFloat("vectorField[0].x"), 42.0f);
        CompareFloats(myStructInstance.GetFloat("vectorField[0].y"), 43.0f);
        CompareFloats(myStructInstance.GetFloat("vectorField[0].z"), 44.0f);

        QCOMPARE(type->GetFieldType("myLilBitty.f"), Protobetter::SignedBitfield);

        QCOMPARE(myStructInstance.GetSignedBitfield("myLilBitty.f"), -32768);

        {
            // we should be able to get an object referencing the same underlying data
            // and delete it without destroying the data since the reference doesn't own it
            auto myLilBitty = myStructInstance.GetObject(lilBittyRootType, "myLilBitty");

            QCOMPARE(lilBittyRootType->GetFieldType("f"), Protobetter::SignedBitfield);

            CompareFloats(myLilBitty.GetSignedBitfield("f"), -32768);
        }

        QCOMPARE(type->GetFieldType("myLilBitty.e[0].x"), Protobetter::Float);
        QCOMPARE(type->GetFieldType("myLilBitty.e[0].y"), Protobetter::Float);
        QCOMPARE(type->GetFieldType("myLilBitty.e[0].z"), Protobetter::Float);
        QCOMPARE(type->GetFieldType("myLilBitty.e[1].x"), Protobetter::Float);
        QCOMPARE(type->GetFieldType("myLilBitty.e[1].y"), Protobetter::Float);
        QCOMPARE(type->GetFieldType("myLilBitty.e[1].z"), Protobetter::Float);
        QCOMPARE(type->GetFieldType("myLilBitty.e[2].x"), Protobetter::Float);
        QCOMPARE(type->GetFieldType("myLilBitty.e[2].y"), Protobetter::Float);
        QCOMPARE(type->GetFieldType("myLilBitty.e[2].z"), Protobetter::Float);

        CompareFloats(myStructInstance.GetFloat("myLilBitty.e[0].x"), 0.0f);
        CompareFloats(myStructInstance.GetFloat("myLilBitty.e[0].y"), 0.0f);
        CompareFloats(myStructInstance.GetFloat("myLilBitty.e[0].z"), 0.0f);

        {
            auto e1x = myStructInstance.GetObject(vectorRootType, "myLilBitty.e[1]");

            QCOMPARE(vectorRootType->GetFieldType("x"), Protobetter::Float);
            QCOMPARE(vectorRootType->GetFieldType("y"), Protobetter::Float);
            QCOMPARE(vectorRootType->GetFieldType("z"), Protobetter::Float);

            CompareFloats(e1x.GetFloat("x"), -987.0f);
            CompareFloats(e1x.GetFloat("y"), -654.0f);
            CompareFloats(e1x.GetFloat("z"), -321.0f);
        }

        CompareFloats(myStructInstance.GetFloat("myLilBitty.e[1].x"), -987.0f);
        CompareFloats(myStructInstance.GetFloat("myLilBitty.e[1].y"), -654.0f);
        CompareFloats(myStructInstance.GetFloat("myLilBitty.e[1].z"), -321.0f);

        // verify that myLilBitty.e[2] is zero-ed out
        CompareFloats(myStructInstance.GetFloat("myLilBitty.e[2].x"), 0.0f);
        CompareFloats(myStructInstance.GetFloat("myLilBitty.e[2].y"), 0.0f);
        CompareFloats(myStructInstance.GetFloat("myLilBitty.e[2].z"), 0.0f);

        {
            // we should also be able to create a dynamic object of type 'Vector' and
            // then use it to set a vector-type field of another object...
            Protobetter::DynamicObject tempVector(vectorRootType);
            tempVector.SetFloat("x", 12.34f);
            tempVector.SetFloat("y", 45.67f);
            tempVector.SetFloat("z", 89.1011f);

            // we're going to set myLilBitty.e[2]'s vector field from tempVector's data
            myStructInstance.SetObject("myLilBitty.e[2]", tempVector);
        }

        // this should now be equal to what the temp vector's data was before...
        CompareFloats(myStructInstance.GetFloat("myLilBitty.e[2].x"), 12.34f);
        CompareFloats(myStructInstance.GetFloat("myLilBitty.e[2].y"), 45.67f);
        CompareFloats(myStructInstance.GetFloat("myLilBitty.e[2].z"), 89.1011f);

        QCOMPARE(type->GetFieldType("tinyBits"), Protobetter::UnsignedBitfield);
        QCOMPARE(type->GetFieldType("tinyBitsRollover"), Protobetter::UnsignedBitfield);

        QCOMPARE((int)myStructInstance.GetUnsignedBitfield("tinyBits"), 3);

        // we expect a rollover here b.c. we set a 5-bit unsigned field to 32
        QCOMPARE((int)myStructInstance.GetUnsignedBitfield("tinyBitsRollover"), 0);
    }
    catch (const std::exception &e)
    {
        QFAIL(e.what());
    }
}

void ProtobetterTest::TestBittylicious()
{
    try
    {
        /*
         * This test does the following:
         *
         * 1) Create vector, lilbitty and bittylicious root types using Protobetter::Dynamic* API
         * 2) Instantiate new DynamicObject of type "Bittylicious"
         * 3) Initialize object with expected values
         * 4) Verify the object's values can be accessed through the DynamicObject interface
         *
         * */

        /* define composite types dynamically at runtime */
        auto vectorRootType = CreateVectorRootType();
        auto lilBittyRootType = CreateLilbittyRootType(vectorRootType);
        auto bittyliciousRootType = CreateBittyliciousRootType(vectorRootType, lilBittyRootType);

        /* verify the reflection API returned types are correct */
        VerifyVectorRootTypeDefinition(vectorRootType);
        VerifyLilBittyRootTypeDefinition(lilBittyRootType);
        VerifyBittyliciousRootTypeDefinition(bittyliciousRootType);

        /* create instances of these composite types */
        Protobetter::DynamicObject myBittylicious(bittyliciousRootType);

        InitBittyliciousWithExpectedValues(lilBittyRootType, vectorRootType, myBittylicious);

        VerifyBittyliciousExpectedValues(lilBittyRootType, vectorRootType, myBittylicious);
    }
    catch (const std::exception &e)
    {
        QFAIL(e.what());
    }
}

void ProtobetterTest::TestBittylicousFromPtypeFile()
{
    try
    {
        /*
         * This test does the following:
         *
         * 1) Get QList<DynamicType> from ptype file
         * 2) Instantiate new DynamicObject of type "Bittylicious"
         * 3) Initialize object with expected values
         * 4) Verify the object's values can be accessed through the DynamicObject interface
         * 4) Create a 2nd new object of type "Bittylicious"
         * 5) Verify that the 2nd created object has 0 for all of it's data
         * 6) Now set the 2nd object's data using the first object's data
         * 7) Verify the 2nd object's values can be accessed through the DynamicObject interface
         * 8) Modify a few fields in the 2nd object and verify them by reading back values
         * 9) Verify that the fields in the first object
         *
         * */

        Protobetter::PrototypeCollection prototypes;

        prototypes.LoadPrototypesFromPType(QString(":/protobetter_test/data/test_c.ptype"));

        QVERIFY(prototypes.Size() == 4);

        QVERIFY(prototypes.HasType("Vector_c"));
        QVERIFY(prototypes.HasType("LilBity_c"));
        QVERIFY(prototypes.HasType("Bittylicious_c"));

        auto dynamicTypes = Protobetter::DynamicTypeCollection::FromPrototypeCollection(prototypes);

        QVERIFY(dynamicTypes.Size() == 4);

        QVERIFY(dynamicTypes.HasType("Vector_c"));
        QVERIFY(dynamicTypes.HasType("LilBity_c"));
        QVERIFY(dynamicTypes.HasType("Bittylicious_c"));

        QCOMPARE((int)dynamicTypes.GetType("Vector_c")->Size(), 13);
        QCOMPARE((int)dynamicTypes.GetType("LilBity_c")->Size(), 53);
        QCOMPARE((int)dynamicTypes.GetType("Bittylicious_c")->Size(), 150);

        auto vectorRootType = dynamicTypes.GetType("Vector_c");
        auto lilBittyRootType = dynamicTypes.GetType("LilBity_c");
        auto bittyliciousRootType = dynamicTypes.GetType("Bittylicious_c");

        /* verify the reflection API returned types are correct */
        VerifyVectorRootTypeDefinition(vectorRootType);
        VerifyLilBittyRootTypeDefinition(lilBittyRootType);
        VerifyBittyliciousRootTypeDefinition(bittyliciousRootType);

        /* create instances of these composite types */
        Protobetter::DynamicObject myBittylicious(bittyliciousRootType);

        InitBittyliciousWithExpectedValues(lilBittyRootType, vectorRootType, myBittylicious);

        VerifyBittyliciousExpectedValues(lilBittyRootType, vectorRootType, myBittylicious);

        Protobetter::DynamicObject myBittylicious2(bittyliciousRootType);

        const char *myBittylicious2Data = myBittylicious2.Data();

        // verify that the 2nd instance's data is all zeroed out...
        for (std::size_t i = 0; i < myBittylicious2.Size(); ++i)
            QCOMPARE(myBittylicious2Data[i], 0);

        myBittylicious2.SetData(myBittylicious.Data());

        // verify you can access all of the data through DynamicObject API and it's all as expected
        VerifyBittyliciousExpectedValues(lilBittyRootType, vectorRootType, myBittylicious2);

        // zero out the entire data buffer for the first instance
        char *zeroedBuffer = new char[bittyliciousRootType->Size()];
        memset(zeroedBuffer, 0, bittyliciousRootType->Size());
        myBittylicious.SetData(zeroedBuffer);

        // verify that it's data was in fact zeroed out without affecting the second instance
        const char *myBittyliciousData = myBittylicious.Data();

        for (std::size_t i = 0; i < myBittylicious.Size(); ++i)
            QCOMPARE(myBittyliciousData[i], 0);

        VerifyBittyliciousExpectedValues(lilBittyRootType, vectorRootType, myBittylicious2);
    }
    catch (const std::exception &e)
    {
        QFAIL(e.what());
    }
}

void ProtobetterTest::TestAgainstProtobetterC()
{
    try
    {
        Bittylicious_c a;

        char buffer[STRUCT_BITTYLICIOUS_C_PACKED_SIZE];

        InitBittylicious_cWithExpectedValues(&a);

        PackBittylicious_c(buffer, &a);

        Protobetter::PrototypeCollection prototypes;

        prototypes.LoadPrototypesFromPType(QString(":/protobetter_test/data/test_c.ptype"));

        QVERIFY(prototypes.Size() == 4);

        QVERIFY(prototypes.HasType("Vector_c"));
        QVERIFY(prototypes.HasType("LilBity_c"));
        QVERIFY(prototypes.HasType("Bittylicious_c"));

        auto dynamicTypes = Protobetter::DynamicTypeCollection::FromPrototypeCollection(prototypes);

        auto rootTypeNames = dynamicTypes.GetRootTypeNames();

        QVERIFY(rootTypeNames.size() == 4);

        QVERIFY(rootTypeNames[0] == "Vector_c");
        QVERIFY(rootTypeNames[1] == "LilBity_c");
        QVERIFY(rootTypeNames[2] == "Bittylicious_c");

        QVERIFY(dynamicTypes.Size() == 4);

        QVERIFY(dynamicTypes.HasType("Vector_c"));
        QVERIFY(dynamicTypes.HasType("LilBity_c"));
        QVERIFY(dynamicTypes.HasType("Bittylicious_c"));

        QCOMPARE((int)dynamicTypes.GetType("Vector_c")->Size(), 13);
        QCOMPARE((int)dynamicTypes.GetType("LilBity_c")->Size(), 53);
        QCOMPARE((int)dynamicTypes.GetType("Bittylicious_c")->Size(), STRUCT_BITTYLICIOUS_C_PACKED_SIZE);

        auto vectorRootType = dynamicTypes.GetType("Vector_c");
        auto lilBittyRootType = dynamicTypes.GetType("LilBity_c");
        auto bittyliciousRootType = dynamicTypes.GetType("Bittylicious_c");

        /* create instances of these composite types */
        Protobetter::DynamicObject myBittylicious(bittyliciousRootType);

        myBittylicious.SetData(buffer);

        VerifyBittyliciousExpectedValues(lilBittyRootType, vectorRootType, myBittylicious);
    }
    catch (const std::exception &e)
    {
        QFAIL(e.what());
    }
}

void ProtobetterTest::TestSuperBityFromPtypeFile()
{
    try
    {
        Protobetter::PrototypeCollection prototypes;

        prototypes.LoadPrototypesFromPType(QString(":/protobetter_test/data/test_c.ptype"));

        QVERIFY(prototypes.Size() == 4);

        QVERIFY(prototypes.HasType("Vector_c"));
        QVERIFY(prototypes.HasType("LilBity_c"));
        QVERIFY(prototypes.HasType("Bittylicious_c"));
        QVERIFY(prototypes.HasType("SuperBity_c"));

        auto dynamicTypes = Protobetter::DynamicTypeCollection::FromPrototypeCollection(prototypes);

        QVERIFY(dynamicTypes.Size() == 4);

        QVERIFY(dynamicTypes.HasType("Vector_c"));
        QVERIFY(dynamicTypes.HasType("LilBity_c"));
        QVERIFY(dynamicTypes.HasType("Bittylicious_c"));
        QVERIFY(dynamicTypes.HasType("SuperBity_c"));

        QCOMPARE(dynamicTypes.GetType("Vector_c")->Size(), 13);
        QCOMPARE(dynamicTypes.GetType("LilBity_c")->Size(), 53);
        QCOMPARE(dynamicTypes.GetType("Bittylicious_c")->Size(), 150);
        QCOMPARE(dynamicTypes.GetType("SuperBity_c")->Size(), 393);

        auto vectorRootType = dynamicTypes.GetType("Vector_c");
        auto lilBittyRootType = dynamicTypes.GetType("LilBity_c");
        auto bittyliciousRootType = dynamicTypes.GetType("Bittylicious_c");
        auto superBityRootType = dynamicTypes.GetType("SuperBity_c");

        /* create instances of these composite types */
        Protobetter::DynamicObject mysuper(superBityRootType);
        Protobetter::DynamicObject mysuper2(superBityRootType);

        /* Set initial values of mysuper */
        mysuper.SetUnsignedBitfield("a", 1);
        mysuper.SetUnsignedBitfield("b", 3214);
        InitVectorWithExpectedValues(mysuper.GetObject(vectorRootType, "c[0]"));
        InitVectorWithExpectedValues(mysuper.GetObject(vectorRootType, "c[1]"));
        mysuper.SetFloat("d", 310.0f);
        InitLilBittyWithExpectedValues(vectorRootType, mysuper.GetObject(lilBittyRootType, "e"));
        InitBittyliciousWithExpectedValues(lilBittyRootType, vectorRootType, mysuper.GetObject(bittyliciousRootType, "f[0]"));
        InitBittyliciousWithExpectedValues(lilBittyRootType, vectorRootType, mysuper.GetObject(bittyliciousRootType, "f[1]"));
        mysuper.SetDouble("g", 54.1234); 
        
        // Verify that 2nd instance data is all zeroed out...
        const char *mysuper2Data = mysuper2.Data();
        for (std::size_t i = 0; i < mysuper2.Size(); ++i)
            QCOMPARE(mysuper2Data[i], 0);

        // Set data of 2nd instance to 1st
        mysuper2.SetData(mysuper.Data());
        QCOMPARE(mysuper.Size(), mysuper2.Size());

        // Verify that 2nd instance data matches 1st
        QCOMPARE(mysuper.GetUnsignedBitfield("a"), mysuper2.GetUnsignedBitfield("a"));
        QCOMPARE(mysuper.GetUnsignedBitfield("b"), mysuper2.GetUnsignedBitfield("b"));

        VerifyVectorExpectedValues(mysuper.GetObject(vectorRootType, "c[0]"));
        VerifyVectorExpectedValues(mysuper.GetObject(vectorRootType, "c[1]"));
        VerifyVectorExpectedValues(mysuper2.GetObject(vectorRootType, "c[0]"));
        VerifyVectorExpectedValues(mysuper2.GetObject(vectorRootType, "c[1]"));

        CompareFloats(mysuper.GetFloat("d"), mysuper2.GetFloat("d"));

        VerifyLilBittyExpectedValues(vectorRootType, mysuper.GetObject(lilBittyRootType, "e"));
        VerifyLilBittyExpectedValues(vectorRootType, mysuper2.GetObject(lilBittyRootType, "e"));

        VerifyBittyliciousExpectedValues(lilBittyRootType, vectorRootType, mysuper.GetObject(bittyliciousRootType, "f[0]"));
        VerifyBittyliciousExpectedValues(lilBittyRootType, vectorRootType, mysuper.GetObject(bittyliciousRootType, "f[1]"));
        VerifyBittyliciousExpectedValues(lilBittyRootType, vectorRootType, mysuper2.GetObject(bittyliciousRootType, "f[0]"));
        VerifyBittyliciousExpectedValues(lilBittyRootType, vectorRootType, mysuper2.GetObject(bittyliciousRootType, "f[1]"));

        CompareDoubles(mysuper.GetDouble("g"), mysuper2.GetDouble("g"));
    }
    catch (const std::exception &e)
    {
        QFAIL(e.what());
    }

}

