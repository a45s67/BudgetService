//
// Created by Fish on 2/11/2023.
//

#ifndef BUDGETSERVICE_BUDGETSERVICE_H
#define BUDGETSERVICE_BUDGETSERVICE_H

#include <chrono>
#include <memory>
#include "Budget.h"

class BudgetService {
public:
    BudgetService(IBudgetRepo *budget_repo);

    double Query(std::chrono::time_point<std::chrono::system_clock> start,
                 std::chrono::time_point<std::chrono::system_clock> end);

private:
    //std::string GetYearMonth(std::chrono::time_point<std::chrono::system_clock> date);

    IBudgetRepo *budget_repo;

    double GetBudgetOfDate(std::chrono::time_point<std::chrono::system_clock> point);

    int GetBudgetOfMonth(std::string year_month_str);

    int GetDayOfMonth(std::chrono::time_point<std::chrono::system_clock> time_point);
};

#endif //BUDGETSERVICE_BUDGETSERVICE_H
