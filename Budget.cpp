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

std::string GetYearMonthStr(std::chrono::time_point<std::chrono::system_clock> time_point) {
    //https://stackoverflow.com/a/15958113/12764484
    auto dp = round<std::chrono::days>(time_point);
    std::chrono::year_month_day ymd{dp};
    if (unsigned(ymd.month())<10){
        return std::to_string(int(ymd.year())) + "0" +
               std::to_string(unsigned(ymd.month()));
    }
    return std::to_string(int(ymd.year())) +
           std::to_string(unsigned(ymd.month()));
}

BudgetRepo::BudgetRepo(std::vector<Budget> budgets) : budgets(budgets) {}

std::vector<Budget> BudgetRepo::GetAll() {
    return this->budgets;
}
