//CSC 134
//M4HW1 - Times Table
//Rank-Silver
//Cunningham
//3/20/2025

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int numTable = 5, total;
    bool runTable=false;
    int multiplyNum=1;
    int runAmount;

    cout << "Pick a number 1 to 12 for times table. Enter: ";
    cin >> numTable;

    cout <<"\nThe "<<numTable<<" Times Table!"<< endl;

    while(runTable == false){

        for(int i = 1;i <=12; i++){
            total = numTable * i;
            cout <<numTable <<" times " << i <<" is " << total<< endl;
        }
        runAmount++;
        if (runAmount >= 12){
            runTable = true;
        }
    }
    cout<<"Calcuations are done!\n";
}