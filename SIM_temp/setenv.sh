export TRICKSBN_HOME=$( readlink -e .. )
export QT_INSTALL_DIR=${HOME}/development/Qt/5.12.2/gcc_64
export LD_LIBRARY_PATH=${QT_INSTALL_DIR}/lib

export PATH=${QT_INSTALL_DIR}/bin:${QT_INSTALL_DIR}/lib:${QT_INSTALL_DIR}/include:${PATH}
