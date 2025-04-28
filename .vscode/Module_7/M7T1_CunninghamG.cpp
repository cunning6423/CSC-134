#include <iostream>
using namespace std;

// CSC 134
// M7T1 - Restaurant Rating
// CunninghamG
// 4/28/24
// Use Restaurant class to store user ratings

// Next time we'll put the class in a separate file
class Restaurant {
  private:
    string name;    // the name
    double rating;  // 0 to 5 stars

  public:
  //empty constructor
    Restaurant(){
        //does nothing
    }
	// constructor 
	Restaurant(string n, double r) {
		name = n;
		rating = r;
	}
	// getters and setters
    void setName(string n) {
        name = n; 
    }
    void setRating(double r) {
        rating = r;
    }
    string getName() const {
        return name;
    }
    double getRating() const {
        return rating;
    }
    // Display the void main
    void showInfo(){
        cout << "Restaurant Name: " << name << endl;
        cout << "Rating: " << rating <<"/5" << endl;
    }
  
};

int main() {
    cout << "M7T1 - Restaurant Reviews" << endl;
    // First create a resterrant
    Restaurant rest1= Restaurant("Marco's pizza", 4);

    // next ask the user to enter one
    Restaurant rest2 = Restaurant();
    cout << "Restaurant Name: ";
    string name;
    double rating;

    // this is how you get a name containg spaces
    getline(cin, name);
    cout <<"Resaurant Rating: ";
    cin >> rating;
    rest2.setName(name);
    rest2.setRating(rating);

    // Finally, show all the data
    cout <<"---------" << endl;
    rest1.showInfo();
    rest2.showInfo();
    return 0;

}