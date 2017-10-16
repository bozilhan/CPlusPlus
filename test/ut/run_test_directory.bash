#!/bin/bash
set -e
export TEST_MAIN_DIRECTORY=`pwd`
printf "TEST_MAIN_DIRECTORY: %s\n" $TEST_MAIN_DIRECTORY
function run_test_directory ( )
{
        TEST_DIRECTORY=$1
        TEST_COMMAND=$2
        BUILD_PARAMETERS=$3
        INI_PATH=../../../../*.ini
				
        cd  $TEST_MAIN_DIRECTORY
        printf "TEST_DIRECTORY: %s \n" $TEST_DIRECTORY
		printf "INI_PATH: %s \n" $INI_PATH
        cd $TEST_DIRECTORY
		make full_clean
        make full_build ${BUILD_PARAMETERS}
        cd build
		cp $INI_PATH .
        echo "Executing Test Command : $TEST_COMMAND"
        $TEST_COMMAND
}

