#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    
    // Varible bank.
    float game_1;
    float game_2;
    float game_3;
    float game_4;
    float game_5;
    float game_6;
    float game_7;
    float game_8;
    float game_9;
    float total_1;
    float total_2;
    float total_3;
    float total_cost;
    float average;
    string month;


    // User inputs and calculations
    cout << "\n\n\nEnter the month: ";
    cin >> month;
    cin.ignore();

    cout << "\nPrice of Game 1: $";
    cin >> game_1;
    cout << "\nPrice of Game 2: $";
    cin >> game_2;
    cout << "\nPrice of Game 3: $";
    cin >> game_3;

    // Total of all three games for the month.
    total_1 = game_1 + game_2 + game_3;

    cout << "\nTotal cost of all three games for " << month << ": $" << total_1;
    
    // User inputs and calculations
    cout << "\n\n\nEnter the month: ";
    cin >> month;
    cin.ignore();

    cout << "\nPrice of Game 1: $";
    cin >> game_4;
    cout << "\nPrice of Game 2: $";
    cin >> game_5;
    cout << "\nPrice of Game 3: $";
    cin >> game_6;

    // Total of all three games for the month.
    total_2 = game_4 + game_5 + game_6;

    cout << "\nTotal cost of all three games for " << month << ": $" << total_2;
    

    // User inputs and calculations   
    cout << "\n\n\nEnter the month: ";
    cin >> month;
    cin.ignore();

    cout << "\nPrice of Game 1: $";
    cin >> game_7;
    cout << "\nPrice of Game 2: $";
    cin >> game_8;
    cout << "\nPrice of Game 3: $";
    cin >> game_9;

    // Total of all three games for the month.
    total_3 = game_7 + game_8 + game_9;

    cout << "\nTotal cost of all three games for " << month << ": $" << total_3;
    


    // Total cost for all three months and the average cost.
    total_cost = total_1 + total_2 + total_3;
    average = total_cost /9;


    // Output results.
    cout << "\n\nTotal amount spent over the three months: $" << total_cost;
    cout << "\nAverage price per game: $" << setprecision(4) << average << endl;


return 0;
}