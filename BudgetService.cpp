//
// Created by Fish on 2/11/2023.
//

#include <iostream>
#include "BudgetService.h"

BudgetService::BudgetService(IBudgetRepo *budget_repo) : budget_repo(budget_repo) {

}

double BudgetService::Query(std::chrono::time_point<std::chrono::system_clock> start,
                            std::chrono::time_point<std::chrono::system_clock> end) {

    auto budgets = this->budget_repo->GetAll();
    double total = 0;
    std::cout<<"hello";
    while (start <= end) {
        total += GetBudgetOfDate(start);
        start += std::chrono::days(1);
    }
    return total;
}

double BudgetService::GetBudgetOfDate(std::chrono::time_point<std::chrono::system_clock> point) {
    int month_budget = GetBudgetOfMonth(GetYearMonthStr(point));
    int day_of_month = GetDayOfMonth(point);

    return 1.0 * month_budget/day_of_month;
}

int BudgetService::GetBudgetOfMonth(std::string year_month_str) {
    auto budgets = this->budget_repo->GetAll();
    for (auto budget: budgets) {
        if (budget.YearMonth == year_month_str) {
            return budget.Amount;
        }
    }
    return 0;
}

int BudgetService::GetDayOfMonth(std::chrono::time_point<std::chrono::system_clock> time_point) {

    auto dp = floor<std::chrono::days>(time_point);
    std::chrono::year_month_day ymd{dp};

    std::chrono::year_month_day_last ym_last_day{ymd.year(), std::chrono::month_day_last(ymd.month())};
    return unsigned(ym_last_day.day());
}

