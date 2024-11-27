#include <iostream>
using namespace std;

bool isPalindrome(string str){
    int length = str.length();

     for(int i=0; i<length/2; i++){
        if(str[i] != str[length-i-1]){
        return false;    
        }
     }
     return true;
}

int main(){
    string input;

    cout<<"Enter a String: ";
    cin>>input;

    if(isPalindrome(input)){
        cout<<"String is palindrome.";
    }
    else{
        cout<<"String is not palindrome.";
    }
}