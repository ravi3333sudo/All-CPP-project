#include <iostream>
using namespace std;

class Vehicle {
private:
    string make, model;
    int year;
public:
    void inputData() {
        cout << "Enter Company Name: ";
        cin >> make;
        cout << "Enter Model: ";
        cin >> model;
        cout << "Enter Year: ";
        cin >> year;
    }
    void display() {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

class Car : public Vehicle {
private:
    int numDoors;
public:
    void inputData() {
        Vehicle::inputData(); // Call base class inputData
        cout << "Enter Number of Doors: ";
        cin >> numDoors;
    }
    void display() {
        Vehicle::display(); // Call base class display
        cout << "Number of Doors: " << numDoors << endl;
    }
};

class ToyotaCar : public Car {
private:
    string trimLevel;
public:
    void inputData() {
        Car::inputData(); // Call base class inputData
        cout << "Enter Trim Level: ";
        cin >> trimLevel;
    }
    void display() {
        Car::display(); // Call base class display
        cout << "Trim Level: " << trimLevel << endl;
    }
};

int main() {
    ToyotaCar myCar;
    cout << "----------- Input Car Info ---------------" << endl;
    myCar.inputData();
    cout << "----------- Display Car Info -------------" << endl;
    myCar.display();
    return 0;
}
