#ifndef PROTOBETTER_TEST_H
#define PROTOBETTER_TEST_H

#include <QtTest>

#include "protobetterdynamic.h"

class ProtobetterTest : public QObject
{
    Q_OBJECT

private slots:

    void TestPrototypeJsonDeserialization();
    void TestXTCEDeserialization();
    void TestDynamicAPI();
    void TestBittylicious();
    void TestBittylicousFromPtypeFile();
    void TestAgainstProtobetterC();
};

#endif // PROTOBETTER_TEST_H
