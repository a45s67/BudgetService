//
// Created by Fish on 2/11/2023.
//

#include "Budget.h"

std::chrono::system_clock::time_point GetDate(int year, int month, int day) {
    std::tm tm = { /* .tm_sec  = */ 0,
            /* .tm_min  = */ 0,
            /* .tm_hour = */ 0,
            /* .tm_mday = */ day,
            /* .tm_mon  = */ (month) - 1,
            /* .tm_year = */ (year) - 1900,
    };
    tm.tm_isdst = -1; // Use DST value from local time zone
    auto tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));
    return tp;
}

BudgetRepo::BudgetRepo(std::vector<Budget> budgets) : budgets(budgets) {}

std::vector<Budget> BudgetRepo::GetAll() {
    return this->budgets;
}
