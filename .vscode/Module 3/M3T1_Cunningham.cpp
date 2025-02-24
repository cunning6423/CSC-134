// CSC 134
// M3LAB1 - Choices
// CunninghamG
// 2/24/2025

#include <iostream>
using namespace std;

// beginning of the main() method
int main() {
  // declare the variable we need
  int choice;
  int rockThrow = 1, planAttack = 2, attackChoice;

  //Constants
  const int FIGHT = 1;
  const int RUN = 2;
  const int ITEM = 3;

  // ask the question
  cout << "You're in a pokemon battle! Pikachu vs.Snorlax." << endl;
  cout << "1. Fight" << endl;
  cout << "2. Run"   << endl;
  cout << "3. Use Item" << endl;
  cout << "Type 1,2, or 3: "; 
  cin >> choice;

  // using if, make a decision based on the user's choice
  // = sign sets the value, two == asks a question

  if (FIGHT == choice) {
  	cout << "You chose to fight" << endl;
    cout <<"Would you like to calulate your attack or throw a rock: " << endl;
    cout <<"1. Throw a rock!!" <<endl;
    cout <<"2. Plan your attack !!" << endl;
    cin >> attackChoice;
    if (rockThrow == attackChoice )
    {
        cout << "Sadly, you lose. " << endl;
    }
    else if (planAttack == attackChoice)
    {
        cout << "You defeated the Snorlax!!" << endl ;
    }
    else 
    {
        cout << "That is a vaild number"<< endl;
        cout << "Try again!!" << endl;
    }
    
  }
  else if (RUN == choice) {
  	cout << "You chose to run" << endl;
    cout << "You live to fight another day." << endl;
  }
  else if (ITEM == choice) {
    cout << "You use a potion." << endl;
    cout << "More here later..." << endl;
  }
  else {
  	cout << "I'm sorry, that is not a valid choice." << endl;
    
  }
  // finish up
  cout <<endl;
  cout << "Thanks for playing!" << endl; // this runs no matter what they choose
  return 0; // exit without error
} // end of the main() method