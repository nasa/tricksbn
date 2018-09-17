QT -= gui
QT += testlib

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    test/include \
    include

SOURCES += \
    src/protobetterdynamic.cpp \
    test/src/protobetter_test.cpp \
    test/src/test_main.cpp

HEADERS += \
    include/protobetterdynamic.h \
    test/include/protobetter_test.h

RESOURCES += \
    test/protobetter_test.qrc
