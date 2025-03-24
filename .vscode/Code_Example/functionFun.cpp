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
    int balance, withDraw, deposit;
    bankAccount(balance, withDraw, deposit);
    cout <<"Your balance: $" << balance << endl;
}


int bankAccount(int balance, int withDraw, int deposit){
    string withdrawChoice;
    string depositChoice;
    cout <<"\nEnter balance: $";
    cin >> balance;
    cout <<"Do you want to deposit (Yes or No): ";
    cin >> depositChoice;
    if (depositChoice == "yes"){
        cout << "Deposit amount: $" ;
        cin >> deposit;
        balance = balance + deposit;
    }
    cout <<"Do you want to withdraw (Yes or No): ";
    cin >> withdrawChoice;
    if (withdrawChoice == "Yes"){
        cout << "Withdraw amount: $" ;
        cin >> withDraw;
        balance = balance - withDraw;
    }
    return balance;
}