#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Income.h"
#include "Markup.h"
#include "AuxiliartMethods.h"
using namespace std;

class FileWithIncomes {

    string replaceIncomeDataForDataLinesSeparatedByVerticalLines(Income income );
    Income  downloadUserData(string dataFromTheFile);

public:
   bool saveIncomeToFile(Income income);
   vector<Income> loadIncomesFromFile(int userId);

struct before
{
    inline bool operator() ( Income& struct1,  Income& struct2)
    {
        return (struct1.getDate() < struct2.getDate());
    }
};

};
#endif
