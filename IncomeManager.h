#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "OperationsOnDates.h"
#include "AuxiliartMethods.h"
#include "FileWithIncomes.h"
using namespace std;

class IncomeManager{

FileWithIncomes fileWithIncomes;
vector<Income> incomes;
Income addIncomeData();

int  getIncomeId();
public:
Income addIncome();





};
#endif
