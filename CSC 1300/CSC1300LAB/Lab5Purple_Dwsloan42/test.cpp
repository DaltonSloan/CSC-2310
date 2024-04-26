#include <iostream>
#include <string>
using namespace std;


int main()
{
  const int maxPlayers = 20;
  const int boardSize = 25;
  int menuChoice;
  int playerNumber;
  string playerNames[playerNumber];
  float totalMoney[playerNumber];
  
  
  do
    {
      cout << "\n\nWelcome to the United States Realestate Market!" << endl;
      cout << "How many Players?: ";
      cin >> playerNumber;
      cin.ignore();

      if (playerNumber > maxPlayers || playerNumber <= 0)
      {
        cout << "\nERROR! Please enter the number of players between 1 and 20: ";
        cin >> playerNumber;
        cin.ignore();
      }
      
      for (int i=0;i<playerNumber;i++)
        {
          playerNames[i] = "";
          totalMoney[i] = 0.00;
        }
      
      

      
    } while (menuChoice == 1);
}