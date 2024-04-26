#include <iostream>
#include <iomanip>
using namespace std;


int main() {

    // Varible bank.
    int todes;
    int houses;

    // Gathering data.
    cout << "\n\nEnter the number of nematodes tamed:" << setw(2) << "";
    cin >> todes;
    cin.ignore();

    // Calculation
    houses = todes /5;

    // Output
    cout << "\nNumber of nematodes that will be assigned to each of the 5 houses:  " << houses << "\n\n";
    
return 0;
}