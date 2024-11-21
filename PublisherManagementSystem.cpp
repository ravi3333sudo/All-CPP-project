/*
Imagine a publishing company that markets both book and audio cassette.
1. create class publishing that store the price(type float) of a publiscation.
2. from this class drive two classes Book which adds a page count (type int) and type which adds a playing time in minutes(type float)
3. Each of these three classes should have a getdata() function to get its data from the user at the keyboard and a putdata() function to display its data object.
4. write a main() program to test Book and tape classes by creating objects of them and then display the data
*/
#include <iostream>
using namespace std;
class Publication
{
protected:
    float price;

public:
    void getdata()
    {
        cout << "Enter Price :";
        cin >> price;
    }
    void putdata()
    {
        cout << "Price :" << price << endl;
    }
};
class Book : public Publication
{
private:
    int pageCount;

public:
    void getdata()
    {
        cout << "Enter Number of Page :";
        cin >> pageCount;
        Publication::getdata();
    }
    void putdata()
    {
        cout << "Number of pages :" << pageCount << endl;
        Publication::putdata();
    }
};
class TAPE : public Publication
{
private:
    float time;

public:
    void getdata()
    {
        cout << "Enter Time in Minutes :";
        cin >> time;
        Publication::getdata();
    }
    void putdata()
    {
        cout << "Time :" << time << endl;
        Publication::putdata();
    }
};
main()
{
    Book b;
    TAPE t;
    int op;
    cout << "1. Book Information" << endl;
    cout << "2. TAPE Information" << endl;
    cout << "---------------------------" << endl;
    cout << "Plz Enter Your Choice:";
    cin >> op;
    switch (op)
    {
    case 1:
        cout << "----Book Information----" << endl;
        b.getdata();
        b.putdata();
        break;
    case 2:
        cout << "----TAPE Information----" << endl;
        t.getdata();
        t.putdata();
        break;
        default:
            cout<<"Invalid Number"<<endl;
    }
}