//CSC 134
//M2T1 - Apple sales more
//Cunningham
//1/29/2025
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
    //new for this version 
    string customer_name;
    int apple_to_buy;

    // 
    cout << "Hi, what is your name? ";
    cin >> customer_name;
    cout << "Nice to meet you, " << customer_name <<endl;
    cout <<endl;

    cout <<"Welcome to the " << name << " pizza place." << endl;
    cout <<"We have " << num_apples << " pizzas in stock." << endl;
    cout <<"Price per pizza is: $"<< price_each << endl;
    cout <<endl;
    // Calculate
    double total_Cost = num_apples * price_each ;

    //Print result
    cout << fixed << setprecision(2); //This rounds the print line below to the hundreth place 10.00 instead of 10
    cout << "The total for all " << num_apples << " is $" << total_Cost << endl;
    cout << endl;

    // make a deal
    cout << "How many pizzas do you want? " <<endl;
    cout << "Enter: ";
    cin >> apple_to_buy;
    double customer_cost = apple_to_buy * price_each;
    cout << "For " << apple_to_buy << " your total is $" << customer_cost <<endl;
    return 0;
}