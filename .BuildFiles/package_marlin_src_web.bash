#!/bin/bash

#$1 TagNumber
#$2 SVNRevision
#$3 Path

SVN=""
BUILD_DIRECTORY=$3
PACKAGE_FOLDER="MarlinCentosWithWeb_"
INI_PATH="../../*.ini"
#HTML_PATH="../../Form.html"
BIN="../../bin"
WEB="../../MarlinHMI/WebService/target/marlin-web-service-$1-dist.zip"

if [ -n "$2" ];then
	SVN="_SVN"
fi

cd $BUILD_DIRECTORY

PACKAGE=$PACKAGE_FOLDER"$1$SVN$2"
PACKAGE_ZIP=$PACKAGE.zip

mkdir -p $PACKAGE

cp $INI_PATH $HTML_PATH $WEB $PACKAGE/.

cp Marlin $PACKAGE/.

zip -r $PACKAGE_ZIP $PACKAGE/

rm -rf $PACKAGE_FOLDER*/

cd $BIN/

rm -rf *.zip

mv $BUILD_DIRECTORY/$PACKAGE_ZIP .