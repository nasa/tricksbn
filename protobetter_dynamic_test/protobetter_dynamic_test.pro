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
    ../protobetter_dynamic_lib/include \
    include

SOURCES += \
    src/protobetter_generated.c \
    src/protobetter_test.cpp \
    src/test_main.cpp

HEADERS += \
    include/protobetter_generated.h \
    ../protobetter_dynamic_lib/include/protobetterdynamic.h \
    include/protobetter_test.h

RESOURCES += \
    protobetter_test.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../protobetter_dynamic_lib/release/ -lprotobetter_dynamic_lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../protobetter_dynamic_lib/debug/ -lprotobetter_dynamic_lib
else:unix: LIBS += -L$$OUT_PWD/../protobetter_dynamic_lib/ -lprotobetter_dynamic_lib

INCLUDEPATH += $$PWD/../protobetter_dynamic_lib/include
DEPENDPATH += $$PWD/../protobetter_dynamic_lib
