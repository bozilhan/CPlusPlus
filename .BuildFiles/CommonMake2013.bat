@echo off
setlocal enabledelayedexpansion

set UNIT_NAME=%1
set START_DIR=%cd%
set MAXCPUS=12
set ERROR=0

IF "%SOL_TYPE%" == "" set SOL_TYPE=Debug
IF "%VS_TYPE%" == "" set VS_TYPE=VS2013
IF "%ARC_TYPE%" == "" set ARC_TYPE=64

IF "%BUILD_TYPE%" == "build" goto build
IF "%BUILD_TYPE%" == "full_build" goto full_build 
IF "%BUILD_TYPE%" == "rebuild" goto rebuild 
IF "%BUILD_TYPE%" == "full_rebuild" goto full_rebuild 
echo Undefined build command. Defined commands are "build, full_build, rebuild, full_rebuild"
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

set CMAKE_CMD="Visual Studio 12 Win64"
set CXX=VC12x64
set CMAKE_ARGS=-D CMAKE_BUILD_TYPE:STRING=%SOL_TYPE%
set ARCHITECTURE_CMD=x64
set EXTENSION=vcxproj

echo "command: cmake -Wno-dev --no-warn-unused-cli -G %CMAKE_CMD% %CMAKE_ARGS% ..\"

cmake -Wno-dev --no-warn-unused-cli -G %CMAKE_CMD% %CMAKE_ARGS% ..\
call:all %~1
goto:exit

:all
cd build
call:buildCommand %~1 %UNIT_NAME%.sln
IF "%errorlevel%" NEQ "0" goto exiterror
IF EXIST Install.%EXTENSION%
(
	call:buildCommand build Install.%EXTENSION%
	IF "%errorlevel%" NEQ "0" goto exiterror
)
goto:exit

:buildCommand
msbuild %~2 /verbosity:normal /t:%~1 /p:Configuration=%SOL_TYPE% /p:Platform=%ARCHITECTURE_CMD% /m
goto:eof

:exiterror
echo "Exit with error 1"
set ERROR=1
exit /B 1
goto:eof

:exit
cd %START_DIR%
exit /B %ERROR%
goto:eof
