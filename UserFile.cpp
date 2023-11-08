#include "UserFile.h"
#include "AuxiliaryMethods.h"

void UserFile::addUserToTheFile(User user)
{
    bool bSuccess = xml.Load(FILE_NAME);

    if(!bSuccess)
    {
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());

    xml.Save(FILE_NAME);
}
/*
void UserFile::updateUsersPasswordInTheFile(string loggedInUserIdString, string newPassword)
{
    string userIdString, previousPassword;

    if(xml.Load(FILE_NAME))
    {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("User"))
        {
            userIdString = xml.GetAttrib("UserId");
            if (loggedInUserIdString == userIdString)
            {
                previousPassword = xml.GetData();
                xml.SetData(newPassword);
                break;
            }
        }
        xml.OutOfElem();
    }

    xml.Save(FILE_NAME);
}*/
/*
void UserFile::saveAllUsersToFile(vector <User> users)
{
    xml.AddElem("Users");
    xml.FindElem();
    xml.IntoElem();

    for (size_t i = 0; i < users.size(); i++)
    {
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem("UserId", users[i].getId());
        xml.AddElem("Login", users[i].getLogin());
        xml.AddElem("Password", users[i].getPassword());
        xml.AddElem("Name", users[i].getName());
        xml.AddElem("Surname", users[i].getSurname());
        xml.OutOfElem();
    }

    xml.Save(FILE_NAME);
}
*/
vector <User> UserFile::loadUsersFromFile()
{
    int userId;
    User user;
    vector <User> users;

    bool bSuccess = xml.Load(FILE_NAME);

    xml.ResetPos();
    xml.FindElem(); //jestesmy w Users
    xml.IntoElem(); //Wchodzimy wglab Users

    if (bSuccess)
    {
        while(xml.FindElem("User"))
        {
          xml.IntoElem();
          xml.FindElem("UserId");
          userId = atoi(xml.GetData().c_str());
          user.setId(userId);
          xml.FindElem("Login");
          user.setLogin(xml.GetData());
          xml.FindElem("Password");
          user.setPassword(xml.GetData());
          xml.FindElem("Name");
          user.setName(xml.GetData());
          xml.FindElem("Surname");
          user.setSurname(xml.GetData());
          xml.OutOfElem();

          users.push_back(user);
        }
    }
    return users;
}
