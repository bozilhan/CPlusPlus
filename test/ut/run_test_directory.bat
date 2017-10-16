@echo off
setlocal enabledelayedexpansion

set TEST_DIRECTORY=%1

set TEST_COMMAND=Test%1

set COPY_PATH=..\..\..\..\..\DLPIConfig.ini .

set TEST_MAIN_DIRECTORY=%cd%
set MAXCPUS=12
set ERROR=0
set VS_TYPE=VS2012
set ARC_TYPE=64
set SOL_TYPE=Debug
set BUILD_TYPE=full_rebuild

echo TEST_MAIN_DIRECTORY: %TEST_MAIN_DIRECTORY%
echo TEST_DIRECTORY: %TEST_DIRECTORY%
echo TEST_COMMAND: %TEST_COMMAND%.exe
echo COPY_PATH: %COPY_PATH%

cd %TEST_MAIN_DIRECTORY%\%TEST_DIRECTORY%
set CURRENT_DIR=%cd%
echo CURRENT_DIR: %CURRENT_DIR%

IF "%BUILD_TYPE%" == "build" goto build
IF "%BUILD_TYPE%" == "full_build" goto full_build
IF "%BUILD_TYPE%" == "rebuild" goto rebuild
IF "%BUILD_TYPE%" == "full_rebuild" goto full_rebuild

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

set CMAKE_ARGS=-D CMAKE_BUILD_TYPE:STRING=%SOL_TYPE%
set CMAKE_CMD="Visual Studio 11 Win64"
set EXTENSION=vcxproj
set CXX=VC11x64
set ARCHITECTURE_CMD=x64

echo "command: cmake -Wno-dev --no-warn-unused-cli -G %CMAKE_CMD% %CMAKE_ARGS% ..\"

cmake -Wno-dev --no-warn-unused-cli -G %CMAKE_CMD% %CMAKE_ARGS% ..\
call:all %~1
goto:exit

:all
cd build
call:buildCommand %~1 %TEST_COMMAND%.sln
IF "%errorlevel%" NEQ "0" goto exiterror
IF EXIST Install.%EXTENSION% (
    call:buildCommand build Install.%EXTENSION%
    IF "%errorlevel%" NEQ "0" goto exiterror
)
goto:exit

:buildCommand
msbuild %~2 /verbosity:normal /t:%~1 /p:Configuration=%SOL_TYPE% /p:Platform=%ARCHITECTURE_CMD% /m
call:copyAndRun %TEST_COMMAND%
goto:eof

:copyAndRun
cd %SOL_TYPE%
copy %COPY_PATH%
echo Executing Test Command: %~1.exe
%~1.exe
goto:exit

:exiterror
echo "Exit With Error 1"
set ERROR=1
exit /B 1
goto:eof

:exit
cd %START_DIR%
exit /B %ERROR%
goto:eof