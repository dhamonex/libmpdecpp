include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_BINARY_DIR}/src)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${GMOCK_INCLUDE_DIRS})

include(GoogleTest)

add_executable(mpdecpp_test mpdecpp_test.cpp)
target_link_libraries(mpdecpp_test mpdecpp GTest::GTest GTest::Main GMock::GMock GMock::Main)
gtest_add_tests(TARGET mpdecpp_test)
gtest_discover_tests(mpdecpp_test)


add_executable(mpdecpp_uninit_throw_test mpdecpp_uninit_throw_test.cpp)
target_link_libraries(mpdecpp_uninit_throw_test mpdecpp GTest::GTest GTest::Main GMock::GMock GMock::Main)
gtest_add_tests(TARGET mpdecpp_uninit_throw_test)
gtest_discover_tests(mpdecpp_uninit_throw_test)
