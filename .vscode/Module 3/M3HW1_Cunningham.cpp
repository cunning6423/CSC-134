// CSC 134
// M3HW1 - Gold
// Gabrel Cunningham
// 2/26/2025 

#include <iostream>
#include <iomanip>
using namespace std;
void question1();
// beginning of the main() method
// Ask the user what question you want to a
int main() 
{
    int choice;
    cout <<"Welcome to the question interface!"<< endl;
    cout <<"Enter: "<< endl <<"1 for ChatBot"<< endl << "2 for Receipt Calculator"<<endl <<"3 for Choose Your Own Adventure"<< endl << "4 for Math Practice"<<endl;
    cout <<endl <<"Enter Here:";
    cin >> choice;
switch (choice)
{
case 1:
    
    question1();
    break;
case 2:

    break;
case 3:

    break;
case 4:

    break;
default:
    cout<< "Try Again" << endl;
    cout<< "Use: 1, 2, 3, 4 ";
    break;
}
return 0;
}



void question1(){
    cout <<"Welcome to C++ ChatBot";
}
