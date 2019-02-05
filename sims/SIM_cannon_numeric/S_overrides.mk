# QT_INSTALL_DIR=/users/dspray1/Qt/5.11.1/gcc_64

TRICK_CFLAGS += -DPROTOBETTER_DYNAMIC_LIBSHARED_EXPORT -I../models 
TRICK_CXXFLAGS = -DPROTOBETTER_DYNAMIC_LIBSHARED_EXPORT -I../models

# TRICK_CXXFLAGS += -I/users/dspray1/Qt/5.11.1/gcc_64/include -I/users/dspray1/Qt/5.11.1/gcc_64/include/QtCore -I/users/dspray1/Qt/5.11.1/gcc_64/mkspecs/linux-g++
TRICK_CXXFLAGS += -I${QT_INSTALL_DIR}/include -I${QT_INSTALL_DIR}/include/QtCore -I${QT_INSTALL_DIR}/include/QtNetwork -I${QT_INSTALL_DIR}/mkspecs/linux-g++

TRICK_CXXFLAGS += -I../../extern/protobetter/protobetter_dynamic_lib/include
TRICK_CXXFLAGS += -I../../extern/ccsds_header_lib/include
TRICK_CXXFLAGS += -I../../extern/trick_sbn_lib

TRICK_CFLAGS += -I../../extern/ccsds_header_lib/include



TRICK_CXXFLAGS += -D_REENTRANT -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_CORE_LIB

TRICK_CXXFLAGS += -std=c++0x -fPIC -m64

TRICK_USER_LINK_LIBS += -L${QT_INSTALL_DIR}/lib
TRICK_USER_LINK_LIBS += -lQt5Core -lQt5Network -lpthread -licui18n -licuuc -licudata
