#include "FileWithExpenses.h"

bool FileWithExpenses::saveExpenseToFile(Expense expense) {

    string userNumber="user"+AuxiliartMethods::conversionIntForString(expense.getUserId());
    string expenseIdNumber="Expense"+AuxiliartMethods::conversionIntForString(expense.getId());
    string lineWithData="";
    lineWithData=replaceIncomeDataForDataLinesSeparatedByVerticalLines(expense);
    CMarkup xml;
    bool fileExists = xml.Load( EXPENSES_FILE_NAME );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    if (!xml.FindElem(userNumber)) {
        xml.AddElem(userNumber);
    }
    xml.IntoElem();

    xml.AddElem(expenseIdNumber, lineWithData);
    xml.OutOfElem();
    xml.Save(EXPENSES_FILE_NAME);
    return true;
}
string FileWithExpenses::replaceIncomeDataForDataLinesSeparatedByVerticalLines(Expense expense) {
    string lineWithData="";
    lineWithData+=AuxiliartMethods::conversionIntForString(expense.getUserId())+"|";
    lineWithData+=AuxiliartMethods::conversionIntForString(expense.getId())+"|";
    lineWithData+=AuxiliartMethods::conversionIntForString(expense.getDate())+"|";
    lineWithData+=expense.getIncomeCategory()+"|";
    lineWithData+=AuxiliartMethods::conversionDoubleForString(expense.getValue())+"|";
    return lineWithData;
}
vector<Expense> FileWithExpenses::loadExpensesFromFile(int userId) {
    CMarkup xml;
    vector<Expense> expenses;
    Expense expense;
    string u= "user"+AuxiliartMethods::conversionIntForString(userId);

    bool fileExists = xml.Load( EXPENSES_FILE_NAME );
    xml.FindElem();
    xml.IntoElem();
    xml.FindElem(u);
    xml.IntoElem();
    while (xml.FindElem()) {
        MCD_STR dataFromTheFile = xml.GetData();
        expense=downloadUserData(dataFromTheFile);
        expenses.push_back(expense);
    }
    xml.OutOfElem();
    return  expenses;
}
Expense FileWithExpenses:: downloadUserData(string dataFromTheFile) {
    Expense expense;
    string singleData = "";
    int numberSingleData = 1;

    for (int markPosition = 0; markPosition < dataFromTheFile.length(); markPosition++) {
        if (dataFromTheFile[markPosition] != '|') {
            singleData += dataFromTheFile[markPosition];
        } else {
            switch(numberSingleData) {
            case 1:
                expense.setUserId( atoi(singleData.c_str()));
                break;
            case 2:
                expense.setId( atoi(singleData.c_str()));
                break;
            case 3:
                expense.setDate(atoi(singleData.c_str()));
                break;
            case 4:
                expense.setIncomeCategory(singleData);
                break;
            case 5:
                expense.setValue(AuxiliartMethods::conversionStringForDouble(singleData));
                break;
            }
            singleData = "";
            numberSingleData++;
        }
    }
    return expense;
}
