#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    // Intro to the program.
    cout << "\n\n\n********** Puppy Food Cost Calculator **********\n\n";
    // Varible bank.
    int cup = 2;
    int puppy;
    int day;
    int week;
    int cost = 3;
    
    // Gathering data.
    cout << "Please enter the number of puppies:  ";
    cin >> puppy;
    cin.ignore();

    // Calculation
    day = puppy * cup;
    week = cost * cup * puppy *7;

    
    // Output
    cout << "\nThe amount of pet food needed per day: " << day << " cups";

    cout << "\nThe total cost of pet food per week: $" << week << "\n\n";

return 0;
}