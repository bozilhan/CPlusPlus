REM USAGE : make [BUILD_TYPE=[build | rebuild | full_build | full_rebuild]]  [SOL_TYPE=[Release |Debug | MinSizeRel | RelWithDebInfo ]] [ARC_TYPE=[32 | 64]] [VS_TYPE=VS2012]

set UNIT_NAME=TestLC
set BUILD_FILES_DIR="%cd%\\..\\..\\..\\.BuildFiles"

call "%BUILD_FILES_DIR%\\arg2env.bat" %*
call "%BUILD_FILES_DIR%\\CommonMake.bat" %UNIT_NAME%

