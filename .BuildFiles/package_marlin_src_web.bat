::%1 TagNumber
::%2 SVNRevision
::%3 Path

@echo off

set BUILD_DIRECTORY=%3

echo "BUILD_DIRECTORY: " %BUILD_DIRECTORY%

set BUILD_FILES_FOLDER="..\..\..\.BuildFiles"

echo "BUILD_FILES_FOLDER: " %BUILD_FILES_FOLDER%

set PACKAGE_FOLDER="MarlinVC11WithWeb_"
set SVN=""
set INI_PATH="..\..\..\*.ini"
::set HTML_PATH="..\..\..\*.html"
set BIN="..\..\..\bin"
set WEB="C:\opt\bin\.m2\repository\mantdl\marlin-web-service\"%1"\marlin-web-service-"%1"-dist.zip"

IF NOT %2 == "" set SVN="_SVN"

set PACKAGE=%PACKAGE_FOLDER%"%1"%SVN%"%2"

cd %BUILD_DIRECTORY%

del /s %PACKAGE_FOLDER%*.zip

mkdir \a %PACKAGE%

copy /b %HTML_PATH% %PACKAGE%

copy /b %INI_PATH% %PACKAGE%

copy /b %WEB% %PACKAGE%

copy Marlin.exe %PACKAGE%

set PACKAGE_ZIP=%PACKAGE%".zip"

7z a %PACKAGE_ZIP% %BUILD_DIRECTORY%\%PACKAGE%

for /d %%a in (%PACKAGE_FOLDER%*) do rmdir /s /q %%a

cd %BIN%

del /s *.zip

move %BUILD_DIRECTORY%\%PACKAGE_ZIP% %cd%