#ifndef USERMENEGER_H
#define USERMENEGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "UserFile.h"

using namespace std;

class UserMeneger
{
    int LoggedInUserId;
    vector <User> users;
    UserFile userFile;

    User provideNewUserData();
    int getNewUserId();
    bool loginExists(string login);

public:
    UserMeneger(string UserFileName) : userFile(UserFileName)
    {
        LoggedInUserId = 0;
        users = userFile.loadUsersFromFile();
    };
    void userRegister();
    void displayAllUsers();
    void userLogIn();
    void changePassword();
    void logOut();
    int getIdOfLoggedInUser();
    bool isUserLoggedIn();
};

#endif
