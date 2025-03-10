//CSC 134
//M4T1 - loops
//Cunningham
//3/10/2025

#include <iostream>
using namespace std;

int main()
{
    // Part 1 - just count
    int count = 1;
    while(count <= 5) {
        cout << "Hello #" << count << endl;
       // count = count + 1;
        //count+= 1;
        count++; // all the same thing
    }
    cout << "Finished" << endl;

    // Part 2 table of squares
    const int MIN_NUM =1;
    const int MAX_NUM = 20;
    int num = MIN_NUM;
    int sq;
    cout <<endl << "Table of Squares" << endl;
    cout << "-------------------"<< endl;
    while (num <= MAX_NUM){
        sq = num + num;
        cout << num << "\t" << sq << endl;
        num = num + 1;
    }
// My Part
/*
    bool is_valid = false;
    
    while (is_valid == false){
        int choice;
        cout<<"pick 1 or 2";
        cin >> choice;
        if (choice==1){
            is_valid = true;
        }
        else if(choice ==2 ){
            is_valid = false;
        }
        else{
            cout <<"Try again" ;
        }
        return is_valid;
*/
    return 0; // no errors
}
