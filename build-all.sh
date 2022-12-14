#!/bin/bash
# Build script for sandbox
set echo on

echo "Building everything...."

pushd engine
source build.sh
popd

ERRORLEVEL=$?
if [ $ERRORLEVEL -ne 0 ]
then echo "Error: "$ERRORLEVEL &&  exit
fi

pushd sandbox
source build.sh
popd
ERRORLEVEL=$?
if [ $ERRORLEVEL -ne 0 ]
then echo "Error: "$ERRORLEVEL &&  exit
fi

echo "Built all assemblies succesfully"