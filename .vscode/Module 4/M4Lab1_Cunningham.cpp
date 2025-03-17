//CSC 134
//M4T1 - grid fpr loop
//Cunningham
//3/17/2025

#include <iostream>
using namespace std;

int main(){
    string pattern = "🙂🙏";
    //string pattern
    int count = 0;
    const int WIDTH = 8;
    const int HEIGHT = 5;
    //while loop version
    /*
    while(count < WIDTH){
        count++;
    }
    cout << endl;

    // print a row (horizontal)
    cout << "row" << endl;
    for (int i = 0; i < WIDTH; i++){
        cout << pattern;
    }
    cout << endl;
    // print a row (vertically)
    cout << "column" << endl;
    for (int i = 0; i  < HEIGHT; i++){
        cout << pattern << endl;
    }
    */
    int width, height;
    bool goodValues = false;

    do
    {
        cout << "Enter the desired amount of rows:";
        cin >> width;
        cout << endl;
        cout <<"Enter the desired amunt of columns: ";
        cin >> height;
        cout << endl;    
        if (width > 0 && height << 0){
            goodValues = true;
        }
    } while (goodValues=false);// loop until we get desired values

    // print a square (combine both)
    cout << "Square of " << width <<" by " << height<< endl;
    for (int v=0; v<height; v++){
        //print one row
        for (int w =0; w<width;w++){
            cout << pattern;
        }
        cout << endl; // got to next row
    } 
}