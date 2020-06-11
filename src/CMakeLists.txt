include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(mpdecpp_SRC
  decimal.cpp
  decimalprivate.cpp
  operations.cpp
)

set(mpdecpp_HEADER
  decimal.h
  decimalexceptions.h
  operations.h
  scienfstringconversionformatflag.h
  roundmode.h
  ${CMAKE_CURRENT_BINARY_DIR}/libmpdecpp_export.h
)


add_library(mpdecpp SHARED ${mpdecpp_SRC})
# add_library(mpdecpp_static STATIC ${mpdecpp_SRC})

target_link_libraries(mpdecpp 
  ${LIBMPDEC_LIBRARIES}
  fmt::fmt
)

generate_export_header(mpdecpp
  BASE_NAME libmpdecpp
)

set_property(TARGET mpdecpp PROPERTY VERSION ${libmpdecpp_VERSION})
set_property(TARGET mpdecpp PROPERTY SOVERSION 1)
set_property(TARGET mpdecpp PROPERTY INTERFACE_libmpdecpp_MAJOR_VERSION 1)
set_property(TARGET mpdecpp APPEND PROPERTY
  COMPATIBLE_INTERFACE_STRING libmpdecpp_MAJOR_VERSION
)

# set_target_properties(mpdecpp_static PROPERTIES OUTPUT_NAME mpdecpp)

install(
  TARGETS 
    mpdecpp 
  EXPORT
    LibmpdecppTargets
  DESTINATION 
    ${LIBMPDECPP_LIB_DIR}
)
# install(TARGETS mpdecpp_static DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
  FILES
    ${mpdecpp_HEADER}
  DESTINATION
    ${LIBMPDECPP_INC_DIR}
  COMPONENT
    Devel
)
