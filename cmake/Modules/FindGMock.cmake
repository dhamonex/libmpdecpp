# Locate the Google C++ Mocking Framework.

# (This file is almost an identical copy of the original FindGTest.cmake file,
#  feel free to use it as it is or modify it for your own needs.)

# file Copyright.txt or https://cmake.org/licensing for details.

#[=======================================================================[.rst:
FindGMock
---------

Locate the Google C++ GMock Testing Framework.

Imported targets
^^^^^^^^^^^^^^^^

This module defines the following :prop_tgt:`IMPORTED` targets:

``GMock::GMock``
  The Google Test ``gmock`` library, if found; adds Thread::Thread
  automatically
``GMock::Main``
  The Google Test ``gmock_main`` library, if found


Result variables
^^^^^^^^^^^^^^^^

This module will set the following variables in your project:

``GMOCK_FOUND``
  Found the Google Testing framework
``GMOCK_INCLUDE_DIRS``
  the directory containing the Google Test headers

The library variables below are set as normal variables.  These
contain debug/optimized keywords when a debugging library is found.

``GMOCK_LIBRARIES``
  The Google Test ``gmock`` library; note it also requires linking
  with an appropriate thread library
``GMOCK_MAIN_LIBRARIES``
  The Google Test ``gmock_main`` library
``GMOCK_BOTH_LIBRARIES``
  Both ``gmock`` and ``gmock_main``

Cache variables
^^^^^^^^^^^^^^^

The following cache variables may also be set:

``GTEST_ROOT``
  The root directory of the Google Test installation (may also be
  set as an environment variable)
``GTEST_MSVC_SEARCH``
  If compiling with MSVC, this variable can be set to ``MT`` or
  ``MD`` (the default) to enable searching a GTest build tree


Example usage
^^^^^^^^^^^^^

::

    enable_testing()
    find_package(GMock REQUIRED)

    add_executable(foo foo.cc)
    target_link_libraries(foo GMock::GMock GMock::Main)

    add_test(AllTestsInFoo foo)


Deeper integration with CTest
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

See :module:`GoogleTest` for information on the :command:`gtest_add_tests`
and :command:`gtest_discover_tests` commands.
#]=======================================================================]

# include(${CMAKE_CURRENT_LIST_DIR}/GoogleTest.cmake)

function(__gmock_append_debugs _endvar _library)
    if(${_library} AND ${_library}_DEBUG)
        set(_output optimized ${${_library}} debug ${${_library}_DEBUG})
    else()
        set(_output ${${_library}})
    endif()
    set(${_endvar} ${_output} PARENT_SCOPE)
endfunction()

function(__gmock_find_library _name)
    find_library(${_name}
        NAMES ${ARGN}
        HINTS
            ENV GTEST_ROOT
            ${GTEST_ROOT}
        PATH_SUFFIXES ${_gmock_libpath_suffixes}
    )
    mark_as_advanced(${_name})
endfunction()

macro(__mock_determine_windows_library_type _var)
    if(EXISTS "${${_var}}")
        file(TO_NATIVE_PATH "${${_var}}" _lib_path)
        get_filename_component(_name "${${_var}}" NAME_WE)
        file(STRINGS "${${_var}}" _match REGEX "${_name}\\.dll" LIMIT_COUNT 1)
        if(NOT _match STREQUAL "")
            set(${_var}_TYPE SHARED PARENT_SCOPE)
        else()
            set(${_var}_TYPE UNKNOWN PARENT_SCOPE)
        endif()
        return()
    endif()
endmacro()

function(__gmock_determine_library_type _var)
    if(WIN32)
        # For now, at least, only Windows really needs to know the library type
        __gmock_determine_windows_library_type(${_var})
        __gmock_determine_windows_library_type(${_var}_RELEASE)
        __gmock_determine_windows_library_type(${_var}_DEBUG)
    endif()
    # If we get here, no determination was made from the above checks
    set(${_var}_TYPE UNKNOWN PARENT_SCOPE)
endfunction()

function(__gmock_import_library _target _var _config)
    if(_config)
        set(_config_suffix "_${_config}")
    else()
        set(_config_suffix "")
    endif()

    set(_lib "${${_var}${_config_suffix}}")
    if(EXISTS "${_lib}")
        if(_config)
            set_property(TARGET ${_target} APPEND PROPERTY
                IMPORTED_CONFIGURATIONS ${_config})
        endif()
        set_target_properties(${_target} PROPERTIES
            IMPORTED_LINK_INTERFACE_LANGUAGES${_config_suffix} "CXX")
        if(WIN32 AND ${_var}_TYPE STREQUAL SHARED)
            set_target_properties(${_target} PROPERTIES
                IMPORTED_IMPLIB${_config_suffix} "${_lib}")
        else()
            set_target_properties(${_target} PROPERTIES
                IMPORTED_LOCATION${_config_suffix} "${_lib}")
        endif()
    endif()
endfunction()

#

if(NOT DEFINED GMOCK_MSVC_SEARCH)
    set(GMOCK_MSVC_SEARCH MD)
endif()

set(_gmock_libpath_suffixes lib)
if(MSVC)
    if(GMOCK_MSVC_SEARCH STREQUAL "MD")
        list(APPEND _gmock_libpath_suffixes
            msvc/gtest-md/Debug
            msvc/gtest-md/Release
            msvc/x64/Debug
            msvc/x64/Release
            msvc/2010/gtest-md/Win32-Debug
            msvc/2010/gtest-md/Win32-Release
            msvc/2010/gtest-md/x64-Debug
            msvc/2010/gtest-md/x64-Release
            )
    elseif(GMOCK_MSVC_SEARCH STREQUAL "MT")
        list(APPEND _gtest_libpath_suffixes
            msvc/gtest/Debug
            msvc/gtest/Release
            msvc/x64/Debug
            msvc/x64/Release
            msvc/2010/gtest/Win32-Debug
            msvc/2010/gtest/Win32-Release
            msvc/2010/gtest/x64-Debug
            msvc/2010/gtest/x64-Release
            )
    endif()
endif()


find_path(GMOCK_INCLUDE_DIR gmock/gmock.h
    HINTS
        $ENV{GTEST_ROOT}/include
        ${GTEST_ROOT}/include
)
mark_as_advanced(GMOCK_INCLUDE_DIR)

if(MSVC AND GMOCK_MSVC_SEARCH STREQUAL "MD")
    # The provided /MD project files for Google Test add -md suffixes to the
    # library names.
    __gmock_find_library(GMOCK_LIBRARY            gmock-md  gmock)
    __gmock_find_library(GMOCK_LIBRARY_DEBUG      gmock-mdd gmockd)
    __gmock_find_library(GMOCK_MAIN_LIBRARY       gmock_main-md  gmock_main)
    __gmock_find_library(GMOCK_MAIN_LIBRARY_DEBUG gmock_main-mdd gmock_maind)
else()
    __gmock_find_library(GMOCK_LIBRARY            gmock)
    __gmock_find_library(GMOCK_LIBRARY_DEBUG      gmockd)
    __gmock_find_library(GMOCK_MAIN_LIBRARY       gmock_main)
    __gmock_find_library(GMOCK_MAIN_LIBRARY_DEBUG gmock_maind)
endif()

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GMock DEFAULT_MSG GMOCK_LIBRARY GMOCK_INCLUDE_DIR GMOCK_MAIN_LIBRARY)

if(GMOCK_FOUND)
    set(GMOCK_INCLUDE_DIRS ${GMOCK_INCLUDE_DIR})
    __gmock_append_debugs(GMOCK_LIBRARIES      GMOCK_LIBRARY)
    __gmock_append_debugs(GMOCK_MAIN_LIBRARIES GMOCK_MAIN_LIBRARY)
    set(GMOCK_BOTH_LIBRARIES ${GMOCK_LIBRARIES} ${GMOCK_MAIN_LIBRARIES})

    find_package(Threads QUIET)

    if(NOT TARGET GMock::GMock)
        __gmock_determine_library_type(GMOCK_LIBRARY)
        add_library(GMock::GMock ${GMOCK_LIBRARY_TYPE} IMPORTED)
        if(TARGET Threads::Threads)
            set_target_properties(GMock::GMock PROPERTIES
                INTERFACE_LINK_LIBRARIES Threads::Threads)
        endif()
        if(GTEST_LIBRARY_TYPE STREQUAL "SHARED")
            set_target_properties(GMock::GMock PROPERTIES
                INTERFACE_COMPILE_DEFINITIONS "GMOCK_LINKED_AS_SHARED_LIBRARY=1")
        endif()
        if(GMOCK_INCLUDE_DIRS)
            set_target_properties(GMock::GMock PROPERTIES
                INTERFACE_INCLUDE_DIRECTORIES "${GMOCK_INCLUDE_DIRS}")
        endif()
        __gmock_import_library(GMock::GMock GMOCK_LIBRARY "")
        __gmock_import_library(GMock::GMock GMOCK_LIBRARY "RELEASE")
        __gmock_import_library(GMock::GMock GMOCK_LIBRARY "DEBUG")
    endif()
    if(NOT TARGET GMock::Main)
        __gmock_determine_library_type(GMOCK_MAIN_LIBRARY)
        add_library(GMock::Main ${GMOCK_MAIN_LIBRARY_TYPE} IMPORTED)
        set_target_properties(GMock::Main PROPERTIES
            INTERFACE_LINK_LIBRARIES "GMock::GMock")
        __gmock_import_library(GMock::Main GMOCK_MAIN_LIBRARY "")
        __gmock_import_library(GMock::Main GMOCK_MAIN_LIBRARY "RELEASE")
        __gmock_import_library(GMock::Main GMOCK_MAIN_LIBRARY "DEBUG")
    endif()
endif()

