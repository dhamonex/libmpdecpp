project(libmpdecimal++)

cmake_minimum_required(VERSION 2.8)
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_SOURCE_DIR}/cmake/Modules/")

ADD_DEFINITIONS("-DBOOST_LOG_DYN_LINK -std=c++11 -Wall")
find_package(LibMPDecimal REQUIRED)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include(GNUInstallDirs)
include(GenerateExportHeader)

enable_testing()

include_directories(${LIBMPDEC_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})

add_subdirectory(src)
add_subdirectory(test)
