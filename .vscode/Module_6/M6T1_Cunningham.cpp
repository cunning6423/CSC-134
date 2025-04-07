/*
CSC- 134
M6T1 - Arrays
Cunningham
4/7/2025
*/
#include <iostream>
using namespace std;

int main(){
    const int SIZE = 3;
    int nums[SIZE];
    int count;

    // We have six stats, names
    const int NUM_STATS = 6;
    const int STR = 0;
    const int DEX = 1;
    const int CON = 2;
    const int INT = 3;
    const int WIS = 4;
    const int CHA = 5;

    //other variable
    string characterName;
    int stats[NUM_STATS];
    string statNames[] = {"STR", "DEX", "CON", "INT", "WIS", "CHA"};
    int currentStat; // User input
    double totalStats;
    double averageStats;
    cout <<"Please input Character stats" <<endl;
    cout << "Enter Character Name: ";
    cin >> characterName; 
    for(int i = 0; i < NUM_STATS; i++)
    {
        cout << "Stat (" << statNames[i] << "): ";
        cin >> currentStat;
        stats[i] = currentStat;
        totalStats+=currentStat;
    }
    cout <<endl;
    //Find total and Average
    averageStats = totalStats / NUM_STATS;
    cout << "Total: " << totalStats << " Average: " << averageStats << endl;
    cout << "Character Sheet: " << characterName <<endl; 
    //output
    for(int i = 0;i < NUM_STATS; i++){
        cout << statNames[i] << ": " << stats[i] << endl;
    }
}