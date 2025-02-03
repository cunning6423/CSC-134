//CSC 134
//M2T2 - Apple sales more
//Cunningham
//2/3/2025



#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    string store_name = "Cunningham's Pizza";
    string food_name = "pizza";
    double food_price = 8.99; // $
    int amount;
    
    // Our receipt variables
    double subtotal, total;
    double tax_percent, tax_cost;
    
    // 
    cout << setprecision(2) <<fixed;

    //Do the Order
    cout <<"Welcome to the " << store_name << " store!" << endl;
    cout <<"A pizza is " << food_price  << "!" << endl;
    cout <<"How many pizza's do you want to order: " ;
    cin >> amount;
    subtotal = food_price * amount;
    cout <<"You ordered  "<< amount << " of " << food_name << " and it is $" << subtotal <<endl;  
    cout <<endl;

    // Cacluate subtotal, tax, total
    tax_percent = 0.08;
    tax_cost = subtotal * tax_percent; //8% of 5.99
    total    = subtotal + tax_cost;
    
    // Print the receipt
    cout << setprecision(2) <<fixed; // Rounds 2 decimals placement.
    cout <<"-------------------------------" <<endl;
    cout <<setw(12) <<"subtotal: $" <<setw(6) <<subtotal <<endl;
    cout <<setw(12) <<"Tax (8%): $" <<setw(6) <<tax_cost <<endl;
    cout <<"-------------------------------" <<endl;
    cout <<setw(12) <<"Total: $"    <<setw(6) <<total <<endl;
    cout <<"-------------------------------" <<endl;

    cout << "Have a nice day! " << endl;
    return 0;
}