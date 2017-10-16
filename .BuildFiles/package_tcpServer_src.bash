#!/bin/bash

#$1 JenkinsBuildNumber
#$2 SVNRevision
#$3 Path

BUILD_DIRECTORY=$3
PACKAGE_FOLDER="MarlinCentos_"
INI_PATH="../../../../*.ini"
SVN="_SVN"
BIN="../../../../bin"

cd $BUILD_DIRECTORY

mkdir -p $PACKAGE_FOLDER"$1$SVN$2"

cp $INI_PATH $PACKAGE_FOLDER"$1$SVN$2"/.

cp Marlin $PACKAGE_FOLDER"$1$SVN$2"/.

zip -r $PACKAGE_FOLDER"$1$SVN$2".zip $PACKAGE_FOLDER"$1$SVN$2"/

rm -rf $PACKAGE_FOLDER*/

cd $BIN/

rm -rf *.zip

mv $BUILD_DIRECTORY/$PACKAGE_FOLDER"$1$SVN$2".zip .