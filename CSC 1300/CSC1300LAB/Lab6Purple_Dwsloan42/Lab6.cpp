#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
// Function bank.
int displayMenuGetChoice(int); 
void printToFile(string,int,int,int,string,string);



// Main fuction
int main() {


    // Variable bank.
    int mainChoice;
    string monsterName;
    int monsterAge;
    double monsterHeight;
    double monsterWeight;
    string monsterFood;
    string monsterFacts;
    ifstream inFS;
    ofstream outFS;
    int monsterData;
    
    // Menu loop
    do 
    {
        mainChoice = displayMenuGetChoice(mainChoice);
        
        // Switch statement for users choices.
        switch (mainChoice)
        {
            // Data input to txt file.
            case 1:
                
                cout << "\nMonster Name: ";
                getline(cin, monsterName);
                
                cout << monsterName << "'s age (years): ";
                cin >> monsterAge;
                cin.ignore();
                
                cout << monsterName << "'s height (feet): ";
                cin >> monsterHeight;
                cin.ignore();
                
                cout << monsterName << "'s weight (pounds): ";
                cin >> monsterWeight;
                cin.ignore();
                
                cout << "Food that " << monsterName << " prefers: ";
                getline(cin, monsterFood);
                
                cout << "Fun facts about " << monsterName << ": ";
                getline(cin, monsterFacts);
                
                printToFile(monsterName, monsterAge, monsterHeight, monsterWeight, monsterFood, monsterFacts);
                
            break;
                
            // Reading from text file and inputting to Variables.
            case 2:
                
                inFS.open("monsterData.txt");
                
                if (inFS)
                {
                    getline(inFS,monsterName);   
                    inFS >> monsterAge;                  
                    inFS >> monsterHeight;                 
                    inFS >> monsterWeight;
                    inFS.ignore();                  
                    getline(inFS,monsterFood);               
                    getline(inFS,monsterFacts);
                    
                    
                    cout << "\n" << monsterName << " has been read from the file." << endl;
                    inFS.close();
                }
                
                else 
                {
                cout << "\nThe monsterData.txt file does not exist." << endl;
                }
            
            break;
            
            // Printing data form Variables.
            case 3:
            
                inFS.open("monsterData.txt");
                
                if (inFS)
                {
                cout << "MONSTER NAME:     " << monsterName << endl;
                cout << "AGE (YEARS):      " << monsterAge << endl;
                cout << "HEIGHT (FEET):    " << monsterHeight << endl;
                cout << "WEIGHT (POUNDS):  " << monsterWeight << endl;
                cout << "FOOD IT EATS:\n" << monsterFood << endl;
                cout << "FUN FACT:\n" << monsterFacts << endl;
                
                inFS.close();
                }
                
                else 
                {
                cout << "\nNo Monster Data exists." << endl;
                }
                
                
            break;
        }
    
    
    } while (mainChoice != 4);
    
    // User exits the menu, program ends.
    cout << "The monster, " << monsterName << ", has been saved to the monsterData.txt file. GOODBYE!";
    return 0;
}

// Function definition.
int displayMenuGetChoice(int mainChoice)
{
    cout << "\n\n1. Enter a Monster's Data from Screen" << endl;
    cout << "2. Read a Monster's Data from File" << endl;
    cout << "3. Print the monster's Data to screen" << endl;
    cout << "4. Save & Quit Program" << endl;
    cout << "CHOOSE 1-4: ";
    cin >> mainChoice;
    cin.ignore();
    
    while (mainChoice < 1 || mainChoice > 4)
    {
        cout << "Error! Please Choose 1-4: ";
        cin >> mainChoice;
        cin.ignore();
    }
    return mainChoice;
}

// Function definition.
void printToFile(string Name, int Age, int Height, int Weight, string Food, string Facts)
{
    ofstream outFS;
    
    outFS.open("MonsterData.txt");
    
    if (!outFS.is_open())
    {
        cout << "File not open!";
    }
    
    
    outFS << Name << endl;
    outFS << Age << endl;
    outFS << Height << endl;
    outFS << Weight << endl;
    outFS << Food << endl;
    outFS << Facts;
    
    outFS.close();
    
    if (outFS.is_open())
    {
        cout << "File not closed!";
    }
}

