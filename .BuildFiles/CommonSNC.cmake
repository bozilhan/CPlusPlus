
IF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	INCLUDE(${NC_MAIN_DIRECTORY}/.BuildFiles/VCXProjFormatter.cmake)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")

IF (NOT ${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    ADD_DEFINITIONS(-std=c++1y)
	ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)
ELSE(NOT ${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	ADD_DEFINITIONS(-D_WIN32_WINNT=0x0600)
	ADD_DEFINITIONS(-D_XKEYCHECK_H)
	ADD_DEFINITIONS(/MP)
ENDIF (NOT ${CMAKE_SYSTEM_NAME} MATCHES "Windows")

SET(BOOST_INCLUDEDIR $ENV{BOOST_INCLUDE})

#SET(Boost_DEBUG ON)

SET( Boost_USE_STATIC_LIBS ON )

FIND_PACKAGE(Boost)

MESSAGE("Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
MESSAGE("Boost_LIBRARY_DIRS: ${Boost_LIBRARY_DIRS}")

IF( ENABLE_COVERAGE )
    SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage" )
    SET( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage" )
    SET( GCOV_LIB gcov )
ENDIF( ENABLE_COVERAGE )

SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

ADD_DEFINITIONS(-DPTHREADS -D_REENTRANT)

SET(NC_SOURCE_DIR ${NC_MAIN_DIRECTORY}/src)

SET(NC_TEST_DIR ${NC_MAIN_DIRECTORY}/test)

IF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	ADD_DEFINITIONS(-DLITTLE_ENDIAN)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")

FILE(GLOB_RECURSE SOURCE1 
	${PROJECT_SOURCE_DIR}/*.cpp
	${PROJECT_SOURCE_DIR}/*.h
)

FILE(GLOB_RECURSE REMOVE_SOURCE1 
	${PROJECT_SOURCE_DIR}/build/*.cpp
	${PROJECT_SOURCE_DIR}/build/*.h
)

IF(REMOVE_SOURCE1)
	list(REMOVE_ITEM SOURCE1 ${REMOVE_SOURCE1})
ENDIF(REMOVE_SOURCE1)

FILE(GLOB_RECURSE SOURCE2
	${NC_SOURCE_DIR}/SNCApp.cpp
	${NC_SOURCE_DIR}/SNCApp.h
	${NC_SOURCE_DIR}/DLPI/*.cpp
	${NC_SOURCE_DIR}/DLPI/*.h
	${NC_SOURCE_DIR}/ICD/*.cpp
	${NC_SOURCE_DIR}/ICD/*.h
	${NC_SOURCE_DIR}/LC/*.cpp
	${NC_SOURCE_DIR}/LC/*.h
	${NC_SOURCE_DIR}/MAC/*.cpp
	${NC_SOURCE_DIR}/MAC/*.h
	${NC_SOURCE_DIR}/PI/*.cpp
	${NC_SOURCE_DIR}/PI/*.h
	${NC_SOURCE_DIR}/Mediator/*.cpp
	${NC_SOURCE_DIR}/Mediator/*.h
	${NC_SOURCE_DIR}/SignalHandling/*.cpp
	${NC_SOURCE_DIR}/SignalHandling/*.h
	${NC_SOURCE_DIR}/Util/*.cpp
	${NC_SOURCE_DIR}/Util/*.h
)

#MESSAGE("#######################################################################")
#MESSAGE(" # Source3 List")
#FOREACH(CPPFILE ${SOURCE1})
#MESSAGE("${CPPFILE}")
#ENDFOREACH(CPPFILE)
#FOREACH(CPPFILE ${SOURCE2})
#MESSAGE("${CPPFILE}")
#ENDFOREACH(CPPFILE)
#MESSAGE("##################################################################")

IF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	GroupSources(${NC_MAIN_DIRECTORY} src)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")

INCLUDE_DIRECTORIES(
	${PROJECT_SOURCE_DIR}
	${NC_SOURCE_DIR}
	${NC_TEST_DIR}
	${Boost_INCLUDE_DIRS}
	$ENV{CPPUNIT_INCLUDE}
)

LINK_DIRECTORIES(
    $ENV{CPPUNIT_LIB}
	${Boost_LIBRARY_DIRS}
)

ADD_EXECUTABLE(${UNIT_NAME} ${SOURCE1} ${SOURCE2} ${NC_MAIN_DIRECTORY}/.BuildFiles/TestRunnerSNC.cpp)

IF(NOT ${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	SET(NSL nsl)
	SET(PTHREAD pthread)
ENDIF(NOT ${CMAKE_SYSTEM_NAME} MATCHES "Windows")

IF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	IF(${CMAKE_BUILD_TYPE} MATCHES "Release")
		SET (BOOST_ABI_TAG ${_boost_RELEASE_ABI_TAG})
	ELSE(${CMAKE_BUILD_TYPE} MATCHES "Release")
		SET (BOOST_ABI_TAG ${_boost_DEBUG_ABI_TAG})
		SET (CPPUNIT_SUFFIX d)
	ENDIF(${CMAKE_BUILD_TYPE} MATCHES "Release")
	
    SET (BOOST_PREFIX lib)
    SET (BOOST_SUFFIX ${_boost_COMPILER}${_boost_MULTITHREADED}${BOOST_ABI_TAG}-${Boost_LIB_VERSION})
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")

SET(LINK_LIBRARIES_VAR
    ${BOOST_PREFIX}boost_thread${BOOST_SUFFIX}
    ${BOOST_PREFIX}boost_system${BOOST_SUFFIX}
    ${BOOST_PREFIX}boost_filesystem${BOOST_SUFFIX}
    ${BOOST_PREFIX}boost_date_time${BOOST_SUFFIX}
    ${BOOST_PREFIX}boost_log_setup${BOOST_SUFFIX}
    ${BOOST_PREFIX}boost_log${BOOST_SUFFIX}
    ${BOOST_PREFIX}boost_iostreams${BOOST_SUFFIX}
    ${BOOST_PREFIX}boost_program_options${BOOST_SUFFIX}
    #${NSL}
    #${PTHREAD}
    ${GCOV_LIB}
    cppunit${CPPUNIT_SUFFIX}
)

TARGET_LINK_LIBRARIES(
    ${UNIT_NAME}
	${LINK_LIBRARIES_VAR}
)

INSTALL(TARGETS ${UNIT_NAME} DESTINATION build)