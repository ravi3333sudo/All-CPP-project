#include <iostream>
#include <fstream>
using namespace std;

class temp
{
    string id, name, author, search;
    fstream file;

public:
    void addBook();
    void showAll();
    void extractBook();
} obj;

int main()
{
    char choice;
    cout << "-------------------------\n";
    cout << "1-Show All Books\n";
    cout << "2-Extract Book\n";
    cout << "3-Add Books (ADMIN)\n";
    cout << "4-Exit\n";
    cout << "-------------------------\n";
    cout << "Enter Your choice :: ";
    cin >> choice;

    switch (choice)
    {
    case '1':
        cin.ignore();
        obj.showAll();
        break;
    case '2':
        cin.ignore();
        obj.extractBook();
        break;
    case '3':
        cin.ignore();
        obj.addBook();
        break;
    case '4':
        return 0;
    default:
        cout << "Invalid Choice...!";
    }

    return 0;
}

void temp::addBook()
{
    cout << "\nEnter Book ID :: ";
    getline(cin, id);
    cout << "Enter Book Name :: ";
    getline(cin, name);
    cout << "Enter Book's Author Name :: ";
    getline(cin, author);

    file.open("bookData.txt", ios::out | ios::app);
    file << id << "*" << name << "*" << author << endl;
    file.close();
}

void temp::showAll()
{
    file.open("bookData.txt", ios::in);
    if (!file)
    {
        cout << "No data found.\n";
        return;
    }

    cout << "\n\n";
    cout << "\t\tBook ID\t\t\tBook Name\t\t\tAuthor's Name\n";

    while (getline(file, id, '*') && getline(file, name, '*') && getline(file, author, '\n'))
    {
        cout << "\t\t" << id << "\t\t\t" << name << "\t\t\t" << author << endl;
    }

    file.close();
}

void temp::extractBook()
{
    showAll();
    cout << "Enter Book ID :: ";
    getline(cin, search);

    file.open("bookData.txt", ios::in);
    if (!file)
    {
        cout << "No data found.\n";
        return;
    }

    bool found = false;
    cout << "\n\n";
    cout << "\t\tBook ID\t\t\tBook Name\t\t\tAuthor's Name\n";

    while (getline(file, id, '*') && getline(file, name, '*') && getline(file, author, '\n'))
    {
        if (search == id)
        {
            cout << "\t\t" << id << "\t\t\t" << name << "\t\t\t" << author << endl;
            cout << "Book Extracted Successfully...!\n";
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Book ID not found.\n";
    }

    file.close();
}
