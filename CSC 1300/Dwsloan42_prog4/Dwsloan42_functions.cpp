/*
	Title: Program 4.cpp
	Author: Dalton W. Sloan
	Date: 24 April 2023
	Purpose: Monster Zoo.
*/

#include "Dwsloan42_prog4.h"


// Loads monsters information from a text file.
int loadMonstersFromFile(int numMonsters, Monsters list[]) {
    int numMonstersAdded = 0;
    int maxCapacity = 75;
    string filename;

    cout << "Enter the name of the file to load monsters from: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: could not open file " << filename << endl;
        return numMonsters;
    }

    string line;
    while (getline(file, line, '#') && numMonsters < maxCapacity) 
    {
        
    
        
        list[numMonsters].name = line;
        getline(file, line, '#');
        list[numMonsters].description = line;
        getline(file, line, '#');
        list[numMonsters].weight = stod(line);
        getline(file, line, '#');
        list[numMonsters].height = stod(line);
        getline(file, line, '#');
        list[numMonsters].location = line;
        getline(file, line, '#');
        list[numMonsters].dangerLevel = stoi(line);
        getline(file, line, '#');
        list[numMonsters].m.hours = stod(line);
        getline(file, line, '#');
        list[numMonsters].m.careCost = stod(line);
        getline(file, line, '#');
        list[numMonsters].m.foodCost = stod(line);
        getline(file, line, '#');
        list[numMonsters].m.matsCost = stod(line);


        cout << "Added monster " << list[numMonsters].name << " from file." << endl;

        numMonsters++;
        numMonstersAdded++;
    }

    file.close();

    return numMonsters;
}

int registerMonster(int numMonsters, Monsters list[]) {
    int maxCapacity = 75;
    // Check to see if the list is full.
    if (numMonsters >= maxCapacity) {
        cout << "Error: zoo is at full capacity, cannot add more monsters." << endl;
        return numMonsters;
    }
    // User input.
    Monsters newMonster;
    cout << "Enter the following information about the new monster:" << endl;

    // Get input for each field and validate as needed
    cout << "Name: ";
    getline(cin, newMonster.name);

    cout << "Description: ";
    getline(cin, newMonster.description);

    
    cout << "Weight (in pounds): ";
    cin >> newMonster.weight;
    // Input Validation.
    while (newMonster.weight <= 0)
    {
        cout << "Invalid Weight, please try again: ";
        cin >> newMonster.weight;
    }

    
    cout << "Height (in feet): ";
    cin >> newMonster.height;
    // Input Validation.
    while (newMonster.height <= 0)
    {
        cout << "Invalid Height, please try again: ";
        cin >> newMonster.height;
    }

    cin.ignore(); // ignore newline left in buffer by previous cin
    cout << "Last known location: ";
    getline(cin, newMonster.location);

    
    cout << "Danger level (1-5): ";
    cin >> newMonster.dangerLevel;
    // Inout Validation.
    while (newMonster.dangerLevel < 1 || newMonster.dangerLevel > 5)
    {
        cout << "Invalid input, please enter a number between 1 and 5: ";
        cin >> newMonster.dangerLevel;
    }

    cout << "Required direct care (in hours) per week: ";
    cin >> newMonster.m.hours;
    // Input Validation.
    while (newMonster.m.hours < 0 )
    {
        cout << "Invalid input, please enter a number greater than 0: ";
        cin >> newMonster.m.hours;
    }

    cout << "Cost of care per week: $";
    cin >> newMonster.m.careCost;
    // Input validation.
    while (newMonster.m.careCost < 0 )
    {
        cout << "Invalid input, please enter a number greater than 0: ";
        cin >> newMonster.m.careCost;
    }

    cout << "Food cost per week: $";
    cin >> newMonster.m.foodCost;
    // Input validation.
    while (newMonster.m.foodCost < 0)
    {
        cout << "Invalid input, please enter a number greater than 0: ";
        cin >> newMonster.m.foodCost;
    }

    cout << "Medical & grooming cost per week: $";
    cin >> newMonster.m.matsCost;
    // Input validation.
    while (newMonster.m.matsCost < 0)
    {
        cout << "Invalid input, please enter a number greater than 0: ";
        cin >> newMonster.m.matsCost;
    }

    
    list[numMonsters] = newMonster;
    numMonsters++;

    cout << "Added monster " << newMonster.name << " to the zoo." << endl;
    return numMonsters;
}

int removeMonster(int numMonsters, Monsters list[]) 
{
    // Print the list of monsters to the screen.
    cout << "The following is a list of all the monsters in the zoo:" << endl;
    for (int i = 0; i < numMonsters; i++) 
    {
        cout << list[i].name << endl;
    }

    string tempName;
    cout << "What monster is leaving the zoo?" << endl;
    cout << "MONSTER NAME: ";
    cin.ignore();
    getline(cin, tempName);

    int deleteIndex = -1;
    for (int i = 0; i < numMonsters; i++) 
    {
        if (list[i].name == tempName) 
        {
            deleteIndex = i;
            break;
        }
    }

    if (deleteIndex == -1) 
    {
        cout << "Sorry, a monster by the name " << tempName << " could not be found." << endl;
    }

    else 
    {
        cout << "You have removed " << list[deleteIndex].name << "." << endl;

        for (int i = deleteIndex; i < numMonsters - 1; i++) 
        {
            list[i] = list[i + 1];
        }

        numMonsters--;
    }

    return numMonsters;
}

void printMonsters(int numMonsters, Monsters* list) 
{
    // Checks if monsters are on the list.
    if (numMonsters == 0) 
    {
        cout << "THERE ARE NO MONSTERS AT YOUR ZOO!" << endl;
    } 
    // Iterates through the list of monsters and prints the to the screen.
    else 
    {
        for (int i = 0; i < numMonsters; i++) 
        {
        Monsters currentMonster = list[i];
        cout << "\n\nMonster #" << (i+1) << ":" << endl;
        cout << "Name: " << currentMonster.name << endl;
        cout << "Description: " << endl;
        cout << "\t\t";
        string description = currentMonster.description;
        int startIndex = 0;

        while (startIndex < description.length()) 
        {
            int endIndex = min((int)description.length()-1, startIndex+60);
            int length = endIndex - startIndex + 1;
            cout << description.substr(startIndex, length) << endl;
            startIndex += length;
            
            if (startIndex < description.length()) 
            {
                cout << "\t\t";
            }
        }

        cout << "Weight: " << currentMonster.weight << endl;
        cout << "Height: " << currentMonster.height << endl;
        cout << "Last Known Location: " << currentMonster.location << endl;
        cout << "DangerLevel: " << currentMonster.dangerLevel << endl;
        cout << "Weekly Care Information: " << endl;
        cout << "        -Hours of care required:        " << currentMonster.m.hours << endl;
        cout << "        -Cost of care:                  $" << currentMonster.m.careCost << endl;
        cout << "        -Food cost:                     $" << currentMonster.m.foodCost << endl;
        cout << "        -Grooming & Supplies Cost:      $" << currentMonster.m.matsCost << endl;
        }
    }
}

void printCostInfo(int numMonsters, Monsters list[]) 
{
    // Checks if monsters are on the list.
    if (numMonsters == 0) 
    {
        cout << "\n\nThere are no monsters in the zoo so the total cost is $0.00." << endl;
        return;
    }
    
    double totalCost = 0;
    
    cout << "\n\nCOST OF EACH MONSTER FOR ONE WEEK:" << endl;
    cout << "MONSTER\t\t\tCARE COST" << endl;
    cout << "----------------------------------------" << endl;
    // Adds the cost of each monster by the number of hours.
    for (int i = 0; i < numMonsters; i++) 
    {
        double careCost = list[i].m.hours * list[i].m.careCost + list[i].m.foodCost + list[i].m.matsCost;
        totalCost += careCost;
        cout << setw(24) << left << list[i].name << "$" << fixed << setprecision(2) << careCost << endl;
    }
    
    cout << "----------------------------------------" << endl;
    cout << "TOTAL COST:\t\t $ " << fixed << setprecision(2) << totalCost << endl;
}

void saveMonstersToFile(int numMonsters, Monsters* list) 
{
    // Checks if monsters are on the list.
    if (numMonsters == 0) 
    {
        cout << "There are no monsters in the zoo so none can be saved to a file.\n";
        return;
    }
    
    string filename;
    cout << "Enter the name of the file to save the monsters to: ";
    cin >> filename;
    
    ofstream outfile(filename);
    if (!outfile) 
    {
        cout << "Error: could not open file " << filename << " for writing.\n";
        return;
    }
    
    for (int i = 0; i < numMonsters; i++) 
    {
        outfile << list[i].name << "#"
                << list[i].description << "#"
                << list[i].weight << "#"
                << list[i].height << "#"
                << list[i].location << "#"
                << list[i].dangerLevel << "#"
                << list[i].m.hours << "#"
                << list[i].m.careCost << "#"
                << list[i].m.foodCost << "#"
                << list[i].m.matsCost;
        
        if (i < numMonsters - 1) 
        {
        outfile << "#"; // separate entries with a pound sign
        }
    }
    
    outfile.close();
    cout << "All monsters currently housed in the zoo were successfully saved to the " << filename << " file.\n";
}



