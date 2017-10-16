#!/bin/bash

set -e
export LCOV_COMMAND="lcov"
export GENHTML_COMMAND="genhtml"
export UNIT_MAIN_DIRECTORY=`pwd`/../..

UNIT_BUILD_DIR=$UNIT_MAIN_DIRECTORY/src/build
UNIT_NAME=SNC
COVERAGE_FILE=Coverage$UNIT_NAME.info
COVERAGE_DIR=Coverage

#Build and run tests
cd $UNIT_MAIN_DIRECTORY/test/ut

source run_test_directory.bash

run_test_directory DLPI './TestDLPI ' 'COVERAGE=1'
run_test_directory LC './TestLC ' 'COVERAGE=1'
run_test_directory MAC './TestMAC ' 'COVERAGE=1'

#Enter a build directory to clean it at new builds
cd $UNIT_MAIN_DIRECTORY/test/ut

#Gather coverage data
printf "\nGather coverage data\n"
$LCOV_COMMAND -c -d $UNIT_MAIN_DIRECTORY/test/ut -o $COVERAGE_FILE

#Extract coverage data of unit
printf "\nExtract coverage data of unit\n"
$LCOV_COMMAND -e $COVERAGE_FILE "*src*" -o $COVERAGE_FILE

#Generate HTML output
printf "\nGenerate HTML output\n"
$GENHTML_COMMAND $COVERAGE_FILE -o $COVERAGE_DIR
