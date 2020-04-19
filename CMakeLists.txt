if (POLICY CMP0048)
  cmake_policy(SET CMP0048 NEW)
endif (POLICY CMP0048)

project(libmpdecpp VERSION 0.0.1 LANGUAGES CXX)

cmake_minimum_required(VERSION 3.10)
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build all automatic test cases." OFF)

find_package(LibMPDecimal REQUIRED)
find_package(fmt REQUIRED)
find_package(Boost REQUIRED)
find_package(Doxygen OPTIONAL_COMPONENTS dot)

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
  add_subdirectory(doc)
endif()

