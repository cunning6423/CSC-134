/*
Final Project
Choose your own adventure
Cunningham, Gabriel
Explore the world free, however the only thing that blocks you way MATH!!!
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int generateMathQuestion();
void printDirectionChoices();
bool gameRound(int level);
string mainMenu();

int main()
{
    srand(time(0));  // Initialize random seed
    int level = 1;  // Game starts at level 1
    int additionDifficulty = 1;
    int subtractionDifficulty = 1;
    int multiplicationDifficulty = 1;
    int divisionDifficulty = 1;
    cout << "Welcome to the Walking Upstairs Game!\n";
        while (true) {
            cout << "\nLevel " << level << ":\n";
    
            // Run one round of the game
            if (!gameRound(level)) {
                break; // If the player gets the question wrong, end the game
            }
    
            // Increase difficulty after each level
            level++;
    
            // Optionally, add a delay or some kind of visual cue that they're advancing
            cout << "You've moved to the next area!\n";
        }
    
    cout << "You made it to level " << level - 1 << ".\n***GAME OVER***" ;
    return 0;

}

string mainMenu(){
    string choice;
    cout <<"\nEnter Adventure mode\nEnter Study Mode\nQuit"<< endl;
    cout <<"(Enter with Cap letters)" << endl;
    cin>> choice;
    if (choice == "Adventure" || choice == "A" || choice == "Adventure Mode")
    {
        entranceHall();
    }
    else if (choice == "Study " || choice == "S" || choice == "Study Mode"){
        gameRound();
    }
    else if (choice == "Quit" || choice == "Q"){
        main();
    }
    else{
        cout << "Invalid Option... Try Again";
        mainMenu();
    }
    return choice;
}

int generateMathQuestion(int level) {
    int answer = a + b;

    //When the direction is pick a certain math equation is choosen
    switch (choice) {
        case 1: // Addition
            a = rand() % (additionDifficulty * 10);
            b = rand() % (additionDifficulty * 10);
            answer = a + b;
            cout << "What is " << a << " + " << b << "? ";
            break;
        case 2: // Multiplication
            a = rand() % (multiplicationDifficulty * 10);
            b = rand() % (multiplicationDifficulty * 10);
            answer = a * b;
            cout << "What is " << a << " * " << b << "? ";
            break;
        case 3: // Subtraction
            a = rand() % (subtractionDifficulty * 10);
            b = rand() % (subtractionDifficulty * 10);
            answer = (a > b) ? a - b : b - a;
            cout << "What is " << max(a, b) << " - " << min(a, b) << "? ";
            break;
        case 4: // Division
            a = rand() % (divisionDifficulty * 10) + 1;  // Avoid division by zero
            b = rand() % (divisionDifficulty * 5) + 1;  
            answer = a / b;
            cout << "What is " << a << " / " << b << "? (Rounded to nearest whole number) ";
            break;
        default{
            break;
        }
    }

    return answer;
}

// displays the direction chooces to the player
void printDirectionChoices() {
    cout << "Choose a direction to go:\n";
    cout << "1. North\n";
    cout << "2. East\n";
    cout << "3. South\n";
    cout << "4. West\n";
    cout << "5. Quit\n";
}

bool gameRound(int level) {
    // Show direction choices
    printDirectionChoices();

    // Get player's direction choice
    int choice;
    cout <<"Enter 5 to exit" << endl;
    cout << "Enter your choice (1-4): ";
    cin >> choice;
    if (choice <0 || choice > 5){
        cout << "Invalid Option... Try Again" << endl;
        printDirectionChoices();
    }
    else if(choice == 5){
       
    }
    // Generate math question for this round
    int correctAnswer = generateMathQuestion(level);

    // Get player's answer to the math question
    int playerAnswer;
    cout << "Your answer: ";
    cin >> playerAnswer;

    // Check if the answer is correct
    if (playerAnswer != correctAnswer) {
        cout << "\nIncorrect! The correct answer was " << correctAnswer << ".\n";
        return false;
    }

    cout << "\nCorrect! You move " << (choice == 1 ? "North" : (choice == 2 ? "East" : (choice == 3 ? "South" : "West"))) << ".\n";
    return true;
}
