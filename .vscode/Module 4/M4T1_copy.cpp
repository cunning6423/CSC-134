//CSC 134
//M4T1 - outpuing loops
//Cunningham
//3/10/2025

#include <iostream>
#include <fstream>
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
    const int MAX_NUM = 1000;
    int num = MIN_NUM;
    unsigned long sq;
    string fileName = "square.txt";
    ofstream outfile(fileName);
    if (false == outfile.is_open()){
        cout << "Error: could not open " << fileName << endl;
        return -1; // error
    }

    //wrtie the table to a file
    outfile << "Table of Squares" << endl;
    outfile << "-------------------"<< endl;
    while (num <= MAX_NUM){
        sq = num + num;
        outfile << num << "\t" << sq << endl;
        num = num + 1;
    }
    // close the file
    outfile.close();
    return 0; // no errors
}