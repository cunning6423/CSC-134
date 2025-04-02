#include <iostream>

using namespace std;

// Declare (Write the prototypes for)
// the getLength,
// getWidth, getArea, and displayData
// functions here.
double getLength();
double getWidth();
double getArea(double length, double width);
void displayData(double length,double width,double area);

int main()
{
    // This program calculates the area of a rectangle.
	// TODO: fix any syntax errors

   double length,width,area;

   // Get the rectangle's length.
   length = getLength();

   // Get the rectangle's width.
   width = getWidth();

   // Get the rectangle's area.
   area = getArea(length, width);
    cout <<endl;
   // Display the rectangle's data.
   displayData(length, width, area);
    return 0;
}

double getLength(){
    double length;
    cout <<"Enter length: ";
    cin >> length;
    return length;
}
double getWidth(){
    double width;
    cout <<"Enter width: ";
    cin >> width;
    return width;
}
double getArea(double length, double width){
    double area = length * width;
    return area;
}
void displayData(double length,double width, double area){
    cout <<"Length: " << length << endl;
    cout <<"Width: " << width << endl;
    if (length == width){
        cout <<"Area of the square: " << area << endl;
    }
    else{
        cout <<"Area of the rectangle: " << area << endl;
    }
    return;
}
