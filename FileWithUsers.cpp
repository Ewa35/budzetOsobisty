#include "FileWithUsers.h"

void FileWithUsers:: addUsersToFile(User user) {
    string lineWithData="";
    string numberUser="user"+ AuxiliartMethods::conversionIntForString(user.getId());
    lineWithData=replaceUserDataForDataLinesSeparatedByVerticalLines(user);
    CMarkup xml;

    bool fileExists = xml.Load( USER_FILE_NAME );
    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( numberUser, lineWithData );
    xml.Save(USER_FILE_NAME);

}

string FileWithUsers::replaceUserDataForDataLinesSeparatedByVerticalLines(User user) {
    string lineWithData="";
    lineWithData+=AuxiliartMethods:: conversionIntForString(user.getId())+"|";
    lineWithData+=user.getName()+"|";
    lineWithData+=user.getLastName()+"|";
    lineWithData+=user.getLogin()+"|";
    lineWithData+=user.getPassword()+"|";
    return lineWithData;
}
vector<User> FileWithUsers::loadUsersFromFile() {
    CMarkup xml;
    vector<User> users;
    User user;
    bool fileExists = xml.Load( USER_FILE_NAME );
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem()) {
        MCD_STR dataFromTheFile = xml.GetData();
        user=downloadUserData(dataFromTheFile);
        users.push_back(user);
    }
    xml.OutOfElem();
    return users;
}

User FileWithUsers:: downloadUserData(string dataFromTheFile) {
    User user;
    string singleData = "";
    int numberSingleData = 1;

    for (int markPosition = 0; markPosition < dataFromTheFile.length(); markPosition++) {
        if (dataFromTheFile[markPosition] != '|') {
            singleData += dataFromTheFile[markPosition];
        } else {
            switch(numberSingleData) {
            case 1:
                user.setId( atoi(singleData.c_str()));
                break;
            case 2:
                user.setName(singleData);
                break;
            case 3:
                user.setLastName(singleData);
                break;
            case 4:
                user.setLogin(singleData);
                break;
            case 5:
                user.setPassword(singleData);
                break;
            }
            singleData = "";
            numberSingleData++;
        }
    }
    return user;
}
void FileWithUsers::saveTheNewPasswordInAFile(string lineWithData, int loggedUserId) {
    User user;
    string numberUser= "user"+AuxiliartMethods::conversionIntForString(loggedUserId);
    CMarkup xml;
    bool fileExists = xml.Load( USER_FILE_NAME );
    xml.FindElem();
    xml.IntoElem();
    xml.FindElem(numberUser);
    xml.SetData(lineWithData);
    xml.OutOfElem();
    xml.Save(USER_FILE_NAME);
}

