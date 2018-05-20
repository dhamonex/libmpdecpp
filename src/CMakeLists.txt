include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(libmpdecimal++_SRC
  decimal.cpp
  decimalprivate.cpp
)

set(libdecimal++_HEADER
  decimal.h
  libmpdecimal_export.h
)

add_library(mpdecimal++ SHARED ${libmpdecimal++_SRC})
add_library(mpdecimal++_static STATIC ${libmpdecimal++_SRC})

target_link_libraries(mpdecimal++ ${LIBMPDEC_LIBRARY})

generate_export_header(mpdecimal++
  BASE_NAME libmpdecimal
)

set_target_properties(mpdecimal++_static PROPERTIES OUTPUT_NAME libmpdecimal++)

install(TARGETS mpdecimal++ DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(TARGETS mpdecimal++_static DESTINATION ${CMAKE_INSTALL_LIBDIR})
