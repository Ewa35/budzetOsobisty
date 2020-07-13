#include "FileWithUsers.h"

void FileWithUsers:: addUsersToFile(User user)
{
    string lineWithData="";
    string numberUser="user"+ conversionIntForString(user.getId());
    lineWithData=replaceUserDataForDataLinesSeparatedByVerticalLines(user);
    cout<<lineWithData;
    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( numberUser, lineWithData );

xml.Save("Users.xml");
}

string FileWithUsers::replaceUserDataForDataLinesSeparatedByVerticalLines(User user)
{
    string lineWithData="";
    lineWithData+=conversionIntForString(user.getId())+"|";
    lineWithData+=user.getName()+"|";
    lineWithData+=user.getLastName()+"|";
    lineWithData+=user.getLogin()+"|";
    lineWithData+=user.getPassword()+"|";
    return lineWithData;
}

string  FileWithUsers:: conversionIntForString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
