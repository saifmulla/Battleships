CMAKE_MINIMUM_REQUIRED(VERSION 2.8) #minimum cmake version for building project

IF(NOT PROJECT_NAME)
	PROJECT_NAME(Battleships)
ENDIF(NOT PROJECT_NAME)

# ###############################################
# yes we are building shared libraries
ADD_DEFINITIONS(-DBUILD_SHARED_LIB)
# we are building the code as shared library accordingly we must set a name
SET(SHARED_LIB_NAME Battleships)
# set c++11 flags by default for the moment
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET(ADDITIONAL_COMP_FLAGS "")

# include header files to be included for sources to compile
INCLUDE_DIRECTORIES(BEFORE 
	${CMAKE_CURRENT_SOURCE_DIR}/include
	)

# include the source files to be compiled and generated as shared library
SET(SOURCE_FILES_CPP
	${CMAKE_CURRENT_SOURCE_DIR}/src/PrimaryBoard.C
	${CMAKE_CURRENT_SOURCE_DIR}/src/TrackingBoard.C
	${CMAKE_CURRENT_SOURCE_DIR}/src/BattleShips.C
	)

# ###############################################
# add target to create shared library
ADD_LIBRARY(${SHARED_LIB_NAME} SHARED ${SOURCE_FILES_CPP})

# ###############################################
# by default unit tests are disabled
# however to enable them simply supply variable
# BUILD_UNIT_TESTS = ON
OPTION( BUILD_UNIT_TESTS "Build unit tests." OFF )

IF (BUILD_UNIT_TESTS)
	SET(BUILD_UNIT_TESTS ${BUILD_UNIT_TESTS})
ENDIF (BUILD_UNIT_TESTS)

#compile gtest framework for unit testing
# ###############################################
# Enable the CMake built in CTest system if unit
# tests are enabled.
IF( BUILD_UNIT_TESTS)
	# IF( APPLE )
	# 	INCLUDE_DIRECTORIES(libraries/CMake/GTest)
	# ENDIF( APPLE )

	ENABLE_TESTING()
	# ###############################################
	# find package pthreads this is required when 
	# unit testing with gtest 
	FIND_PACKAGE(Threads)
	INCLUDE(external/CMakeLists.txt)
	ADD_SUBDIRECTORY(tests)
ENDIF( BUILD_UNIT_TESTS)