/*
CSC 134
M5LAB1 - Choose Your Own Adventure
Gabriel Cunningham
3/26/2025

This template serves as a starting point
for your own program. We'll be using
void functions to tell a simple story,
where the user gets to make choices.

You can fork this template by clicking on the name above, then click the three
dots on the top right, and click 'fork repl'. This makes a copy for you to use.
*/
#include <iostream>
using namespace std;

//Main menu functions
void main_menu();
void choice_boardtheAirship();
void choice_jumpofIsland();
void choice_attempt_to_leave();
void choice_world_history();
//Board the Air ship Path
void airshipPath_Stay();
// Leaving path functions
void leavePath_leaveContinue_1();
void leavePath_leaveContinue_2();
void leavePath_Fight();

int main() {
  cout << "M5LAB1 - Choose Your Own Adventure" << endl;
  // load up the main menu
  main_menu();
  // when we return here, we're done
  cout << "Thanks for playing!" << endl;
  return 0; // finished with no errors
}

void main_menu() {
  // Write a simple menu that lets the user choose 1,2, or 3, or 4 to quit.
  cout << "Main Menu" << endl;
  cout << "You're in front gaint airship..." << endl;
  cout << "Do you:" << endl;
  cout << "1. Board the airship" << endl;
  cout << "2. Jump Off the island" << endl;
  cout << "3. Attempt to leave, this life ain't for you" << endl;
  cout << "4. World history" << endl;
  cout << "5. [Quit]" << endl;
  cout << "Choose: ";
  int choice;
  cin >> choice;
  if (1 == choice) {
    choice_boardtheAirship();
  } else if (2 == choice) {
    choice_jumpofIsland();
  } else if (3 == choice) {
    choice_attempt_to_leave();
  } else if (4==choice){
    choice_world_history();
  }else if (5 == choice) {
    cout << "\nOk, quitting game" << endl;
    return; // go back to main()
  } else {
    cout << "That's not a valid choice, please try again." << endl;
    cin.ignore(); // clear the user input
    main_menu();  // try again
  }
}

// FUNCTION DEFINITIONS
// OK, we have the prototypes at the top, but
// now we have to actually write the functions.
// They go here, after main().
void choice_boardtheAirship() {
  cout << "The Captian speaks: \n\"Welcome to the Soaring Bolt.\"" << endl;
  cout << "It's locked. " << endl;
  cout << "Do you:" << endl;
  cout << "1. Jump Off" << endl;
  cout << "2. Try to leave" << endl;
  cout << "3. Stay" << endl;
  int choice;
  cout << "Choose: ";
  cin >> choice;
  if (1 == choice) {
    choice_jumpofIsland();
  } else if (2 == choice) {
    choice_attempt_to_leave();
  } else if (3 == choice){

  }
}

//Main menu Pathway
void choice_jumpofIsland() { 
    cout << "You jump off..." << endl;
    cout << "You Died"<< endl;
    cout << "***Unaliving yourself ending(1/)***";
}

void choice_attempt_to_leave() { 
    cout << "You turn around to leave.\nGuards command \"If you don't complie you will die.\"" << endl; 
    cout<< "Do you: \n1. Continue to leave" << endl;
    cout <<"2. Comply"<<endl;
    int choice;
    cout << "Choose: ";
    cin >> choice;
    if(choice == 1){
        leavePath_leaveContinue_1();
    }else if(choice == 2){
        choice_boardtheAirship();
    }
}

void choice_world_history() {
    cout <<"Welcome to the Island of Sklor!!\n" << endl;
    cout <<"This island's technology is powered by steam.\n "<<
    "Airships are the only transportation from each Island of the\nempire of Skylor."
    <<" You are a criminal forced venture out to claim more flying islands." << endl;
    int choice;
    cout <<"\n1. Head back to the main menu.\n2. Press any key to quit" <<endl;
    cout <<"Choose: ";
    cin>> choice;
    if (choice == 1){
        main_menu();
    }else{
        
    }
}
// PATH WAYS
    //Air Ship Pathway
void airshipPath_Stay(){cout << "You claimed land for the empire.\nYou get back your freedom.";
    cout << "\n***Free Man Ending(2/)***"<< endl;
    //ENDING 2
}
    //Leaving pathway
void leavePath_leaveContinue_1(){
    cout << "They urge you to comply." << endl;
    cout << "Do you: \n1.Fight"<<endl;
    cout << "2. Run" << endl;
    cout << "3. Continue Forward"<< endl;
    int choice;
    cout <<"Choose: "
    cin >> choice;
    if(choice == 1){
        leavePath_Fight();
    }else if(choice == 2){
        ;
    }else if(choice==3){
        leavePath_leaveContinue_2();
    }
}
void leavePath_Fight(){
    cout <<"You get riddle with bullets flying faster that the speed of sound." << endl;
    cout <<"Well that was pretty fast\n"<< endl;
    cout <<"***Shot faster that sound ending(3/)"
}