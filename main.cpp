#include <iostream>
#include <vector>
#include <chrono>
#include "BudgetService.h"
#include "gtest/gtest.h"

TEST(BudgetService, TestBudgetInOneMonth1) {
    std::vector<Budget> budgets = {Budget("202301", 31)};
    BudgetRepo repo(budgets);
    BudgetService service(&repo);

    auto end = std::chrono::system_clock::now();
    double budget = service.Query(GetDate(2023, 1, 1), GetDate(2023, 1, 1));

    ASSERT_EQ(1, budget);
}
TEST(BudgetService, TestBudgetInOneMonth2) {
    std::vector<Budget> budgets = {Budget("202301", 31)};
    BudgetRepo repo(budgets);
    BudgetService service(&repo);

    auto end = std::chrono::system_clock::now();
    double budget = service.Query(GetDate(2023, 1, 2), GetDate(2023, 1, 2));

    ASSERT_EQ(1, budget);
}

TEST(BudgetService, TestBudgetInOneMonth3) {
    std::vector<Budget> budgets = {Budget("202303", 31000)};
    BudgetRepo repo(budgets);
    BudgetService service(&repo);

    auto end = std::chrono::system_clock::now();
    double budget = service.Query(GetDate(2023, 3, 1), GetDate(2023, 3, 31));

    ASSERT_EQ(31000, budget);
}

TEST(BudgetService, TestCrossMontgh) {
    std::vector<Budget> budgets = {Budget("202303", 31000)};
    budgets.push_back(Budget("202304",3000));
    budgets.push_back(Budget("202305",310));
    budgets.push_back(Budget("202306",30));
    BudgetRepo repo(budgets);
    BudgetService service(&repo);

    auto end = std::chrono::system_clock::now();
    double budget = service.Query(GetDate(2023, 3, 10),
                                  GetDate(2023, 6, 18));

    ASSERT_EQ(22000+3000+310+18, budget);
}


int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
//int main(){
//
//    std::cout<<"Hello!\n";
//    return 0;
//}
