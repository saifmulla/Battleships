# ###############################################
# ///////////// BattleShips \\\\\\\\\\\\\\\\\\\\\\
# This is the primary cmake file for the complete project
# therefore to compile this project this file must located 
# with CMAKE command
# this project was built using cmake v2.8 therefore any version
# beyond 2.8 should be able to compile this file
# ###############################################

CMAKE_MINIMUM_REQUIRED(VERSION 2.8) #minimum cmake version for building project

# project name
PROJECT(Battleships)

SET(PROJECT_NAME Battleships)

# ###############################################
# yes we are building shared libraries
ADD_DEFINITIONS(-DBUILD_SHARED_LIB)
# we are building the code as shared library accordingly we must set a name
SET(SHARED_LIB_NAME battleships)
# executale name
SET(EXECUTABLE_NAME run)
# ###############################################
# Make VC happy and group all the binary outputs,
# also make sure GMock headers will compile in
# all targets.
IF( MSVC )
	SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/)
	SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/)
	SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib/)
	ADD_DEFINITIONS( -D_VARIADIC_MAX=10)
ENDIF( MSVC )

# SET(CMAKE_EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
# set c++11 flags for compiler types
IF ( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
ELSEIF ( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
ELSEIF ( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	# DO something for msc++
ENDIF("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")

SET(CMAKE_EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
# set c++11 flags for compiler types
IF ( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
ELSEIF ( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
ELSEIF ( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	# DO something for msc++
ENDIF("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")

SET(ADDITIONAL_COMP_FLAGS "")

# include header files to be included for sources to compile
INCLUDE_DIRECTORIES(BEFORE 
	${CMAKE_CURRENT_SOURCE_DIR}/include
	)

# ###############################################
# create executable to run the actual code using the shared library
ADD_EXECUTABLE(${EXECUTABLE_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/battleships.cpp)
TARGET_LINK_LIBRARIES(${EXECUTABLE_NAME} ${SHARED_LIB_NAME})

# include the source files to be compiled and generated as shared library
SET(SOURCE_FILES_CPP
	${CMAKE_CURRENT_SOURCE_DIR}/src/PrimaryBoard.C
	${CMAKE_CURRENT_SOURCE_DIR}/src/TrackingBoard.C
	${CMAKE_CURRENT_SOURCE_DIR}/src/BattleShips.C
	${CMAKE_CURRENT_SOURCE_DIR}/src/Validator.C
	)

# ###############################################
# add target to create shared library
ADD_LIBRARY(${SHARED_LIB_NAME} SHARED ${SOURCE_FILES_CPP})

INSTALL(TARGETS ${SHARED_LIB_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
INSTALL(TARGETS ${EXECUTABLE_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
INSTALL(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_PREFIX}/include FILES_MATCHING PATTERN *.H)

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
