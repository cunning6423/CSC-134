// CSC 134
// M5T2
// Cunningham
// 3/24/2025

// TODO:
// add declarations
// finish the functions
// write main()
#include <iostream>
using namespace std;

int find_square(int number);
void print_line(int number, int square);

int main() {
    int number = 0;
    int runAmount = 0;
    for (int num=1; num<=10;num++){
        int square = find_square(num);
        print_line(num, square);
        
    }
}

int find_square(int number) {
    int total = number * number;
    return total;
}

void print_line(int number, int square) {
    cout << number << " squared is " << square << endl; 
}