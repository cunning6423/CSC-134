// M3T2 starting point



#include <iostream>
// for random
#include <cmath>    
#include <ctime>
using namespace std;

int main() {
    const int SIDES = 10; // yours will differ!
    const int  DAMAGE_SIDE = 8;
    const int armorClass = 69;
    int damageTotal,damageRoll1, damageRoll2;

    //int seed = 38;
    int seed = time(0);
    cout << "seed is:" << seed << endl; 
    // seed the random number generator
    srand(seed);
    // rand() is a large number, so we take the remainder which is %
    int roll1, roll2, hitTotal;

    // roll a few times
    roll1 = ( (rand() % SIDES)+1 );
    cout << roll1 << endl;

    roll2 = ( (rand() % SIDES)+1 );
    cout << roll2 << endl;

    //total = roll1 + roll2; // This is simple addtion
    hitTotal = (roll1 * 10) + roll2; // This is a 100 die roll
    cout <<"The total of the roll is " << hitTotal << endl;

    if (hitTotal == 100)
    {
        cout << "You hit a critcal " << endl;
    }
    else if (hitTotal >= armorClass)
    {
        cout<<"You hit" << endl;
        damageRoll1 = ( (rand() % DAMAGE_SIDE)+1 );
        damageRoll2 = ( (rand() % DAMAGE_SIDE)+1 );
        damageTotal = damageRoll1 + damageRoll2 + 3;
        cout << " You have done " << damageTotal << " damage" << endl;
    }
    else if (1<= hitTotal <= armorClass)
    {
        cout<< "You missed" << endl;
        //cout <<"Would you like to try again!!" << endl;
    }
    else if (hitTotal == 1)
    {
        cout<<"Critcal failure" << endl;
        damageRoll1 = ( (rand() % DAMAGE_SIDE)+1 );
        damageRoll2 = ( (rand() % DAMAGE_SIDE)+1 );
        cout << damageRoll1 << endl;
        damageTotal = damageRoll1 + damageRoll2 + 3;
        cout<< "You hit yourself for " << damageTotal << endl;
    }

}