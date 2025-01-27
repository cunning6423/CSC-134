//CSC 134
//M1Lab1 - Apple sales
//Cunningham
//1/27/2025
//This program helps us sell apples

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //Declare your varables
    string name = "Cunningham";
    int num_apples = 25;
    double price_each = 7.50;   
    
    //
    cout <<"Welcome to the " << name << " pizza place." << endl;
    cout <<"We have " << num_apples << " pizzas in stock." << endl;
    cout <<"Price per pizza is: $"<< price_each << endl;
    cout <<endl;
    // Calculate
    double total_Cost = num_apples * price_each ;

    //Print result
    cout << fixed << setprecision(2); //This rounds the print line below to the hundreth place 10.00 instead of 10
    cout << "The total for all " << num_apples << " is $" << total_Cost << endl;
    return 0;
}