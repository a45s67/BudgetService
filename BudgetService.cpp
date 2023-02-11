//
// Created by Fish on 2/11/2023.
//

#include "BudgetService.h"

BudgetService::BudgetService(IBudgetRepo *budget_repo) : budget_repo(budget_repo) {

}

double BudgetService::Query(std::chrono::time_point<std::chrono::system_clock> start,
                            std::chrono::time_point<std::chrono::system_clock> end) {
    std::chrono::year_month_day start_ymd{std::chrono::floor<std::chrono::days>(start)};
    std::chrono::year_month_day end_ymd{std::chrono::floor<std::chrono::days>(end)};

    auto budgets = this->budget_repo->GetAll();
    //for (auto budget: budgets) {
    //    if (budget.YearMonth ==)
    //}

    return 1.0;
}

std::string BudgetService::GetYearMonth(std::chrono::time_point<std::chrono::system_clock> date) {
    auto 
    //int month_count = std::chrono::duration_cast<std::chrono::month>(duration).count();
    auto month_count = std::chrono::duration_cast<std::chrono::month>(duration);
}
