#include <iostream>
#include "UserMeneger.h"
#include "Date.h"


using namespace std;

int main()
{
  //  UserMeneger userMeneger("users.xml");
 //   UserFile userFile("users.xml");
 //   userFile.loadUsersFromFile();


  //  userMeneger.userLogIn();
  //  userMeneger.displayAllUsers();

    Date date;
    cout << date.getTodayDate();
    date.selectDate();

    return 0;
}
