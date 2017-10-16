cmake_minimum_required(VERSION 2.8)
project(SNC)

add_definitions(-D_WIN32_WINNT=0x0600)

include_directories(./src)
include_directories(D:/local/boost)
link_directories (D:/local/boost/lib64)


file(GLOB_RECURSE mylist "src/*.cpp" "src/*.h")

macro(GroupSources curdir)
 file (GLOB children RELATIVE ${PROJECT_SOURCE_DIR}/${curdir} ${PROJECT_SOURCE_DIR}/${curdir}/*)
 foreach (child ${children})
  if (IS_DIRECTORY ${PROJECT_SOURCE_DIR}/${curdir}/${child})
    GroupSources (${curdir}/${child})
  else()
   string(REPLACE "/" "\\" groupname ${curdir})
   source_group (${groupname} FILES ${PROJECT_SOURCE_DIR}/${curdir}/${child})
  endif()
 endforeach()
endmacro()

GroupSources(src)
 
add_executable(SNC ${mylist})
target_link_libraries(SNC)

add_custom_command(TARGET SNC POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/SNC.ini ${CMAKE_BINARY_DIR})
add_custom_command(TARGET SNC POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/Log.ini ${CMAKE_BINARY_DIR})
add_custom_command(TARGET SNC POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/DLPIConfig.ini ${CMAKE_BINARY_DIR})


