#!/bin/bash

set -e

SOURCE_DIR=${G4SOURCE_DIR:-~/geant4_source}
BUILD_DIR=${G4BUILD_DIR:-~/geant4_build}
INSTALL_DIR=${G4INSTALL_DIR:-~/geant4_install}
DATA_DIR=${G4DATA_DIR:-~/geant4_data}

echo "Build Geant4: source dir = ${SOURCE_DIR}, build dir = ${BUILD_DIR}, install dir = ${INSTALL_DIR}, data dir = ${DATA_DIR}"

touch ${BUILD_DIR} ${INSTALL_DIR} ${DATA_DIR}

cd ${BUILD_DIR}
cmake ${SOURCE_DIR} \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=${INSTALL_DIR} \
    -DGEANT4_BUILD_MULTITHREADED=ON \
    -DGEANT4_INSTALL_DATA=ON \
    -DGEANT4_INSTALL_DATADIR=${DATA_DIR} \
    -DGEANT4_USE_QT=ON \
    -DGEANT4_USE_GDML=ON \
    -DGEANT4_BUILD_TESTS=ON

make install

#make tests
