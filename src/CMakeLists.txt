include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(libmpdecimal++_SRC
  decimal.cpp
  decimalprivate.cpp
)

set(libdecimal++_HEADER
  decimal.h
  libmpdecimal_export.h
)

add_library(libmpdecimal++ SHARED ${libmpdecimal++_SRC})
add_library(libmpdecimal++_static STATIC ${libmpdecimal++_SRC})

target_link_libraries(libmpdecimal++ ${LIBMPDEC_LIBRARY})

generate_export_header(libmpdecimal++
  BASE_NAME libmpdecimal
)

set_target_properties(libmpdecimal++_static PROPERTIES OUTPUT_NAME libmpdecimal++)

install(TARGETS libmpdecimal++ DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(TARGETS libmpdecimal++_static DESTINATION ${CMAKE_INSTALL_LIBDIR})
