#!/bin/bash

#$1 TagNumber
#$2 SVNRevision
#$3 Path

BUILD_DIRECTORY=$3
PACKAGE_FOLDER="MarlinCentos_"
INI_PATH="../../../../*.ini"
#HTML_PATH="../../../../Form.html"
SVN="_SVN"
BIN="../../../../bin"

cd $BUILD_DIRECTORY

PACKAGE=$PACKAGE_FOLDER"$1$SVN$2"
PACKAGE_ZIP=$PACKAGE.zip

mkdir -p $PACKAGE

cp $INI_PATH $HTML_PATH $PACKAGE/.

cp Marlin $PACKAGE/.

zip -r $PACKAGE_ZIP $PACKAGE/

rm -rf $PACKAGE_FOLDER*/

cd $BIN/

rm -rf *.zip

mv $BUILD_DIRECTORY/$PACKAGE_ZIP .
