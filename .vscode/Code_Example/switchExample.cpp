#include <iostream>
#include <iomanip>
using namespace std;


int main() {
int choice;
cin >> choice;
switch (choice)
{
case  1:
    cout << "Math";
    break;
case 2:
    cout << "Science";
    break;

default:
    cout <<"None of the above.";
    break;
}
return 0;
}