#include "UserMeneger.h"

void UserMeneger::userRegister()
{
    User user = provideNewUserData();

    users.push_back(user);
    userFile.addUserToTheFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

void UserMeneger::userLogIn()
{
    User user;
    string login = "", password = "";
    LoggedInUserId = 0;
    bool loginExists = false;

    cout << endl << "Podaj login: ";
    cin >> login;

    for (size_t i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            loginExists = true;

            for (int triesCount = 3; triesCount > 0; triesCount--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << triesCount << ": ";
                cin >> password;

                if (users[i].getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    LoggedInUserId = users[i].getId();
                    break;
                }
            }

            if (LoggedInUserId == 0)
            {
                cout << "Wprowadzono 3 razy bledne haslo." << endl;
                system("pause");
            }
        }
    }

    if (!loginExists)
    {
        cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
        system("pause");
    }
}

void UserMeneger::changePassword()
{
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    cin >> newPassword;

    for (size_t i = 0; i < users.size(); i++)
    {
        if (users[i].getId() == LoggedInUserId)
        {
            users[i].setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }

    userFile.updateUsersPasswordInTheFile(AuxiliaryMethods::convertIntToString(LoggedInUserId), newPassword);
}

void UserMeneger::logOut()
{
    LoggedInUserId = 0;
}

int UserMeneger::getIdOfLoggedInUser()
{
    return LoggedInUserId;
}

 bool UserMeneger::isUserLoggedIn()
 {
     if (LoggedInUserId > 0)
        return true;

     else
        return false;
 }

User UserMeneger::provideNewUserData()
{
    User user;

    user.setId(getNewUserId());

    string login, password, name, surname;

    do
    {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (loginExists(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    cout << "Podaj imie: ";
    cin >> name;
    user.setName(name);

    cout << "Podaj nazwisko: ";
    cin >> surname;
    user.setSurname(surname);

    return user;
}

int UserMeneger::getNewUserId()
{
    if (users.empty())
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserMeneger::loginExists(string login)
{
    for (size_t i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}
