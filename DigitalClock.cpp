#include<iostream>
#include<iomanip>
using namespace std;
class DigitalC{
    private:
        int hours,minutes,seconds;
    public:
        DigitalC(int h,int m,int s){
            hours = h;
            minutes = m;
            seconds = s;
        }
        void displayTime(){
            if(hours<10)
            cout<<setfill('0')<<setw(2)<<hours<<":"<<setw(2)<<minutes<<":"<<setw(2)<<seconds<<" ";
            else if(minutes<10)
            cout<<setfill('0')<<setw(2)<<hours<<":"<<setw(2)<<minutes<<":"<<setw(2)<<seconds<<" ";
            else if(seconds<10)
            cout<<setfill('0')<<setw(2)<<hours<<":"<<setw(2)<<minutes<<":"<<setw(2)<<seconds<<" ";

            if(hours>=12)
            cout<<"PM";
            else
            cout<<"AM";

        }

};
int main(){
    int hours, minutes,seconds;
    cout<<"Enter Hours:";
    cin>>hours;
    cout<<"Enter Minutes:";
    cin>>minutes;
    cout<<"Enter Seconds:";
    cin>>seconds;
    DigitalC clock(hours,minutes,seconds);
    clock.displayTime();
}