#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>
#include "Expense.h"
#include "Markup.h"
#include "AuxiliartMethods.h"
using namespace std;

class FileWithExpenses {

string replaceIncomeDataForDataLinesSeparatedByVerticalLines(Expense expense );
    Expense  downloadUserData(string dataFromTheFile);

public:
   bool saveExpenseToFile(Expense expense);
   vector<Expense> loadExpensesFromFile();



};
#endif
