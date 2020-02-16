include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(mpdecpp_SRC
  decimal.cpp
  decimalprivate.cpp
)

set(mpdecpp_HEADER
  decimal.h
  libmpdecimal_export.h
)

add_library(mpdecpp SHARED ${mpdecpp_SRC})
add_library(mpdecpp_static STATIC ${mpdecpp_SRC})

target_link_libraries(mpdecpp 
  ${LIBMPDEC_LIBRARIES}
)

generate_export_header(mpdecpp
  BASE_NAME libmpdecpp
)

set_target_properties(mpdecpp_static PROPERTIES OUTPUT_NAME mpdecpp)

install(TARGETS mpdecpp DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(TARGETS mpdecpp_static DESTINATION ${CMAKE_INSTALL_LIBDIR})
