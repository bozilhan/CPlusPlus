@echo off
setlocal enabledelayedexpansion

set UNIT_NAME=%1

set START_DIR=%cd%

set MAXCPUS=12

set ERROR=0

IF "%SOL_TYPE%" == "" set SOL_TYPE=Release
IF "%VS_TYPE%" == "" set VS_TYPE=VS2012
IF "%ARC_TYPE%" == "" set ARC_TYPE=32

IF "%BUILD_TYPE%" == "build" goto build
IF "%BUILD_TYPE%" == "full_build" goto full_build
IF "%BUILD_TYPE%" == "rebuild" goto rebuild
IF "%BUILD_TYPE%" == "full_rebuild" goto full_rebuild
echo Undefined build command, Defined commands are "build,full_build,rebuild,full_rebuild
goto :exiterror

:full_rebuild
rmdir /S/Q build
call:fullBuildCommon rebuild
goto:exit

:full_build
call:fullBuildCommon build
goto:exit

:build
call:all build
goto:exit

:rebuild
call:all rebuild
goto:exit

:fullBuildCommon
mkdir build
cd build

set CMAKE_CMD=""
set CMAKE_ARGS=-D CMAKE_BUILD_TYPE:STRING=%SOL_TYPE%

IF "%VS_TYPE%" == "VS2012" (
	IF "%ARC_TYPE%" == "32" set CMAKE_CMD="Visual Studio 11"
	IF "%ARC_TYPE%" == "64" set CMAKE_CMD="Visual Studio 11 Win64"
	set EXTENSION=vcxproj
	IF "%ARC_TYPE%" == "32" set CXX=VC11
    IF "%ARC_TYPE%" == "64" set CXX=VC11x64
)ELSE IF "%VS_TYPE%" == "VS2013" (
	IF "%ARC_TYPE%" == "32" set CMAKE_CMD="Visual Studio 12 2013"
	IF "%ARC_TYPE%" == "64" set CMAKE_CMD="Visual Studio 12 2013 Win64"
	set EXTENSION=vcxproj
	IF "%ARC_TYPE%" == "32" set CXX=VC11
    IF "%ARC_TYPE%" == "64" set CXX=VC11x64
)

set ARCHITECTURE_CMD=""
IF "%ARC_TYPE%" == "32" set ARCHITECTURE_CMD=Win32
IF "%ARC_TYPE%" == "64" set ARCHITECTURE_CMD=x64

IF %CMAKE_CMD% == "" (
	echo Unsupported Visual Studio version, Supported version is "VS2012" with "32,64" 
	goto :exiterror
)

echo "command: cmake -Wno-dev --no-warn-unused-cli -G %CMAKE_CMD% %CMAKE_ARGS% ..\"

cmake -Wno-dev --no-warn-unused-cli -G %CMAKE_CMD% %CMAKE_ARGS% ..\
call:all %~1
goto:exit

:all
cd build
call:buildCommand %~1 %UNIT_NAME%.sln
IF "%errorlevel%" NEQ "0" goto exiterror
IF EXIST Install.%EXTENSION% (
    call:buildCommand build Install.%EXTENSION%
    IF "%errorlevel%" NEQ "0" goto exiterror
)
goto:exit

:buildCommand
::echo "%1:" %1
::echo %START_DIR%
::echo %MAXCPUS%
::echo %2
::echo %SOL_TYPE%
::echo %ARCHITECTURE_CMD%
::echo %VS_TYPE%

msbuild %~2 /verbosity:normal /t:%~1 /p:Configuration=%SOL_TYPE% /p:Platform=%ARCHITECTURE_CMD% /m

goto:eof

:exiterror
echo "Exit With Error 1"
set ERROR=1
exit /B 1
goto:eof

:exit
cd %START_DIR%
exit /B %ERROR%
goto:eof

