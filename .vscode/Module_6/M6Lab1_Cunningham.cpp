/*
CSC 134
M6Lab1 - Buckshot Roulette
Cunningham
4/21/25
*/

#include <vector>
#include <iostream>
using namespace std;

int main (){
    //The magazine contains a mix of red and black shells.
    const int BLANK = 0;
    const int LIVE = 1;
    const int EMPTY = -1;
    
    string shellNames[] = {"Blank", "Live", "Empty"};

    // example one: Using a basic array

    int magazine[] = {BLANK, LIVE, BLANK, LIVE};
    // For each shell in magazine
    for (int shell : magazine) {
        string name = shellNames[shell];
        cout <<"Next Shell: " << name <<endl;
    }
    // Example 2: using STL Vector (An STL Vector is an array that automatcly gets more space if prompted)
    cout <<endl<< "Example 2:" << endl;
    vector<int> mag;
    // load the mag
    mag.push_back(BLANK);
    mag.push_back(LIVE);
    mag.push_back(LIVE);
    mag.push_back(LIVE);

    for (int shell:mag){
        string name = shellNames[shell];
        cout <<"Next Shell: " << name << endl;
    }
}