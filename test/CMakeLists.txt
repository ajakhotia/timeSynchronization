find_package(GTest 1.8.0 REQUIRED)

add_executable(timeSynchronizationTest timeSynchronizationTest.cpp)
target_link_libraries(timeSynchronizationTest PRIVATE timeSynchronization GTest::GTest GTest::Main)
gtest_discover_tests(timeSynchronizationTest)