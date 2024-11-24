#include <iostream>
#include <fstream>
#include <string> // Included for string usage
using namespace std;

class temp
{
    string userName, Email, password;
    string searchName, searchPass, searchEmail;
    fstream file;

public:
    void login();
    void signUP();
    void forgot();
} obj;

int main()
{
    char choice;
    cout << "\n1- Login";
    cout << "\n2- Sign-up";
    cout << "\n3- Forgot Password";
    cout << "\n4- Exit";
    cout << "\nEnter Your Choice :: ";
    cin >> choice;
    cin.ignore(); // Clear input buffer for getline() to work correctly

    switch (choice)
    {
    case '1':
        obj.login();
        break;
    case '2':
        obj.signUP();
        break;
    case '3':
        obj.forgot();
        break;
    case '4':
        return 0;
    default:
        cout << "Invalid Selection....!" << endl;
    }
    return 0;
}

void temp::signUP()
{
    cout << "\nEnter Your User Name :: ";
    cin.ignore(); // Clear input buffer for getline
    getline(cin, userName);
    cout << "Enter Your Email Address :: ";
    getline(cin, Email);
    cout << "Enter Your Password :: ";
    getline(cin, password);

    file.open("loginData.txt", ios::out | ios::app);
    if (file.is_open())
    {
        file << userName << "*" << Email << "*" << password << endl;
        file.close();
        cout << "Account created successfully!" << endl;
    }
    else
    {
        cout << "Error: Unable to open file." << endl;
    }
}

void temp::login()
{
    cout << "-----------LOGIN---------" << endl;
    cout << "Enter Your User Name :: ";
    cin.ignore(); // Clear input buffer for getline
    getline(cin, searchName);
    cout << "Enter Your Password :: ";
    getline(cin, searchPass);

    file.open("loginData.txt", ios::in);
    if (!file.is_open())
    {
        cout << "Error: Unable to open file for reading." << endl;
        return;
    }

    bool found = false;
    while (getline(file, userName, '*') && getline(file, Email, '*') && getline(file, password))
    {
        if (userName == searchName && password == searchPass)
        {
            cout << "\nAccount Login Successful...!";
            cout << "\nUsername :: " << userName;
            cout << "\nEmail :: " << Email << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Invalid username or password." << endl;
    }
    file.close();
}

void temp::forgot()
{
    cout << "\nEnter Your User Name :: ";
    cin.ignore(); // Clear input buffer for getline
    getline(cin, searchName);
    cout << "Enter Your Email Address :: ";
    getline(cin, searchEmail);

    file.open("loginData.txt", ios::in);
    if (!file.is_open())
    {
        cout << "Error: Unable to open file for reading." << endl;
        return;
    }

    bool found = false;
    while (getline(file, userName, '*') && getline(file, Email, '*') && getline(file, password))
    {
        if (userName == searchName && Email == searchEmail)
        {
            cout << "\nAccount Found....!" << endl;
            cout << "Your Password :: " << password << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nAccount not found or details do not match." << endl;
    }
    file.close();
}

