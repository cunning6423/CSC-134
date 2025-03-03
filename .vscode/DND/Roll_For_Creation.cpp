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
void chooseClass();
int calculateHP(const string& charClass);

int main() {
    // Seed the random number generator
    srand(time(0));
    
    // Get character details from user
    cout << "Enter character name: ";
    getline(cin, name);
    
    bool repeat;
    do {
        inputStats();
        chooseClass();
        hp = calculateHP(charClass);
        displayCharacter();
        repeat = askToRepeat();
    } while (repeat);
    
    return 0;
}
void displayCharacter() {
    cout << "\nCharacter Stats:\n";
    cout << "Level: 1" << endl;
    cout << "Class: " << charClass << endl;
    cout << "Strength: " << strength << endl;
    cout << "Dexterity: " << dexterity << endl;
    cout << "Constitution: " << constitution << endl;
    cout << "Intelligence: " << intelligence << endl;
    cout << "Wisdom: " << wisdom << endl;
    cout << "Charisma: " << charisma << endl;
    cout << "HP: " << hp << endl;
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
void chooseClass() {
    cout << "Choose your character class (e.g., Warrior, Mage, Rogue): ";
    cin >> charClass;
    }
int calculateHP(const string& charClass) {
        int baseHP = 0;
        if (charClass == "Warrior") {
            baseHP = 10;
        } else if (charClass == "Mage") {
            baseHP = 6;
        } else if (charClass == "Rogue") {
            baseHP = 8;
        } else {
            cout << "Unknown class, setting default HP.\n";
            baseHP = 5;
        }
        return baseHP + constitution; // Adjust HP based on constitution modifier
    }
void saveCharacter() {

}

