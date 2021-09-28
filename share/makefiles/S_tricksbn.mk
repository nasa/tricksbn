# Define setup for compiling Trick sim with telemetry server

# Qt dependencies
TRICK_CXXFLAGS += -I${QT_INSTALL_DIR}/include 
TRICK_CXXFLAGS += -I${QT_INSTALL_DIR}/include/QtCore 
TRICK_CXXFLAGS += -I${QT_INSTALL_DIR}/include/QtNetwork 
TRICK_CXXFLAGS += -I${QT_INSTALL_DIR}/mkspecs/linux-g++

TRICK_CXXFLAGS += -D_REENTRANT -DQT_DEPRECATED_WARNINGS -DQT_CORE_LIB

TRICK_USER_LINK_LIBS += -L${QT_INSTALL_DIR}/lib
TRICK_USER_LINK_LIBS += -lQt5Core -lQt5Network -lpthread -licui18n -licuuc -licudata

# Library dependencies
TRICK_SFLAGS += -I${TRICKSBN_HOME}/share

TRICK_CFLAGS += -I${TRICKSBN_HOME}/share/models

TRICK_CXXFLAGS += -I${TRICKSBN_HOME}/share/models
TRICK_CXXFLAGS += -I${TRICKSBN_HOME}/extern/protobetter/protobetter_dynamic_lib/include
TRICK_CXXFLAGS += -I${TRICKSBN_HOME}/extern/ccsds_header_lib/include
TRICK_CXXFLAGS += -I${TRICKSBN_HOME}/extern/trick_sbn_lib

TRICK_CXXFLAGS += -DPROTOBETTER_DYNAMIC_LIB_OBJECT
TRICK_CXXFLAGS += -std=c++0x -fPIC -m64 -g

# Compile library
TRICK_USER_LINK_LIBS += -L./build/trick_sbn/ -ltrick_sbn_lib

$(S_MAIN): build_tricksbn

QT_PRO = ${TRICKSBN_HOME}/extern/trick_sbn_lib/trick_sbn_lib.pro

build_tricksbn:
	@echo "Building trick_sbn_lib.a"
	mkdir -p build/trick_sbn
	export TRICK_MM=${TRICK_HOME}; cd build/trick_sbn; qmake ${QT_PRO}; make
