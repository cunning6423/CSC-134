//CSC 134
//M1HW1
//Cunningham
//1/29/2025
//This is the moive talk

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //Declare your varables
    string name = "Cunningham";
    string moive = "Sharknado" ;
    int year = 2013, installments = 6;
    double budget = 2 ;

    // Output
    cout <<"The moive " <<moive << " is a widely accepted to be a gory comedey in the " << name << " household." <<endl;
    cout << moive << " came out in the " << year << "." <<endl;
    cout <<"The budeget for " << moive << " was " << budget << "  million." << endl;
    cout <<"There are " <<installments<< " installments of the " << moive << " series.";
    return 0;
}