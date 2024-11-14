#include <iostream>
#include <fstream>
using namespace std;

class temp
{
    string rollNum, name, fName, address, search;
    fstream file;

public:
    void addStu();
    void viewStu();
    void searchStu();
} obj;

int main()
{
    char choice;
    while (true) {
        cout << "---------------------\n";
        cout << "1- Add Student Record\n";
        cout << "2- View Student Record\n";
        cout << "3- Search Student Record\n";
        cout << "4- Exit\n";
        cout << "---------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case '1':
                obj.addStu();
                break;
            case '2':
                obj.viewStu();
                break;
            case '3':
                obj.searchStu();
                break;
            case '4':
                return 0;
            default:
                cout << "Invalid choice...!!\n";
        }
    }
}

void temp::addStu()
{
    cout << "Enter Student Roll Number: ";
    getline(cin, rollNum);
    cout << "Enter Student Name: ";
    getline(cin, name);
    cout << "Enter Student Father Name: ";
    getline(cin, fName);
    cout << "Enter Student Address: ";
    getline(cin, address);

    file.open("stuData.txt", ios::out | ios::app);
    if (file.is_open()) {
        file << rollNum << "*";
        file << name << "*";
        file << fName << "*";
        file << address << endl;
        file.close();
    } else {
        cout << "Error opening file for writing!\n";
    }
}

void temp::viewStu()
{
    file.open("stuData.txt", ios::in);
    if (file.is_open()) {
        while (getline(file, rollNum, '*') && getline(file, name, '*') &&
               getline(file, fName, '*') && getline(file, address, '\n')) {
            cout << "\nStudent Roll Number: " << rollNum << endl;
            cout << "Student Name: " << name << endl;
            cout << "Student Father Name: " << fName << endl;
            cout << "Student Address: " << address << endl;
        }
        file.close();
    } else {
        cout << "Error opening file for reading!\n";
    }
}

void temp::searchStu()
{
    cout << "Enter Student Roll Number: ";
    getline(cin, search);

    file.open("stuData.txt", ios::in);
    bool found = false;
    if (file.is_open()) {
        while (getline(file, rollNum, '*') && getline(file, name, '*') &&
               getline(file, fName, '*') && getline(file, address, '\n')) {
            if (rollNum == search) {
                cout << "\nStudent Roll Number: " << rollNum << endl;
                cout << "Student Name: " << name << endl;
                cout << "Student Father Name: " << fName << endl;
                cout << "Student Address: " << address << endl;
                found = true;
                break;
            }
        }
        file.close();
        if (!found) {
            cout << "Student with Roll Number " << search << " not found.\n";
        }
    } else {
        cout << "Error opening file for reading!\n";
    }
}