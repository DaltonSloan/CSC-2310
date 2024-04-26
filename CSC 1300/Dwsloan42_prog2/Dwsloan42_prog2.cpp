/*

Title: Dwsloan_prog2.cpp
Author: Dalton W. Sloan
Date: 8 March 2023
Purpose: Predict users future.

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
// Menu function.
int displayMenuGetChoice(int);



// Main function
int main() 
{
    // Variable bank.
    int pick_1;
    int choice_1;
    int choice_2;
    int choice_3;
    string job_1;
    string job_2;
    string job_3;
    string comp_1;
    string comp_2;
    string comp_3;
    int num_1;
    int num_2;
    int num_3;
    int salary;
    int kids;
    string spouse;
    string location;
    string dwelling;
    string car;
    string end_comp;
    string end_job;
    vector<string> words_1;
    ifstream file_1("People.txt");
    vector<string> words_2;
    ifstream file_2("Dwellings.txt");
    vector<string> words_3;
    ifstream file_3("Locations.txt");
    vector<string> words_4;
    ifstream file_4("Cars.txt");
    // Random Number Gen.
    srand(time(0));
    int random_1;
    int random_2;
    

    

    


    do 
    {
        // Assigning random numbers to variables
        random_1 = (rand() % 15 + 1);
        random_2 = (rand() % 3 + 1);

        pick_1 = displayMenuGetChoice(pick_1);
        
        
            
        // Switch statement for user choice.   
        switch (pick_1)
        {

            case 1:
            // User data collection for 3 variables between 1 and 100.
            cout << "\nYou chose to predict your future!\n\nFirst, I need just a little information." << endl;
            cout << "Enter three numbers between 1 and 100, separated by a space: ";
            cin >> choice_1 >> choice_2 >> choice_3;
            


            

                // User input validation.
                if (choice_1 < 0 || choice_1 > 100) {
                    cout << "\nInvalid choice for the first number you entered.\nEnter a number between 1 and 100: ";
                    cin >> choice_1;
                    
                }

                if (choice_2 < 0 || choice_2 > 100) {
                    cout << "\nInvalid choice for the second number you entered.\nEnter a number between 1 and 100: ";
                    cin >> choice_2;
                    
                }
        
                if (choice_3 < 0 || choice_3 > 100) {
                    cout << "\nInvalid choice for the third number you entered.\nEnter a number between 1 and 100: ";
                    cin >> choice_3;
                    
                }
        
        
            
            // User job choice
            cin.ignore();
            cout << "\nEnter in an awesome job title: ";
            getline(cin,job_1);
            
            cout << "\nEnter in another awesome job title: ";
            getline(cin,job_2);
            
            cout << "\nEnter in the worst job title ever: ";
            getline(cin,job_3);
            
            // User comp choice.
            cout << "\n\nEnter a company, organization, or restaurant you like: ";
            getline(cin,comp_1);
            
            cout << "Enter another company, organization, or restaurant you like: ";
            getline(cin,comp_2);
            
            cout << "Enter a company, organization, or restaurant you hate: ";
            getline(cin,comp_3);
            

            // Collecting 3 numbers from user between 10,000 and 500,000.
            cout << "\nEnter three numbers between 10,000 and 500,000, separated by a space: ";
            cin >> num_1 >> num_2 >> num_3;
            

                // User input validation.
                if (num_1 < 10000 || num_1 > 500000) {
                    cout << "\nThe first number you entered was invalid.\nEnter a number between 10,000 and 500,000: ";
                    cin >> num_1;
                    
                }

                if (num_2 < 10000 || num_2 > 500000) {
                    cout << "\nThe second number you entered was invalid.\nEnter a number between 10,000 and 500,000: ";
                    cin >> num_2;
                    
                }
        
                if (num_3 < 10000 || num_3 > 500000) {
                    cout << "\nThe third number you entered was invalid.\nEnter a number between 10,000 and 500,000: ";
                    cin >> num_3;
                    
                }
        


            // Assigning random words from file to varibles.
            cin.ignore();
            while (getline(file_1, spouse)) words_1.push_back(spouse);
            spouse = words_1[random_1];

            
            while (getline(file_2, dwelling)) words_2.push_back(dwelling);
            dwelling = words_2[random_1];

            
            while (getline(file_3, location)) words_3.push_back(location);
            location = words_3[random_1];

            
            while (getline(file_4, car)) words_4.push_back(car);
            car = words_4[random_1];

            
            // Assigning number of kids at random using user input.
            switch(random_2) 
            {

                case 1:
                kids = choice_1;
                break;

                case 2:
                kids = choice_2;
                break;

                case 3:
                kids = choice_3;
                break;
            }

            // Assigning user comp choice at random using user number input.
            switch (random_2) 
            {

                case 1:
                if (choice_1 >= 1 && choice_1 <= 33) {
                end_comp = comp_1;
                }

                if (choice_1 > 33 && choice_1 <= 66) {
                end_comp = comp_2;
                }

                if ( choice_1 > 66 && choice_1 <= 100) {
                end_comp = comp_3;
                }

                case 2:
                if (choice_2 >= 1 && choice_2 <= 33) {
                end_comp = comp_1;
                }

                if (choice_2 > 33 && choice_2 <= 66) {
                end_comp = comp_2;
                }

                if ( choice_2 > 66 && choice_2 <= 100) {
                end_comp = comp_3;
                }

                case 3:
                if (choice_3 >= 1 && choice_3 <= 33) {
                end_comp = comp_1;
                }

                if (choice_3 > 33 && choice_3 <= 66) {
                end_comp = comp_2;
                }

                if ( choice_3 > 66 && choice_3 <= 100) {
                end_comp = comp_3;
                }
            }

            // Assigning user job choice at random using user number input.
            switch (random_2) 
            {

                case 1:
                if (choice_1 >= 1 && choice_1 < 33) {
                end_job = job_1;
                }

                if (choice_1 >= 33 && choice_1 < 66) {
                end_job = job_2;
                }

                if ( choice_1 >= 66 && choice_1 <= 100) {
                end_job = job_3;
                }

                case 2:
                if (choice_2 >= 1 && choice_2 < 33) {
                end_job = job_1;
                }

                if (choice_2 >= 33 && choice_2 < 66) {
                end_job = job_2;
                }

                if ( choice_2 >= 66 && choice_2 <= 100) {
                end_job = job_3;
                }

                case 3:
                if (choice_3 >= 1 && choice_3 < 33) {
                end_job = job_1;
                }

                if (choice_3 >= 33 && choice_3 < 66) {
                end_job = job_2;
                }

                if ( choice_3 >= 66 && choice_3 <= 100) {
                end_job = job_3;
                }
            }
            // Choosing salary using random number gen.
            switch(random_2) 
            {

                case 1:
                salary = num_3;
                break;

                case 2:
                salary = num_2;
                break;

                case 3:
                salary = num_1;
                break;
            }

            
    



            // Output for user choices.
            cout << "\n\n******  YOUR FUTURE  ******" << endl;
            cout << "You and your spouse, " << spouse << " will live in a " << dwelling << " in " << location << " \nAnd drive a " << car << ".\nYou and your spouse will have " << kids <<" children.\nYou will work at " << end_comp << " as a " << end_job << " making $" << salary << " a year." << endl;
            break;
        
        

    
            // Ends program when user chooses 2 in the menu.
            case 2:
            cout << "\n\nYou chose to end the program.\nBye!" << endl;
            break;
        }

    } while (pick_1 == 1);

    
    
    

    
    
    
       
    

    

return 0;
    
}



int displayMenuGetChoice(int x)
{
    cout << "\n\nPick form the following menu:\n1.  Let's play MASH!\n2.  End program.\nCHOOSE 1 or 2: ";
    cin >> x;
    
            

    while (x < 1 || x > 2) 
    {
    cout << "Invalid Input. CHOOSE 1 or 2: ";
    cin >> x;
    
    }
    
return x;
}