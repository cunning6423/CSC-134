// M3T2 starting point



#include <iostream>
// for random
#include <cmath>    
#include <ctime>
using namespace std;

int main() {
    const int SIDES = 10; // yours will differ!
    //int seed = 38;
    int seed = time(0);
    cout << "seed is:" << seed << endl; 
    // seed the random number generator
    srand(seed);
    // rand() is a large number, so we take the remainder which is %
    int roll1, roll2, total;
    // roll a few times
    roll1 = ( (rand() % SIDES)+1 );
    cout << roll1 << endl;

    roll2 = ( (rand() % SIDES)+1 );
    cout << roll2 << endl;

    //total = roll1 + roll2; // This is simple addtion
    total = (roll1 * 10) + roll2; // This is a 100 die roll
    cout <<"The total of the roll is " << total << endl;

}