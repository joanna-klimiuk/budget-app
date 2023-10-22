#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include "Markup.h"

#include <fstream>
#include <cstdlib>

//#include "MetodyPomocnicze.h"
#include "User.h"
#include "TextFile.h"

using namespace std;


class UserFile :public TextFile
{
   CMarkup xml;

public:
    UserFile(string nameOfUserFile) : TextFile(nameOfUserFile) {};
    void addUserToTheFile(User user);
    vector <User> loadUsersFromFile();
  /*  User getOneUserData(string ???????);
    void saveAllUsersToFile(vector <User> users);
*/
};

#endif
