#include <iostream>
#include <iomanip>
using namespace std;


int main() {
int choice;
cin >> choice;
switch (choice)
{
case  1:
    cout << "1";
    break;
case 2:
    cout << "2";
    break;

default:
    cout <<"None of the above.";
    break;
}
return 0;
}