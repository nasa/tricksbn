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

        bitfieldCollection->AddField("id", 4);
        bitfieldCollection->Finalize();

        type->AddField(bitfieldCollection);

        type->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField("x", 4));
        type->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField("y", 4));
        type->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField("z", 4));

        type->Finalize();

        return type;
    }

    Protobetter::FieldCollection::Ptr CreateLilbittyRootType(Protobetter::FieldCollection::Ptr vectorRootType)
    {
        auto type = Protobetter::FieldCollection::CreateNewRootType("LilBitty_c");

        // float
        type->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField("a", 4));

        auto bitfieldCollection = Protobetter::BitfieldCollection::CreateNewBitfieldCollection(4);

        bitfieldCollection->AddField("b", 31);
        bitfieldCollection->AddField("c", 1);
        bitfieldCollection->Finalize();

        type->AddField(bitfieldCollection);

        bitfieldCollection = Protobetter::BitfieldCollection::CreateNewBitfieldCollection(4);

        bitfieldCollection->AddField("d", 4);
        bitfieldCollection->Finalize();

        type->AddField(bitfieldCollection);

        type->AddField(Protobetter::FieldCollection::CreateFieldFromRootType("e[0]", vectorRootType, true));
        type->AddField(Protobetter::FieldCollection::CreateFieldFromRootType("e[1]", vectorRootType, true));
        type->AddField(Protobetter::FieldCollection::CreateFieldFromRootType("e[2]", vectorRootType, true));

        bitfieldCollection = Protobetter::BitfieldCollection::CreateNewBitfieldCollection(2);

        bitfieldCollection->AddField("f", 16);
        bitfieldCollection->Finalize();

        type->AddField(bitfieldCollection);

        type->Finalize();

        return type;
    }

    Protobetter::FieldCollection::Ptr CreateBittyliciousRootType(Protobetter::FieldCollection::Ptr vectorRootType, Protobetter::FieldCollection::Ptr lilBittyRootType)
    {
        auto type = Protobetter::FieldCollection::CreateNewRootType("Bittylicious_c");

        type->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField("header", 16));
        type->AddField(qSharedPointerCast<Protobetter::DynamicType>(Protobetter::PrimitiveField::CreateNewPrimitiveField("a", 8)));

        type->AddField(Protobetter::FieldCollection::CreateFieldFromRootType("b[0]", lilBittyRootType, true));
        type->AddField(Protobetter::FieldCollection::CreateFieldFromRootType("b[1]", lilBittyRootType, true));

        type->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField("c[0]", 2));
        type->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField("c[1]", 2));
        type->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField("c[2]", 2));

        type->AddField(Protobetter::FieldCollection::CreateFieldFromRootType("d", vectorRootType, true));

        auto bitfieldCollection = Protobetter::BitfieldCollection::CreateNewBitfieldCollection(1);
        bitfieldCollection->AddField("e", 3);
        bitfieldCollection->Finalize();

        type->AddField(bitfieldCollection);

        type->Finalize();

        return type;
    }

    void InitVectorWithExpectedValues(Protobetter::DynamicObject::Ptr vector)
    {
        vector->SetUnsignedBitfield("id", 15);
        vector->SetFloat("x", 1.2345f);
        vector->SetFloat("y", 97865.4321f);
        vector->SetFloat("z", 867.5309f);
    }

    void VerifyVectorExpectedValues(Protobetter::DynamicObject::Ptr vector)
    {
        QCOMPARE(vector->GetUnsignedBitfield("id"), 15);
        CompareFloats(vector->GetFloat("x"), 1.2345f);
        CompareFloats(vector->GetFloat("y"), 97865.4321f);
        CompareFloats(vector->GetFloat("z"), 867.5309f);
    }

    void InitLilBittyWithExpectedValues(Protobetter::DynamicType::Ptr vectorRootType, Protobetter::DynamicObject::Ptr lilbitty)
    {
        lilbitty->SetFloat("a", 123.123f);
        lilbitty->SetUnsignedBitfield("b", 134217728);
        lilbitty->SetUnsignedBitfield("c", 1);
        lilbitty->SetUnsignedBitfield("d", 7);

        InitVectorWithExpectedValues(lilbitty->GetObject(vectorRootType, "e[0]"));
        InitVectorWithExpectedValues(lilbitty->GetObject(vectorRootType, "e[1]"));
        InitVectorWithExpectedValues(lilbitty->GetObject(vectorRootType, "e[2]"));

        lilbitty->SetSignedBitfield("f", 25867);
    }

    void VerifyLilBittyExpectedValues(Protobetter::DynamicType::Ptr vectorRootType, Protobetter::DynamicObject::Ptr lilbitty)
    {
        CompareFloats(lilbitty->GetFloat("a"), 123.123f);
        QCOMPARE(lilbitty->GetUnsignedBitfield("b"), 134217728);
        QCOMPARE(lilbitty->GetUnsignedBitfield("c"), 1);
        QCOMPARE(lilbitty->GetUnsignedBitfield("d"), 7);

        VerifyVectorExpectedValues(lilbitty->GetObject(vectorRootType, "e[0]"));
        VerifyVectorExpectedValues(lilbitty->GetObject(vectorRootType, "e[1]"));
        VerifyVectorExpectedValues(lilbitty->GetObject(vectorRootType, "e[2]"));

        QCOMPARE(lilbitty->GetSignedBitfield("f"), 25867);
    }

    void InitBittyliciousWithExpectedValues(Protobetter::DynamicType::Ptr lilBittyRootType, Protobetter::DynamicType::Ptr vectorRootType, Protobetter::DynamicObject::Ptr bittylicious)
    {
        bittylicious->SetByteArray("header", "The quick brown");
        bittylicious->SetDouble("a", 42.123456l);

        InitLilBittyWithExpectedValues(vectorRootType, bittylicious->GetObject(lilBittyRootType, "b[0]"));
        InitLilBittyWithExpectedValues(vectorRootType, bittylicious->GetObject(lilBittyRootType, "b[1]"));

        bittylicious->SetInt16("c[0]", 12);
        bittylicious->SetInt16("c[1]", 9);
        bittylicious->SetInt16("c[2]", 6);

        InitVectorWithExpectedValues(bittylicious->GetObject(vectorRootType, "d"));

        bittylicious->SetSignedBitfield("e", 3);
    }

    void VerifyBittyliciousExpectedValues(Protobetter::DynamicType::Ptr lilBittyRootType, Protobetter::DynamicType::Ptr vectorRootType, Protobetter::DynamicObject::Ptr bittylicious)
    {
        QVERIFY(strcmp(bittylicious->GetByteArray("header"), "The quick brown") == 0);

        CompareDoubles(bittylicious->GetDouble("a"), 42.123456l);

        VerifyLilBittyExpectedValues(vectorRootType, bittylicious->GetObject(lilBittyRootType, "b[0]"));
        VerifyLilBittyExpectedValues(vectorRootType, bittylicious->GetObject(lilBittyRootType, "b[1]"));

        QCOMPARE(bittylicious->GetInt16("c[0]"), 12);
        QCOMPARE(bittylicious->GetInt16("c[1]"), 9);
        QCOMPARE(bittylicious->GetInt16("c[2]"), 6);

        VerifyVectorExpectedValues(bittylicious->GetObject(vectorRootType, "d"));

        QCOMPARE(bittylicious->GetSignedBitfield("e"), 3);
    }
}

void ProtobetterTest::TestPrototypeJsonDeserialization()
{
    int value = 42;

    QVERIFY(value > 41);

    Protobetter::PrototypeCollection prototypes;

    prototypes.LoadPrototypesFromFile(QString(":/protobetter_test/data/test_c.ptype"));

    QVERIFY(prototypes.HasType("Vector_c"));
    QVERIFY(prototypes.HasType("LilBity_c"));
    QVERIFY(prototypes.HasType("Bittylicious_c"));

    // TODO: finish this test case...
}

void ProtobetterTest::TestDynamicAPI()
{
    try
    {
        /* Define a DynamicType at runtime */
        Protobetter::FieldCollection::Ptr type = Protobetter::FieldCollection::CreateNewRootType("LilBitty_c");

        // float
        type->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField("fieldA", 4));

        // double
        type->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField("fieldB", 8));

        auto vectorRootType = CreateVectorRootType();

        // type: "Vector"
        type->AddField(Protobetter::FieldCollection::CreateFieldFromRootType("vectorField[0]", vectorRootType, true));

        auto bitfieldCollection = Protobetter::BitfieldCollection::CreateNewBitfieldCollection(4);

        bitfieldCollection->AddField("bitfieldA", 3);
        bitfieldCollection->AddField("bitfieldB", 2);
        bitfieldCollection->AddField("bitfieldC", 5);
        bitfieldCollection->Finalize();

        // bitfield collection
        type->AddField(bitfieldCollection);

        // int32
        type->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField("fieldC", 4));

        auto lilBittyRootType = CreateLilbittyRootType(vectorRootType);

        type->AddField(Protobetter::FieldCollection::CreateFieldFromRootType("myLilBitty", lilBittyRootType, true));

        // uint32
        type->AddField(Protobetter::PrimitiveField::CreateNewPrimitiveField("fieldD", 4));

        bitfieldCollection = Protobetter::BitfieldCollection::CreateNewBitfieldCollection(2);

        bitfieldCollection->AddField("bitfieldD", 11);
        bitfieldCollection->AddField("bitfieldE", 4);
        bitfieldCollection->AddField("bitfieldF", 1);
        bitfieldCollection->Finalize();

        // bitfield collection
        type->AddField(bitfieldCollection);

        bitfieldCollection = Protobetter::BitfieldCollection::CreateNewBitfieldCollection(1);

        bitfieldCollection->AddField("tinyBits", 2);
        bitfieldCollection->AddField("tinyBitsRollover", 5);
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

        QCOMPARE(myStructInstance.GetUnsignedBitfield("bitfieldA"), 3);
        QCOMPARE(myStructInstance.GetUnsignedBitfield("bitfieldB"), 1);
        QCOMPARE(myStructInstance.GetSignedBitfield("bitfieldC"), -5);
        QCOMPARE(myStructInstance.GetSignedBitfield("bitfieldD"), -1024);
        QCOMPARE(myStructInstance.GetSignedBitfield("bitfieldE"), 7);
        QCOMPARE(myStructInstance.GetUnsignedBitfield("bitfieldF"), 1);

        CompareFloats(myStructInstance.GetFloat("fieldA"), 123.456f);
        CompareDoubles(myStructInstance.GetDouble("fieldB"), 9876.5432f);

        QCOMPARE(myStructInstance.GetInt32("fieldC"), -421234);
        QCOMPARE(myStructInstance.GetUInt32("fieldD"), 678910);

        CompareFloats(myStructInstance.GetFloat("vectorField[0].x"), 42.0f);
        CompareFloats(myStructInstance.GetFloat("vectorField[0].y"), 43.0f);
        CompareFloats(myStructInstance.GetFloat("vectorField[0].z"), 44.0f);

        QCOMPARE(myStructInstance.GetSignedBitfield("myLilBitty.f"), -32768);

        {
            // we should be able to get an object referencing the same underlying data
            // and delete it without destroying the data since the reference doesn't own it
            auto myLilBitty = myStructInstance.GetObject(lilBittyRootType, "myLilBitty");

            CompareFloats(myLilBitty->GetSignedBitfield("f"), -32768);
        }

        CompareFloats(myStructInstance.GetFloat("myLilBitty.e[0].x"), 0.0f);
        CompareFloats(myStructInstance.GetFloat("myLilBitty.e[0].y"), 0.0f);
        CompareFloats(myStructInstance.GetFloat("myLilBitty.e[0].z"), 0.0f);

        {
            auto e1x = myStructInstance.GetObject(vectorRootType, "myLilBitty.e[1]");

            CompareFloats(e1x->GetFloat("x"), -987.0f);
            CompareFloats(e1x->GetFloat("y"), -654.0f);
            CompareFloats(e1x->GetFloat("z"), -321.0f);
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
            myStructInstance.SetObject("myLilBitty.e[2]", vectorRootType, tempVector);
        }

        // this should now be equal to what the temp vector's data was before...
        CompareFloats(myStructInstance.GetFloat("myLilBitty.e[2].x"), 12.34f);
        CompareFloats(myStructInstance.GetFloat("myLilBitty.e[2].y"), 45.67f);
        CompareFloats(myStructInstance.GetFloat("myLilBitty.e[2].z"), 89.1011f);

        QCOMPARE(myStructInstance.GetUnsignedBitfield("tinyBits"), 3);

        // we expect a rollover here b.c. we set a 5-bit unsigned field to 32
        QCOMPARE(myStructInstance.GetUnsignedBitfield("tinyBitsRollover"), 0);
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

        /* create instances of these composite types */
        Protobetter::DynamicObject::Ptr myBittylicious = Protobetter::DynamicObject::Ptr(new Protobetter::DynamicObject(bittyliciousRootType));

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

        prototypes.LoadPrototypesFromFile(QString(":/protobetter_test/data/test_c.ptype"));

        QVERIFY(prototypes.Size() == 3);

        QVERIFY(prototypes.HasType("Vector_c"));
        QVERIFY(prototypes.HasType("LilBity_c"));
        QVERIFY(prototypes.HasType("Bittylicious_c"));

        auto dynamicTypes = Protobetter::DynamicTypeCollection::FromPrototypeCollection(prototypes);

        QVERIFY(dynamicTypes.Size() == 3);

        QVERIFY(dynamicTypes.HasType("Vector_c"));
        QVERIFY(dynamicTypes.HasType("LilBity_c"));
        QVERIFY(dynamicTypes.HasType("Bittylicious_c"));

        QCOMPARE(dynamicTypes.GetType("Vector_c")->Size(), 13);
        QCOMPARE(dynamicTypes.GetType("LilBity_c")->Size(), 53);
        QCOMPARE(dynamicTypes.GetType("Bittylicious_c")->Size(), 150);

        auto vectorRootType = dynamicTypes.GetType("Vector_c");
        auto lilBittyRootType = dynamicTypes.GetType("LilBity_c");
        auto bittyliciousRootType = dynamicTypes.GetType("Bittylicious_c");

        /* create instances of these composite types */
        auto myBittylicious = Protobetter::DynamicObject::Ptr(new Protobetter::DynamicObject(bittyliciousRootType));

        InitBittyliciousWithExpectedValues(lilBittyRootType, vectorRootType, myBittylicious);

        VerifyBittyliciousExpectedValues(lilBittyRootType, vectorRootType, myBittylicious);

        auto myBittylicious2 = Protobetter::DynamicObject::Ptr(new Protobetter::DynamicObject(bittyliciousRootType));

        const char *myBittylicious2Data = myBittylicious2->Data();

        // verify that the 2nd instance's data is all zeroed out...
        for (int i = 0; i < myBittylicious2->Size(); ++i)
            QCOMPARE(myBittylicious2Data[i], 0);

        myBittylicious2->SetData(myBittylicious->Data());

        // verify you can access all of the data through DynamicObject API and it's all as expected
        VerifyBittyliciousExpectedValues(lilBittyRootType, vectorRootType, myBittylicious2);

        // zero out the entire data buffer for the first instance
        char *zeroedBuffer = new char[bittyliciousRootType->Size()];
        memset(zeroedBuffer, 0, bittyliciousRootType->Size());
        myBittylicious->SetData(zeroedBuffer);

        // verify that it's data was in fact zeroed out without affecting the second instance
        const char *myBittyliciousData = myBittylicious->Data();

        for (int i = 0; i < myBittylicious->Size(); ++i)
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
        Bittylicious_c a, b;

        char buffer[STRUCT_BITTYLICIOUS_C_PACKED_SIZE];

        InitBittylicious_cWithExpectedValues(&a);

        PackBittylicious_c(buffer, &a);

        Protobetter::PrototypeCollection prototypes;

        prototypes.LoadPrototypesFromFile(QString(":/protobetter_test/data/test_c.ptype"));

        QVERIFY(prototypes.Size() == 3);

        QVERIFY(prototypes.HasType("Vector_c"));
        QVERIFY(prototypes.HasType("LilBity_c"));
        QVERIFY(prototypes.HasType("Bittylicious_c"));

        auto dynamicTypes = Protobetter::DynamicTypeCollection::FromPrototypeCollection(prototypes);

        QVERIFY(dynamicTypes.Size() == 3);

        QVERIFY(dynamicTypes.HasType("Vector_c"));
        QVERIFY(dynamicTypes.HasType("LilBity_c"));
        QVERIFY(dynamicTypes.HasType("Bittylicious_c"));

        QCOMPARE(dynamicTypes.GetType("Vector_c")->Size(), 13);
        QCOMPARE(dynamicTypes.GetType("LilBity_c")->Size(), 53);
        QCOMPARE(dynamicTypes.GetType("Bittylicious_c")->Size(), 150);

        auto vectorRootType = dynamicTypes.GetType("Vector_c");
        auto lilBittyRootType = dynamicTypes.GetType("LilBity_c");
        auto bittyliciousRootType = dynamicTypes.GetType("Bittylicious_c");

        /* create instances of these composite types */
        auto myBittylicious = Protobetter::DynamicObject::Ptr(new Protobetter::DynamicObject(bittyliciousRootType));

        myBittylicious->SetData(buffer);

        VerifyBittyliciousExpectedValues(lilBittyRootType, vectorRootType, myBittylicious);
    }
    catch (const std::exception &e)
    {
        QFAIL(e.what());
    }
}

