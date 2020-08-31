#include "FileWithIncomes.h"

bool FileWithIncomes::saveIncomeToFile(Income income)
{

    string userNumber="user"+AuxiliartMethods::conversionIntForString(income.getUserId());
    string incomeIdNumber="Income"+AuxiliartMethods::conversionIntForString(income.getId());
    string lineWithData="";
    lineWithData=replaceIncomeDataForDataLinesSeparatedByVerticalLines(income);
    CMarkup xml;
    bool fileExists = xml.Load( "Incomes.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    if (!xml.FindElem(userNumber))
    {
        xml.AddElem(userNumber);
    }
    xml.IntoElem();

    xml.AddElem(incomeIdNumber, lineWithData);
    xml.OutOfElem();
    xml.Save("Incomes.xml");
    return true;
}
string FileWithIncomes::replaceIncomeDataForDataLinesSeparatedByVerticalLines(Income income)
{
    string lineWithData="";
    lineWithData+=AuxiliartMethods::conversionIntForString(income.getUserId())+"|";
    lineWithData+=AuxiliartMethods::conversionIntForString(income.getId())+"|";
    lineWithData+=AuxiliartMethods::conversionIntForString(income.getDate())+"|";
    lineWithData+=income.getIncomeCategory()+"|";
    lineWithData+=AuxiliartMethods::conversionDoubleForString(income.getValue())+"|";
    return lineWithData;
}
vector<Income> FileWithIncomes::loadIncomesFromFile()
{
    CMarkup xml;
    vector<Income> incomes;
    Income income;
    string u= "user"+AuxiliartMethods::conversionIntForString(1);

    bool fileExists = xml.Load( "Incomes.xml" );
    xml.FindElem();
    xml.IntoElem();
    xml.FindElem(u);
    xml.IntoElem();
    while (xml.FindElem()) {
        MCD_STR dataFromTheFile = xml.GetData();
        income=downloadUserData(dataFromTheFile);
        incomes.push_back(income);
    }
    xml.OutOfElem();
    return  incomes;
}
Income FileWithIncomes:: downloadUserData(string dataFromTheFile) {
    Income income;
    string singleData = "";
    int numberSingleData = 1;

    for (int markPosition = 0; markPosition < dataFromTheFile.length(); markPosition++) {
        if (dataFromTheFile[markPosition] != '|') {
            singleData += dataFromTheFile[markPosition];
        } else {
            switch(numberSingleData) {
            case 1:
                income.setUserId( atoi(singleData.c_str()));
                break;
            case 2:
                income.setId( atoi(singleData.c_str()));
                break;
            case 3:
                income.setDate(atoi(singleData.c_str()));
                break;
            case 4:
                income.setIncomeCategory(singleData);
                break;
            case 5:
                income.setValue(AuxiliartMethods::conversionStringForDouble(singleData));
                break;
            }
            singleData = "";
            numberSingleData++;
        }
    }
    return income;
}
