/*
CSC 134
M5T1 -  basic Functions
CunninghamG
3/24/2025
*/
#include <iostream>
using namespace std;

// First version -- Just all funtions
void sayHi();
int add(int first, int second);
void printNumber(int num);
int globalX = 822;

int main(){
    int myNum =12;
    cout << "int main(), myNum = " << myNum << endl;
    cout << "Global Variable: globalX = " << globalX << endl;
    sayHi();
    cout << "2 + 2 = ";
    int num = add(2,2);
    printNumber(num);
    return 0;
}
// Function definitions (full thing)
//Void function -- just call no need to return
void sayHi(){
    cout << "Hi" << endl;
}
// Value returning function
int add(int first, int second){
    int answer = first + second;
    return answer;
}
//void, but takes a value (Parameter)
void printNumber(int num){
    cout << num << endl;
}
