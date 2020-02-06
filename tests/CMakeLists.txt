# Setup testing
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})
# Add test cpp file
add_executable(runGameTests
        GameTests.cpp
        )
# Link test executable against gtest & gtest_main
target_link_libraries(runGameTests gtest gtest_main)

add_test(
        NAME runGameTests
        COMMAND runGameTests
)