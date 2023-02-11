//
// Created by Fish on 2/11/2023.
//

#ifndef BUDGETSERVICE_BUDGET_H
#define BUDGETSERVICE_BUDGET_H

#include <vector>
#include <string>

std::chrono::system_clock::time_point GetDate(int year, int month, int day);

class Budget {
public:
    Budget(std::string ym, int amount){
        YearMonth = ym;
        Amount = amount;
    }
    std::string YearMonth;
    int Amount;
};

class IBudgetRepo {
public:
    virtual std::vector<Budget> GetAll() = 0;
};

class BudgetRepo : public IBudgetRepo {
public:
    BudgetRepo(std::vector<Budget> budgets);
    std::vector<Budget> GetAll() override;

private:
    std::vector<Budget> budgets;
};

#endif //BUDGETSERVICE_BUDGET_H
