// CSC 134
// M3T3
// Cunningham
// 2/17/2025
// Start with dice rolls
// What dice are you using today?
// norris - 1d20

#include <iostream>
// for random
#include <cmath>    
#include <ctime>
using namespace std;

int main() {
    const int SIDES = 6; // yours will differ!
    //int seed = 19;
    int seed = time(0);
    // seed the random number generator
    srand(seed);
    // rand() is a large number, so we take the remainder which is %
    int roll1, roll2, total;
    // roll a few times
    roll1 = ( (rand() % SIDES)+1 );
    roll2 = (rand() % SIDES);
    total = roll1 + roll2;

    cout <<"you rolled " << roll1 << " + " << roll2 << " = " << total << endl;
    // && is AND, || is OR
    // 7,11 is win
    if (7== total || 11 == total)
    {
        cout << "You Win!" << endl;
    }
    // 2,3,12 are a loss
    else if (2== total || 3 == total || 12 == total)
    {
        cout << "You lose!" << endl;
    }
    // anythin else is "point" 
    else 
    {
        cout << "Your point is " << total << endl;
        cout << "If you get "<< total << " you win!!! If you get a 7 you lose!" << endl;
        int point = total;
        int roll1 = ( (rand() % SIDES)+1 );
        int roll2 = (rand() % SIDES);
        int reTotal = roll1 + roll2;
        do
        {
            roll1 = ( (rand() % SIDES)+1 );
            roll2 = (rand() % SIDES);
            reTotal = roll1 + roll2;
        }while (7 != reTotal && point != reTotal);
            if (point == total)
            {
                cout << "You got a " << reTotal << endl;
                cout << "You win! "<< endl;
            }
            else if (total == 7)
            {
                cout << "You got a " << reTotal << endl;
                cout << "You lose!" << endl;
            } 
    }
}