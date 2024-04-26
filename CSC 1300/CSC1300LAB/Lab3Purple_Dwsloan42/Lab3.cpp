#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

// Varible bank. 
string comp_a;
string comp_b;
string comp_c;
string vech_a;
string vech_b;
string vech_c;
string job_1;
int pick_1;
int salery;
int num_1;
string lineOfStars(79, '*');

// Intro.
cout << lineOfStars << endl;
cout << "JOB FORECAST" << endl;
cout << lineOfStars << endl;


// seeding the random number gen.
srand((unsigned) time(NULL));
	
int random_1 = rand() % 100;

int random_2 = rand() % 10;



// outputs and user inputs.
cout << "Enter in the information requested below and I will determine the job you will\nget, how many years you will work there, your salary, and the company car you\nwill drive." << endl;

cout << "\nCompany you like: ";
getline(cin,comp_a);

cout << "\nAnother company you like: ";
getline(cin,comp_b);

cout << "\nCompany you hate: ";
getline(cin,comp_c);


cout << "\n\nVehicle you like: ";
getline(cin,vech_a);

cout << "\nAnother vehicle you like: ";
getline(cin,vech_b);

cout << "\nVehicle you hate: ";
getline(cin,vech_c);


cout << "\n\nPick an integer between 1 to 25 (inclusively): ";
cin >> num_1;

salery = num_1 * 10000.00 * random_2;



// Picking job and case based on user input.
if (num_1 >= 20) {
    job_1 = comp_a;
    pick_1 = 1;
}

else if (num_1 >= 7 && num_1 < 20) {
    job_1 = comp_b;
    pick_1 = 2;
}

else if ( num_1 < 7) {
    job_1 = comp_c;
    pick_1 = 3;
}



cout << "\n" << lineOfStars << endl;

switch (pick_1) {

    case 1: 
    cout << "\nYou will work at " << job_1 << " for " << fixed << setprecision(2) << random_1  << " years making $" << salery << " per year\nand drive a red " << vech_b << " on business trips." << endl;
    break;

    case 2:
    cout << "\nYou will work at " << job_1 << " for " << fixed << setprecision(2) << random_1  << " years making $" << salery << " per year\nand drive a royal blue " << vech_b << " on business trips." << endl;
    break;

    case 3:
    cout << "\nYou will work at " << job_1 << " for " << fixed << setprecision(2) << random_1  << " years making $" << salery << " per year\nand drive a royal blue " << vech_c << " on business trips." << endl;
    break;

}

cout << "\n" << lineOfStars << endl;

return 0;
}