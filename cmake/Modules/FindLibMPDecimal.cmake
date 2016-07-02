# - Try to find LibMPDec
# Once done this will define
#  LibMPDecimal_FOUND - System has LibMPDec
#  LIBMPDEC_INCLUDE_DIRS - The LibMPDec include directories
#  LIBMPDEC_LIBRARIES - The libraries needed to use LibMPDec
#  LIBMPDEC_DEFINITIONS - Compiler switches required for using LibMPDec

if (LIBMPDEC_LIBRARY AND LIBMPDEC_LIBRARY)
   # in cache already
   set(LibMPDecimal_FIND_QUIETLY TRUE)
endif ()

find_path(LIBMPDEC_INCLUDE_DIR 
  NAMES
    mpdecimal.h
  HINTS 
    ${PC_LIBMPDEC_INCLUDEDIR} 
    ${PC_LIBMPDEC_INCLUDE_DIRS}
    ${PC_LIBMPDEC_INSTALL_DIR}/include
)

find_library(LIBMPDEC_LIBRARY 
  NAMES 
    mpdec
  HINTS 
    ${PC_LIBMPDEC_LIBDIR} 
    ${PC_LIBMPDEC_LIBRARY_DIRS} 
    ${PC_LIBMPDEC_INSTALL_DIR}/lib64/
    ${PC_LIBMPDEC_INSTALL_DIR}/lib/
)

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set LIBMPDEC_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(LibMPDecimal REQUIRED_VARS LIBMPDEC_LIBRARY LIBMPDEC_INCLUDE_DIR VERSION_VAR LIBMPDEC_VERSION_STRING)

mark_as_advanced(LIBMPDEC_INCLUDE_DIR LIBMPDEC_LIBRARY )

IF(LibMPDecimal_FOUND)
  set(LIBMPDEC_LIBRARIES ${LIBMPDEC_LIBRARY} )
  set(LIBMPDEC_INCLUDE_DIRS ${LIBMPDEC_INCLUDE_DIR} )
ENDIF()
