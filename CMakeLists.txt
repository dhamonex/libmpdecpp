if (POLICY CMP0048)
  cmake_policy(SET CMP0048 NEW)
endif (POLICY CMP0048)

project(libmpdecpp VERSION 0.9.0 LANGUAGES CXX)

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

include(CMakePackageConfigHelpers)

set(LIBMPDECPP_CMAKE_DIR ${CMAKE_INSTALL_LIBDIR}/cmake/libmpdecpp CACHE STRING
    "Installation directory for cmake files, relative to ${CMAKE_INSTALL_PREFIX}.")
      
set(LIBMPDECPP_LIB_DIR ${CMAKE_INSTALL_LIBDIR} CACHE STRING
    "Installation directory for libraries, relative to ${CMAKE_INSTALL_PREFIX}.")

set(LIBMPDECPP_INC_DIR ${CMAKE_INSTALL_INCLUDEDIR}/mpdecpp/ CACHE STRING
    "Installation directory for include files, relative to ${CMAKE_INSTALL_PREFIX}.")


set(project_config ${PROJECT_BINARY_DIR}/cmake/LibmpdecppConfig.cmake)
set(version_config ${PROJECT_BINARY_DIR}/cmake/LibmpdecppConfigVersion.cmake)
set(targets_export_name LibmpdecppTargets)
set (INSTALL_TARGETS mpdecpp)

add_subdirectory(src)

target_include_directories(mpdecpp PUBLIC
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)


write_basic_package_version_file(
  ${version_config}
  VERSION ${libmpdecpp_VERSION}
  COMPATIBILITY AnyNewerVersion
)

export(TARGETS ${INSTALL_TARGETS} NAMESPACE Libmpdecpp::
  FILE ${PROJECT_BINARY_DIR}/${targets_export_name}.cmake)

configure_package_config_file(cmake/LibmpdecppConfig.cmake.in
  ${project_config}
  INSTALL_DESTINATION ${LIBMPDECPP_CMAKE_DIR}
)


install(EXPORT ${targets_export_name}
  FILE
    LibmpdecppTargets.cmake
  NAMESPACE
    Libmpdecpp::
  DESTINATION
    ${LIBMPDECPP_CMAKE_DIR}
)

install(
  FILES
    ${project_config}
    ${version_config}
  DESTINATION
    ${LIBMPDECPP_CMAKE_DIR}
  COMPONENT
    Devel
)

if(BUILD_TESTS)
  find_package(GTest REQUIRED)
  find_package(GMock REQUIRED)
  add_subdirectory(test)
  add_subdirectory(doc)
endif()

