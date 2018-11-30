
TRICK_CFLAGS += -I../models
TRICK_CXXFLAGS += -I../models

TRICK_CXXFLAGS += -I/users/dspray1/Qt/5.11.1/gcc_64/include -I/users/dspray1/Qt/5.11.1/gcc_64/include/QtCore

TRICK_CXXFLAGS += -Wall -D_REENTRANT -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_CORE_LIB

TRICK_CXXFLAGS += -std=c++0x -fPIC -m64 -Wl,-O1 

# TODO: this doesn't work - it keeps finding the system version of Qt5Core first I think...
#TRICK_USER_LINK_LIBS = "-L/users/dspray1/Qt/5.11.1/gcc_64/lib"
#TRICK_USER_LINK_LIBS += -lQt5Core -lpthread

TRICK_CXXFLAGS += -I../../extern/protobetter/protobetter_dynamic_lib/include
