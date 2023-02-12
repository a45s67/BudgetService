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


int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
//int main(){
//
//    std::cout<<"Hello!\n";
//    return 0;
//}
