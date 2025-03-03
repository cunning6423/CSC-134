#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Global variables for character stats
int strength, dexterity, constitution, intelligence, wisdom, charisma;
string name, charClass;
int level, hp;

// Function prototypes (declartions)
// You have to "declare" the function first because it is run from top to bottom.
void inputStats();
void displayCharacter();
void saveCharacter();
int rollDice();
int rollStat();
bool askToRepeat();

int main() {
    // Seed the random number generator
    srand(time(0));
    
    // Get character details from user
    cout << "Enter character name: ";
    getline(cin, name);
    cout << "Enter character class: ";
    getline(cin, charClass);
    
    bool repeat;
    do {
        inputStats();
        displayCharacter();
        repeat = askToRepeat();
    } while (repeat);
    
    return 0;
}
int rollDice() {
    return rand() % 6 + 1;
}
int rollStat() {
    //roll 3d6
    int stat;
    stat = rollDice()+rollDice()+rollDice();
    return stat;
}
bool askToRepeat() {
    char choice;
    cout << "Do you want to accept these stats or reroll the stats? (a/n): ";
    cin >> choice;
    return (choice == 'a' || choice == 'A');
}
// function definition (the full function)
void inputStats() {
    strength = rollStat();
    dexterity = rollStat();
    constitution = rollStat();
    intelligence = rollStat();
    wisdom = rollStat();
    charisma = rollStat();
}

void displayCharacter() {
    cout << "\nCharacter Stats:\n";
    cout << "Strength: " << strength << endl;
    cout << "Dexterity: " << dexterity << endl;
    cout << "Constitution: " << constitution << endl;
    cout << "Intelligence: " << intelligence << endl;
    cout << "Wisdom: " << wisdom << endl;
    cout << "Charisma: " << charisma << endl;
}
void saveCharacter() {

}

