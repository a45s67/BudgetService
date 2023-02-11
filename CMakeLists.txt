cmake_minimum_required(VERSION 3.24)
project(BudgetService)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(googletest-main)
include_directories(googletest/include googletest)

add_executable(BudgetService main.cpp BudgetService.cpp Budget.cpp BudgetService.h Budget.h)
target_link_libraries(BudgetService gtest gtest_main)

