#ifndef GAME_DIALOGUE_H
#define GAME_DIALOGUE_H

#include <iostream>
#include <cstdlib>
#include <ctime>

/*
Change this basic completely
Other cool rust fun stuff to play with


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

// Utility to get random roast
string getRandomRoast(const string& mode) {
    vector<string> safeRoasts = {
        "Failsafe Mode: Always, huh? Planning to play the whole game with training wheels?",
        "You chose safety over adventure. I hope your calculator has a juice box.",
        "Failsafe Always? Bold strategy, Cotton. Let's see if it pays off."
    };
    vector<string> noRoasts = {
        "Failsafe None? Brave... or incredibly reckless. Let's find out.",
        "No failsafe? You must have a PhD in overconfidence.",
        "Failsafe None... Did you read the warning label, or just eat it?"
    };

    int index = rand() % 3;
    return (mode == "always") ? safeRoasts[index] : noRoasts[index];
}

void mathChallenge(string question, int correctAnswer) {
    int answer;
    cout << question << "\nYour answer: ";
    cin >> answer;

    if (answer == correctAnswer) {
        cout << "Correct! The path ahead shimmers with digital static...\n";
    } else {
        cout << "Wrong. The glitch tower laughs in binary. Try again.\n";
        mathChallenge(question, correctAnswer);
    }
}

void chooseDirection() {
    cout << "\nYou stand in a broken digital corridor. Which way?\n";
    cout << "1. North\n2. South\n3. East\n4. West\n";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "\n[NORTH] You walk into a room with floating numbers...\n";
            mathChallenge("What is 8 * 7?", 56);
            break;
        case 2:
            cout << "\n[SOUTH] A screen flickers to life with a riddle...\n";
            mathChallenge("What is 15 / 3?", 5);
            break;
        case 3:
            cout << "\n[EAST] A robotic voice asks you to proceed.\n";
            mathChallenge("What is 9 + 6?", 15);
            break;
        case 4:
            cout << "\n[WEST] You stumble upon a looping algorithm...\n";
            mathChallenge("What is 12 - 4?", 8);
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            chooseDirection();
            break;
    }
}

void selectFailsafe() {
    cout << "\nSelect a failsafe mode:\n";
    cout << "1. Always (never fail)\n2. None (no second chances)\n";
    int modeChoice;
    string mode;

    cin >> modeChoice;
    if (modeChoice == 1) {
        mode = "always";
    } else if (modeChoice == 2) {
        mode = "none";
    } else {
        cout << "Invalid choice. Try again.\n";
        selectFailsafe();
        return;
    }

    cout << getRandomRoast(mode) << "\n";
}

void intro() {
    cout << "== GLITCH TOWER: MATH ASCENT ==\n";
    cout << "You awaken inside a fragmented virtual space known as the Glitch Tower.\n";
    cout << "A voice echoes: 'Welcome, User. Your objective: reach the top. Solve or dissolve.'\n";
    cout << "The narrator snickers... 'And try not to embarrass yourself too hard.'\n";
}

int main() {
    srand(time(0)); // Random seed
    intro();
    selectFailsafe();
    chooseDirection();

    cout << "\nTo be continued... (Add more floors to expand the tower)\n";
    return 0;
}

*/
// Utility to get random roast based on fail-safe mode
std::string getRandomRoast(const std::string& failSafeMode) {
    std::vector<std::string> safeRoasts = {
        "Failsafe Mode: Always, huh? Planning to play the whole game with training wheels?",
        "You chose safety over adventure. I hope your calculator has a juice box.",
        "Failsafe Always? Bold strategy, Bud. Let's see if it pays off.",
        "Usable anytime? Wow, someone’s feeling like a freeloader today."
    };
    std::vector<std::string> noRoasts = {
        "Failsafe None? Brave... or incredibly reckless. Let's find out.",
        "No failsafe? You must have a PhD in overconfidence.",
        "Failsafe None... Did you read the warning label, or just eat it?",
        "No fail-safes? Alright, you do you. Let’s see how that works out for you."
    };

    int index = rand() % 4;
    if (mode == "always") {
        return safeRoasts[index];
    } else {
        return noRoasts[index];
    }
}

// Function to print random roasts and dialogue when the player chooses a fail-safe mode
std::string printFailSafeDialog(int failSafes, const std::string& failSafeMode) {
    switch (fmodeSelect) {
        case 1:
            std::cout << "\nOh, starting off safe, huh? I hope you have a *good* reason for that.\n";
            return "basic";
        case 2:
            std::cout << "\nAh, a challenge. You want the fail-safes, but only after you’ve *earned* them? Bold move, friend.\n";
            return "reverse";
        case 3:
            std::cout << getRandomRoast(failSafeMode) << std::endl;
            return "always";
        default:
            std::cout << getRandomRoast("none") << std::endl;
            return "none";
    }
}

// Function to print end screen dialogue with 4th-wall breaking commentary
void printEndScreen(int level) {
    std::cout << "--------------------------------\n";
    std::cout << "Congratulations! You've reached floor " << level << "!\n";
    std::cout << "You have completed the challenge...\n";

    if (level < 10) {
        std::cout << "Not bad, but you're still not quite at the top... Try harder next time!\n";
    } else {
        std::cout << "You made it! You’re a math wizard now. Who knew numbers could be this... fun?\n";
    }

    std::cout << "\tGOOD JOB\n";
    std::cout << "--------------------------------\n";
}

// Function to print random roast when the player fails a math question
void failRoastDialog(int failSafes, const std::string& failSafeMode) {
    if (failSafeMode == "none" || failSafes <= 0) {
        std::cout << "Oops, no failsafes left. Guess that's it, buddy.\n";
    } else {
        std::cout << "You really thought that was the answer? Here's a hint: math is not just about numbers, it's about making *choices*.\n";
        std::cout << "You still have " << failSafes << " fail-safes left... but for how long?\n";
    }
}

// Function to print a random dialogue for the player when they use a fail-safe
void failSafeUsed(int& failSafes) {
    if (failSafes > 0) {
        failSafes--;
        std::cout << "You used a fail-safe! You still continue. (" << failSafes << " left)\n";
        std::cout << "You know, it's almost like you’re treating this like a 'get-out-of-jail-free' card. Lazy, but sure, go ahead.\n";
    }
}

// Function to print random jokes/remarks about the player's progress in the game
void progressRoast(int level) {
    if (level == 1) {
        std::cout << "Alright, level 1... no pressure. It's just math, right? You've got this.\n";
    } else if (level == 5) {
        std::cout << "Wow, halfway there! Let me guess... you’re probably getting cocky now?\n";
    } else if (level == 10) {
        std::cout << "Level 10?! Look at you! I’m *so* impressed... Not bad, not bad at all.\n";
    } else if (level == 20) {
        std::cout << "Oh, you made it to level 20? I didn’t know math was your thing! Guess you’re one of those *genius* types.\n";
    } else {
        std::cout << "Hey, you’re doing better than most, so… Good job? Maybe? Keep it up.\n";
    }
}

// Random joke about quitting the game
void quittingJoke() {
    std::cout << "You know, quitting isn't always the answer... but hey, you do you. Maybe math just isn't your thing. \n";
    std::cout << "Bye... I guess?\n";
}

#endif // GAME_DIALOGUE_H
