/*
	Title: Program 4.cpp
	Author: Dalton W. Sloan
	Date: 24 April 2023
	Purpose: Monster Zoo.
*/
#include "Dwsloan42_prog4.h"
// Main function.
int main()
{
  // Variable bank.
  Monsters list[75];
  int numMonsters = 0;
  int choice = 0;
  char YorN;

  cout << "\nWelcome to the Monster Zoo!" << endl;

  numMonsters = loadMonstersFromFile(numMonsters, list);

// Menu loop.
  do 
    {
      cout << "\n\n1. Register a New Monster" << endl;
      cout << "2. Remove a Monster From Zoo" << endl;
      cout << "3. Print Monsters to Screen" << endl;
      cout << "4. Print Monster Care Cost Data" << endl;
      cout << "5. End Program" << endl;
      cout << "CHOOSE 1-5: ";
      cin >> choice;
      cin.ignore();
      // Switch statement from user input.
      switch(choice)
        {
          // Adds monster to the list.
          case 1:
            numMonsters = registerMonster(numMonsters, list);
            break;
          // Removes a monster from the list.
          case 2:
            numMonsters = removeMonster(numMonsters, list);
            break;
          // Prints monster information to the screen.
          case 3:
            printMonsters(numMonsters, list);
            break;
          // Calculates the cost of each monster and totals it, then prints to the screen.
          case 4:
            printCostInfo(numMonsters, list);
            break;
          // Save monster information to a text file, then end the program.
          case 5:
            cout << "\n\nWould you like to save your monsters to a file? (Y or N): ";
            cin >> YorN;
            cin.ignore();
        
            if (YorN == 'Y' || YorN == 'y')
            {
              saveMonstersToFile(numMonsters, list);
            }
            break;

        }
      // User input validation.  
      while (choice < 1 || choice > 5)
      {
          cout << "Error! Please Choose 1-5: ";
          cin >> choice;
          cin.ignore();
      }
      
    } while (choice != 5);


  
}
