#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "Markup.h"
#include "AuxiliartMethods.h"
using namespace std;

class FileWithIncomes {

    string replaceIncomeDataForDataLinesSeparatedByVerticalLines(Income income );
    Income  downloadUserData(string dataFromTheFile);

public:
   bool saveIncomeToFile(Income income);
   vector<Income> loadIncomesFromFile();



};
#endif
