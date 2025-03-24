/*
C++
3/24/2025
*/

#include <iostream>
#include <iomanip>
using namespace std;

int bankAccount(int balance, int withDraw, int deposit);

int main(){
    cout << " Welcome to Bank Safety!";
    bankAccount(balance, withDraw, deposit);
}
int bankAccount(int balance, int withDraw, int deposit){
    string withdrawChoice;
    string depositChoice;
    cout <<"Enter balance: ";
    cin >> balance;
    cout <<"Do you want to deposit (Yes or No): ";
    cin depositChoice;
    if (depositChoice == "yes"){
        cout << "Deposit amount: " ;
        cin >> deposit
        balance = balance + deposit;
    }
    
}