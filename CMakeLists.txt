project(libmpdecpp)

cmake_minimum_required(VERSION 3.10)
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build all automatic test cases." OFF)

find_package(LibMPDecimal REQUIRED)

find_package(Boost REQUIRED)

include(GNUInstallDirs)
include(GenerateExportHeader)

enable_testing()

include_directories(${LIBMPDEC_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})

add_subdirectory(src)

if(BUILD_TESTS)
  find_package(GTest REQUIRED)
  find_package(GMock REQUIRED)
  add_subdirectory(test)
endif()
