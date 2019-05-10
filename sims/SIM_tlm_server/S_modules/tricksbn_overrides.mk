TRICK_CXXFLAGS += -I${QT_INSTALL_DIR}/include -I${QT_INSTALL_DIR}/include/QtCore -I${QT_INSTALL_DIR}/include/QtNetwork -I${QT_INSTALL_DIR}/mkspecs/linux-g++

TRICK_CXXFLAGS += -DPROTOBETTER_DYNAMIC_LIB_OBJECT

TRICK_CXXFLAGS += -I${TRICK_SBN_LIB_DIR}/protobetter/protobetter_dynamic_lib/include
TRICK_CXXFLAGS += -I${TRICK_SBN_LIB_DIR}/ccsds_header_lib/include
TRICK_CXXFLAGS += -I${TRICK_SBN_LIB_DIR}/trick_sbn_lib

TRICK_CFLAGS += -I${TRICK_SBN_LIB_DIR}/ccsds_header_lib/include

TRICK_CXXFLAGS += -D_REENTRANT -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_CORE_LIB

TRICK_CXXFLAGS += -std=c++0x -fPIC -m64

TRICK_USER_LINK_LIBS += -L${QT_INSTALL_DIR}/lib
TRICK_USER_LINK_LIBS += -lQt5Core -lQt5Network -lpthread -licui18n -licuuc -licudata

TRICK_USER_LINK_LIBS += -L./build/trick_sbn/ -ltrick_sbn_lib

$(S_MAIN): build_tricksbn

QT_PRO = ${TRICK_SBN_LIB_DIR}/trick_sbn_lib/trick_sbn_lib.pro

build_tricksbn:
	@echo "Building trick_sbn_lib.a"
	mkdir -p build/trick_sbn
	export TRICK_MM=${TRICK_HOME}; cd build/trick_sbn; qmake ${QT_PRO}; make
