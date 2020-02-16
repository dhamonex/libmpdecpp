include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_BINARY_DIR}/src)

add_executable(init_test init_test.cpp)
target_link_libraries(init_test mpdecpp)
