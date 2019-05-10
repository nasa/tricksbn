#-------------------------------------------------
#
# Project created by QtCreator 2019-01-26T13:11:26
#
#-------------------------------------------------

QT       += network

QT       -= gui

CONFIG += static

TARGET = trick_sbn_lib
TEMPLATE = lib

DEFINES += TRICK_SBN_LIB_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DEFINES += PROTOBETTER_DYNAMIC_LIB_LIBRARY

SOURCES += \
    qsbn.cpp \
    ../ccsds_header_lib/src/cfe/cfe_sb_msg_id_util.c \
    ../protobetter/protobetter_dynamic_lib/src/protobetterdynamic.cpp \
    trick_ccsds_utils.cpp \
    trick_ccsds_mapping.cpp \
    trick_ccsds_vs_mapping.cpp \
    trick_ccsds_sim_backend.cpp \
    trick_ccsds_memory_manager.cpp

HEADERS += \
    qsbn.h \
    trick_sbn_lib_global.h \
    trick_ccsds_utils.h \
    trick_ccsds_mapping.h \
    trick_ccsds_vs_mapping.h \
    trick_ccsds_sim_backend.h \
    trick_ccsds_memory_manager.h

INCLUDEPATH += \
    ../ccsds_header_lib/include \
    ../ccsds_header_lib/include/cfe \
    ../ccsds_header_lib/include/osal \
    ../protobetter/protobetter_dynamic_lib/include

unix {
    target.path = /usr/lib
    INSTALLS += target
}

isEmpty($$(TRICK_MM)) {
    DEFINES += TRICK_VER
    INCLUDEPATH += \
        $$(TRICK_MM)/include
    unix: LIBS += -L$$(TRICK_MM)/lib64 -ltrick_mm
}
