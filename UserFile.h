#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include "Markup.h"

#include <fstream>
#include <cstdlib>

#include "User.h"


using namespace std;


class UserFile
{
   const string FILE_NAME;
   CMarkup xml;

public:
    UserFile(string nameOfUserFile) : FILE_NAME(nameOfUserFile) {};
    void addUserToTheFile(User user);
    vector <User> loadUsersFromFile();
    void updateUsersPasswordInTheFile(string loggedInUserIdString, string newPassword);
};

#endif
