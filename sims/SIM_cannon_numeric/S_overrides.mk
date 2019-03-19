# QT_INSTALL_DIR=/users/dspray1/Qt/5.11.1/gcc_64

TRICK_CFLAGS += -I../models 
TRICK_CXXFLAGS = -I../models

include ${TRICK_SBN_SIM_DIR}/S_modules/tricksbn_overrides.mk
