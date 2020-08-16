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
