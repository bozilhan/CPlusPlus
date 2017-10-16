set UNIT_NAME=MyBS
set BUILD_FILES_DIR="%cd%\\..\\.BuildFiles"
set SOURCE_DIR="%cd%\\."

call "%BUILD_FILES_DIR%\\arg2env.bat" %*
call "%BUILD_FILES_DIR%\\CommonMake.bat" %UNIT_NAME%
