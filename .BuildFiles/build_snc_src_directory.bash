#!/bin/bash
set -e
export SNC_MAIN_DIRECTORY=`pwd`
printf "SNC_MAIN_DIRECTORY: %s\n" $SNC_MAIN_DIRECTORY
function build_snc_src_directory ( )
{
        SRC_DIRECTORY=$1
        BUILD_PARAMETERS=$2
        cd  $SNC_MAIN_DIRECTORY
        printf "SRC_DIRECTORY: %s \n" $SRC_DIRECTORY
        cd $SRC_DIRECTORY
		make full_clean
        make full_build ${BUILD_PARAMETERS}
}

