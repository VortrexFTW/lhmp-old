cmake_minimum_required(VERSION 3.6)

set(CMAKE_BUILD_TYPE "Release" CACHE STRING "")
set(SQUIRREL_UNICODE "" CACHE STRING "Determine if Squirrel uses Unicode")

project(ezsquirrel C CXX)

if(CMAKE_COMPILER_IS_GNUCXX)
	#set(SQ_FLAGS "-fno-exceptions -fno-strict-aliasing -Wall -Wextra -pedantic -Wcast-qual") #No mo warnings ;-;!
	if(CMAKE_BUILD_TYPE STREQUAL "Release")
		set(SQ_FLAGS "${SQ_FLAGS} -O3")
	elseif(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
		set(SQ_FLAGS "${SQ_FLAGS} -O3 -g")
	elseif(CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
		set(SQ_FLAGS "${SQ_FLAGS} -Os")
	elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
		set(SQ_FLAGS "${SQ_FLAGS} -pg -pie -gstabs -g3 -Og")
	endif()
    add_definitions("${SQ_FLAGS}")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti -std=c++0x")
elseif(MSVC)
	set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

if(MSVC)
	add_definitions("-D_CRT_SECURE_NO_WARNINGS")
endif()

if($<${SQUIRREL_UNICODE}:ON>)
	add_definitions("-DSQUNICODE")
endif()

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  add_definitions("-D_SQ64")
endif()

if(NOT DEFINED INSTALL_BIN_DIR)
	set(INSTALL_BIN_DIR "bin")
endif()
if(NOT DEFINED INSTALL_LIB_DIR)
	set(INSTALL_LIB_DIR "lib")
endif()

add_subdirectory(squirrel)
add_subdirectory(sqstdlib)