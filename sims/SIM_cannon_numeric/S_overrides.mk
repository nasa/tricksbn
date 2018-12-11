
TRICK_CFLAGS += -I../models
TRICK_CXXFLAGS = -I../models

TRICK_CXXFLAGS += -I/users/dspray1/Qt/5.11.1/gcc_64/include -I/users/dspray1/Qt/5.11.1/gcc_64/include/QtCore -I/users/dspray1/Qt/5.11.1/gcc_64/mkspecs/linux-g++

TRICK_CXXFLAGS += -I../../extern/protobetter/protobetter_dynamic_lib/include

TRICK_CXXFLAGS += -D_REENTRANT -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_CORE_LIB

TRICK_CXXFLAGS += -std=c++0x -fPIC -m64

TRICK_USER_LINK_LIBS += -L/users/dspray1/Qt/5.11.1/gcc_64/lib -lQt5Core -lpthread -licui18n -licuuc -licudata
