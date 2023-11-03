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
