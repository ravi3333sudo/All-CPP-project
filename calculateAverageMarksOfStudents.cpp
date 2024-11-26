#include <iostream>
using namespace std;
int main(){
    int students;
    cout<<"Enter number of students: ";
    cin>>students;
    int arr[students];
    int total = 0;
    for(int i=0; i<students; i++){
        cout<<"Enter marks of student "<<i+1<<": ";
        cin>>arr[i];
        total = total + arr[i]; 
    }

    double avg;
    avg = total / students;
    cout<<"Average marks of class: "<<avg;

}