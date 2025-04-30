/*
Final Project
Choose your own adventure
Cunningham, Gabriel
Explore the world free, however the only thing that blocks you way MATH!!!
*/

#include <iostream>
#include <string> // allows for pop ups
#include <cstdlib>
#include <ctime>
using namespace std;

void printMilestone(int level); 
int generateMathQuestion(int choice, int level, int aD, int mD, int sD, int dD); // Generates math question when called
void printDirectionChoices(); // Display the list of actions
bool gameRound(int choice, int aD, int mD, int sD, int dD); // each round of the game.
string mainMenu();

/*
New Idea for the code. 
Create a fuction that allows for an event chance; the main chance is heading to the next floor,
other even could occur that will cause certain math problem to get way harder.
However the next floor chance get bigger the longer a player is on a floor.
*/

int main()
{
    srand(time(0));  // Initialize random seed
    int level = 1;  // Game starts at level 1
    int choice; // the direction input variable
    int aD = 1; //additionDifficulty
    int sD = 1; //subtractionDifficulty
    int mD = 1; //multiplicationDifficulty
    int dD = 1; //divisionDifficulty
    cout << "Welcome to the Walking Upstairs Game!\n";
    // Only go up a level after they pass the find stairs event to head to the next floor.
        while (true) {
            cout << "\nLevel " << level << ":\n";
    
            // Run one round of the game
            if (!gameRound(choice, aD, mD, sD, dD)) {
                break; // If the player gets the question wrong, end the game
            }
    
            // Increase difficulty after each level

            level++;
            if (level == 2){
                printMilestone(level);
            }

        }
    
    cout << "You made it to floor " << level - 1 << ".\n***GAME OVER***" ;
    return 0;

}

void printMilestone(int level){
    std::cout << "--------------------------------\n";
    std::cout << "Congratulations! You've reached floor " << level << "!\n";
    std::cout << "Prepare for the next math challenge...\n";
    std::cout << "--------------------------------\n";
}

string mainMenu(){
return 0;
}

int generateMathQuestion(int choice, int aD, int sD, int mD, int dD) {
    int answer, a,b;
    //When the direction is pick a certain math equation is choosen
    switch (choice) {
        case 1: // Addition
            a = rand() % (aD * 10);
            b = rand() % (aD * 10);
            answer = a + b;
            cout << "What is " << a << " + " << b << "? ";
            break;
        case 2: // Multiplication
            a = rand() % (mD * 10);
            b = rand() % (mD * 10);
            answer = a * b;
            cout << "What is " << a << " * " << b << "? ";
            break;
        case 3: // Subtraction
            a = rand() % (sD * 10);
            b = rand() % (sD * 10);
            answer = (a > b) ? a - b : b - a;
            cout << "What is " << max(a, b) << " - " << min(a, b) << "? ";
            break;
        case 4: // Division
            a = rand() % (dD * 10) + 1;  // Avoid division by zero
            b = rand() % (dD * 5) + 1;  
            answer = a / b;
            cout << "What is " << a << " / " << b << "? (Rounded to nearest whole number) ";
            break;
        default : {
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

bool gameRound(int choice, int aD, int mD, int sD, int dD) {
    // Show direction choices
    printDirectionChoices();
    
    // Get player's direction choice
    cout << "Enter your choice (1-5): ";
    cin >> choice;
    switch(choice) {
        case 1: // North (Addition)
            aD++;
            break;
        case 2: // East (Multiplication)
            mD++;
            break;
        case 3: // South (Subtraction)
            sD++;
            break;
        case 4: // West (Division)
            dD++;
            break;
        case 5: // Quit Screen
            break;
    }
    if(choice != 5) {
            // Generate math question for this round
        int correctAnswer = generateMathQuestion(choice, aD, mD, sD, dD);

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
    else if (choice == 5){
        cout <<"You have quit!\n" << endl;
    }
}
