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
#include <limits>
//#include "game_dialogue.h"
using namespace std;

//Displays milestone that congratulates the player
void printMilestone(int level); 
// Display the list of actions
void printDirectionChoices();
// Display and end screen
void printEndScreen(int level);
// Generates math question when called
int generateMathQuestion(int choice, int level, int aD, int mD, int sD, int dD);  
// Runs each round of the game.
bool gameRound(int choice,int level ,int aD, int mD, int sD, int dD, int &failSafes, string failSafeMode); 
// Function that changes that randomizes events
bool eventRound(int roundsOnFloor, bool &foundStairs, int &levelChange, int level, int &failSafes);
// Function that return the desired fail safe mode
string printFailSafe();
string mainMenu();

/*
Event ideas: 
The events are fractional or decimal answer that will boost you or glich you to a lower floor but same diffculty questions.
If you get sent down a floor on the frist floor into the negatives 1. the game is reverse, 2. Instant win, 3. Extreme difficulty, or 1 and 3.

Create lore and a back ground page on the main menu

Create an end screen

More code ideas:
Depending the direction the equation will get harder faster and their will be more of a reward.
Can win more death saves or less questions until the next floor.
If they answer more questions right then multiple time in a row the chance get higher.
*/

int main()
{
    srand(time(0));         // Initialize random seed
    int level = 1;          // Game starts at level 1
    int choice;             // The direction input variable
    int aD = 1;             // Addition Difficulty
    int sD = 1;             // Subtraction Difficulty
    int mD = 1;             // Multiplication Difficulty
    int dD = 1;             // Division Difficulty
    int roundsOnFloor = 0;  // Amount of questions answered on that floor
    int failSafes = 0;      // Amount of failsafes
    string failSafeMode;    // Choosing the mode
    
    cout << "Welcome to Glitchuations!\n";
    
    failSafeMode = printFailSafe(); // Determines fail safe mode
    if (failSafeMode == "basic") {failSafes = 3;}

    // Only go up a floor after the stairs are found.
        while (true) {
            cout << "\nFloor " << level << ":\n";

            // Resets fail safes to 1
            if (failSafeMode == "always") {failSafes = 1;}
    
            // Run one round of the game
            if (!gameRound(choice,level, aD, mD, sD, dD, failSafes, failSafeMode)) {
                break;
            }
            
            // The stairs haven't been found
            bool foundStairs = false;
            // After the stairs have been found go up one floor.
            int levelChange = 0;
            // Random Event
            eventRound(roundsOnFloor, foundStairs, levelChange, level, failSafes);

            //Check if stairs have been found
            if (foundStairs || levelChange != 0) {
                level += levelChange; // Head to the next floor
                if (level < 1) ;
                printMilestone(level);
                roundsOnFloor = 0;
            } else {
                roundsOnFloor++; // I just need this to sync code...
            }

        }
    
    cout << "\nYou made it to floor " << level << ".\n***GAME OVER***" <<endl;
    printEndScreen(level);
    return 0;

}

void printMilestone(int level){
    std::cout << "--------------------------------\n";
    std::cout << "Congratulations! You've reached floor " << level << "!\n";
    std::cout << "Prepare for the next math challenge...\n";
    std::cout << "--------------------------------\n";
}

void printEndScreen(int level){
    std::cout << "--------------------------------\n";
    std::cout << "Congratulations! You've reached floor " << level << "!\n";
    std::cout << "You have completed the challege...\n";
    std::cout << "\tGOOD JOB\n";
    std::cout << "--------------------------------\n";
}
string mainMenu(){return 0;}


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
            if ( a > b)  {
                answer = a - b;
                cout << "What is " << a << " - " << b << "? (Rounded to nearest whole number) ";
            }else{
                answer = b - a;
                cout << "What is " << b << " - " << a << "? (Rounded to nearest whole number) ";
            }
            break;
        case 4: // Division
            a = rand() % (dD * 10) + 1;  // Avoid division by zero
            b = rand() % (dD * 5) + 1;
            if ( a > b)  {
                answer = a / b;
                cout << "What is " << a << " / " << b << "? (Rounded to nearest whole number) ";
            }else{
                answer = b / a;
                cout << "What is " << b << " / " << a << "? (Rounded to nearest whole number) ";
            }
            
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
string printFailSafe() {
    cout << "\nChoose your fail-safe mode:\n";
    cout << "1. 3 at the beginning (basic)\n";
    cout << "2. 3 only after floor 5 (reverse)\n";
    cout << "3. Usable anytime (always)\n";
    cout << "4. No fail-safes (none)\n";
    int fmodeSelect;
    cout <<"Enter mode: ";
    cin >> fmodeSelect;

    switch (fmodeSelect) {
        case 1: return "basic";
        case 2: return "reverse";
        case 3: return "always";
        default: return "none";
    }
}

bool gameRound(int choice,int level, int aD, int mD, int sD, int dD, int &failSafes, string failSafeMode) {
    // Show direction choices
    printDirectionChoices();
    
    // Get player's direction choice
    cout << "Enter your choice (1-5): ";
    cin >> choice;

    // Input validation for invalid choices
    while (cin.fail() || choice < 1 || choice > 5) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input. Please enter a number between 1 and 5: ";
        cin >> choice;
    }

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
        default: // input validation
            cout << "Invalid Option...Try again" << endl;
            break;
        }
    if(choice != 5) {
            // Generate math question for this round
        int correctAnswer = generateMathQuestion(choice, aD, mD, sD, dD);

        // Get player's answer to the math question
        int playerAnswer;
        cout << "Your answer: ";
        cin >> playerAnswer;

        // Input validation for non-integer input
        while (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a valid number for your answer: ";
            cin >> playerAnswer;
        }

        // Check if the answer is correct
        if (playerAnswer != correctAnswer) {
            cout << "\nIncorrect! The correct answer was " << correctAnswer << ".\n";
            // Handle fail-safe based on the mode
            if (failSafeMode == "none" || failSafes <= 0) {
                return false;  // Game ends because no fail-safes and answer is wrong
            } else {
                // Use a fail-safe if available
                if (failSafes > 0) {
                    failSafes--;
                    cout << "You used a fail-safe! You still continue. (" << failSafes << " left)\n";
                    return true; // Continue the game
                }
            }
        }
        return true;
    }
    else if (choice == 5){
        cout <<"You have quit!\n" << endl;
        return false;
    }

}

bool eventRound(int roundsOnFloor, bool &foundStairs, int &levelChange, int level, int &failSafes){
    int chance = rand() % 100;  // 0–99
    int stairsChance = 10 + (roundsOnFloor * 5); // increases 5% per round on same floor
    //Depending on floor the chance is more likely
    if (!gameRound(choice,level, aD, mD, sD, dD, failSafes, failSafeMode)){
        if (level == 1){
            stairsChance = 10 + (roundsOnFloor * 50); // increases 60% per round on same floor
        }else if(level == 2){
            stairsChance = 10 + (roundsOnFloor * 40); // increases 50% per round on same floor
        }else if(level == 3){
            stairsChance = 10 + (roundsOnFloor * 30); // increases 30% per round on same floor
        }else if(level == 4){
            stairsChance = 10 + (roundsOnFloor * 25); // increases 25% per round on same floor
        }else if(level == 5){
            stairsChance = 10 + (roundsOnFloor * 20); // increases 20% per round on same floor
        }else if(level == 6){
            stairsChance = 10 + (roundsOnFloor * 15); // increases 15% per round on same floor
        }else if(level == 7){
            stairsChance = 10 + (roundsOnFloor * 10); // increases 10% per round on same floor
        }else if(level == 8){
            stairsChance = 10 + (roundsOnFloor * 5); // increases 5% per round on same floor
        }else if(level == 9){
            stairsChance = 5 + (roundsOnFloor * 5); // increases 2.5% per round on same floor
        }else{
            stairsChance = 2 + (roundsOnFloor * 5); // increases 7ish% per round on same floor
        }
    } else {
        foundStairs = false;
        levelChange = 0;
        return false;
    }
    

    if (chance < stairsChance) {
        foundStairs = true;
        levelChange = 1;
        cout << "\nYou found stairs to the next floor!\n";
        return true;
    }
    int glitch = chance + 5;
    if (glitch <= 15) {
        levelChange = (rand() % 2 == 0) ? 1 : -1; // same as an if statement
        cout << "\nYou stepped on a glitch tile! You " 
             << (levelChange > 0 ? "boosted up" : "fell") 
             << " a level.\n";
        foundStairs = false;
        return true;
    } 
    else if (glitch <=30){ // You can lose a fail safe or gain a fail safe.
        glitch = rand() % 2;
        cout <<"\nYour body warps, you feel like you"
        << (glitch > 0 ? " can " : " can't " )
        <<"fail another time.\n";
        // Determines if you lose or gain a fail safe.
        if (glitch > 0){failSafes = failSafes + 1; } 
        else {failSafes = failSafes - 1;}
    }

    foundStairs = false;
    levelChange = 0;
    return false;  // no event
}