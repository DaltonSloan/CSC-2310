#include <iostream>
#include <iomanip>
using namespace std;


int main()
{

// Varible bank.
   string Name;
   int Age;
   char Gender;
   int Weight;
   char Smoke;
   char Drink;
   int Workout;
   char Pet;
   int Marry;
   char Care;
   int Job;
   char Breaky;
   char Dead;
   char Fruit;
   char Veg;
   int Hang;
   int Ed;
   int life_expect;
   int start = 60;
   int a;
   int b;
   int c;
   int d;
   int e;
   int f;
   int g;
   int h;
   int i;
   int j;
   int k;
   int l;
   int m;
   int n;
   int o;
   int start_age;
   



// Data collection.
    cout << "\n********** Life Expectancy Calculator **********\n\n\n\n";


    cout << "What is your name?:" << setw(2)<<"";
    getline(cin,Name);


    cout << "\nWhat is your age?:" << setw(2) << "";
    cin >> Age;
    cin.ignore();


    cout << "\nAre you male or Female? (Enter m or f):" << setw(2) << "";
    cin >> Gender;
    cin.ignore();

    cout << "\nWhat is your current weight status?\n(1) Underweight, (2)Just right, (3) Overweight, (4)Obese\n(Enter 1, 2, 3, 4):" << setw(2) << "";
    cin >> Weight;
    cin.ignore();

    cout << "\nDo you smoke? (y or n):" << setw(2) << "";
    cin >> Smoke;
    cin.ignore();

    cout << "\nDo you drink? (y or n):" << setw(2) << "";
    cin >> Drink;
    cin.ignore();

    cout << "\nDo you workout?\n(1)None, (2)Very little, (3)Periodically, (4)Active, (5)Athlete\n(Enter 1, 2, 3, 4 or 5):" << setw(2) << "";
    cin >> Workout;
    cin.ignore();

    cout << "\nDo you have a pet? (y or n):" << setw(2) << "";
    cin >> Pet;
    cin.ignore();

    cout << "\nAre you married?\n(1)Divorced, (2)Single, (3)Married, (4)Happily Married\n(Enter 1, 2, 3, or 4):" << setw(2) << "";
    cin >> Marry;
    cin.ignore();

    cout << "\nAre you a caretaker? (Emter y or n):" << setw(2) << "";
    cin >> Care;
    cin.ignore();

    cout << "\nHow do you feel about your job?\n(1)Hate it!, (2)Dislike it, (3)It's ok, (4)Enjoyable, (5)Love it!\n(Enter 1, 2, 3, 4, or 5):" << setw(2) << "";
    cin >> Job;
    cin.ignore();

    cout << "\nDo you eat breakfast everyday? (Enter y or n):" << setw(2) << "";
    cin >> Breaky;
    cin.ignore();

    cout << "\nDid either of your biological parents or any of your biological\ngrandparents die before the age of 50? (Enter y or n):" << setw(2) << "";
    cin >> Dead;
    cin.ignore();

    cout << "\nDo you eat fruit everyday? (Enter y or n):" << setw(2) << "";
    cin >> Fruit;
    cin.ignore();

    cout << "\nDo you eat vegetables everyday? (enter y or n):" << setw(2) << "";
    cin >> Veg;
    cin.ignore();

    cout << "\nDo you hang out with you friends?\n(1)Never, (2)Periodically, (3)Often\n(Enter 1, 2, or 3):" << setw(2) << "";
    cin >> Hang;
    cin.ignore();

    cout << "\nWhat is your education level?\n(1)No degrees, (2)Highschool degree, (3)Associate degree,\n(4)Bachelors degree, (5)Masters/PHD degree\n(Enter 1, 2, 3, 4, or 5):" << setw(2) << "";
    cin >> Ed;
    cin.ignore();


// Making it so life ecpect cant be lower than your age.
    if (Age < 60) {
        life_expect = 60;
        start_age = 60;
    }

    if (Age > 60) {
        life_expect = Age + 60;
        start_age = Age + 60;
    }


// Calculating user data based on table given and storing in varibles.
    if (Gender =='f') {
        life_expect = life_expect + 4;
        a = 4;
    }
    else {
        life_expect = life_expect + 0;
        a = 0;
    }

    if (Weight == 1) {
        life_expect = life_expect - 1;
        b = -1;
        
    }
    
    else if (Weight == 2) {
            life_expect = life_expect + 5;
            b = 5;
    }

    else if (Weight == 3) {
            life_expect = life_expect - 2;
            b = -2;
    }

    else if (Weight == 4) {
            life_expect = life_expect - 5;
            b = -5;
    }
    else {
        b = 0;
    }

    if (Smoke == 'y') {
        life_expect = life_expect - 5;
        c = -5;
    }
        else {
            life_expect = life_expect + 5;
            c = 5;
        }
    if (Drink == 'y') {
        life_expect = life_expect - 5;
        d = -5;
    }
        else {
            life_expect = life_expect + 2;
            d = 2;
        }

    if (Workout == 1){
        life_expect = life_expect - 1;
        e = -1;
    }
    
    if (Workout == 2) {
        life_expect = life_expect - 2;
        e = -2;
    }

    if (Workout == 3) {
        life_expect = life_expect + 0;
        e = 0;
    }

    if (Workout == 4) {
        life_expect = life_expect + 5;
        e = 5;
    }

    if (Workout == 5) {
            life_expect = life_expect + 7;
            e = 7;
    }

    if (Pet == 'y') {
        life_expect = life_expect + 3;
        f = 3;
    }
    
    if (Pet == 'n') {
        life_expect = life_expect - 1;
        f = -1;
    }

    if (Marry == 1) {
        life_expect = life_expect - 5;
        g = -5;
    }
    
    if (Marry == 2) {
        life_expect = life_expect - 2;
        g = -2;
    }

    if (Marry == 3) {
        life_expect = life_expect + 2;
        g = 2;
    }

    if (Marry == 4) {
        life_expect = life_expect + 5;
        g = 5;
    }

    if (Care == 'y') {
        life_expect = life_expect - 2;
        h = -2;
    }
        else {
            life_expect = life_expect + 0;
            h = 0;
        }

    if (Job == 1) {
        life_expect = life_expect - 5;
        i = -5;
    }
    
    if (Job == 2) {
        life_expect = life_expect - 2;
        i = -2;
    }

    if (Job == 3) {
        life_expect = life_expect + 0;
        i = 0;
    }

    if (Job == 4) {
        life_expect = life_expect + 2;
        i = 2;
    }

    if (Job == 5) {
        life_expect = life_expect + 5;
        i = 5;
    }

    if (Breaky == 'y') {
        life_expect = life_expect + 5;
        j = 5;
    }
        else {
            life_expect = life_expect - 2;
            j = -2;
        }

    if (Dead == 'y') {
        life_expect = life_expect - 2;
        k = -2;
    }    
        else {
            life_expect = life_expect + 5;
            k = 5;
        }

    if (Fruit == 'y') {
        life_expect = life_expect + 5;
        l = 5;
    }
        else {
            life_expect = life_expect - 5;
            l = -5;
        }

    if (Veg == 'y') {
        life_expect = life_expect + 5;
        m = 5;
    }
        else {
            life_expect = life_expect - 5;
            m = -5;
        }

    if (Hang == 1) {
        life_expect = life_expect - 2;
        n = -2;
    }
    
    if (Hang == 2) {
        life_expect = life_expect + 0;
        n = 0;
    }

    if (Hang == 3) {
        life_expect = life_expect + 2;
        n = 2;
    }

    if (Ed == 1) {
        life_expect = life_expect - 5;
        o = -5;
    }
    
    if (Ed == 2) {
        life_expect = life_expect - 2;
        o = -2;
    }

    if (Ed == 3) {
        life_expect = life_expect + 2;
        o = 2;
    }

    if (Ed == 4) {
        life_expect = life_expect + 5;
            o = 5;
    }

    if (Ed == 5) {
            life_expect = life_expect + 7;
            o = 7;
    }

   
    
    
// Output of life expect after each input, and final life expect.
    cout << "\nStarting Life Expectancy:  " << Age << endl;
    cout << "Life Expectancy after gender:  " << (start += a) << endl;
    cout << "Life Expectancy after weight:  " << (start += b) << endl;
    cout << "Life Expectancy after smoke:  " << (start += c) << endl;
    cout << "Life Expectancy after alcohol:  " << (start += d) << endl;
    cout << "Life Expectancy after exercise:  " << (start += e) << endl;
    cout << "Life Expectancy after pet:  " << (start += f) << endl;
    cout << "Life Expectancy after married:  " << (start += g) << endl;
    cout << "Life Expectancy after caretaker:  " << (start += h) << endl;
    cout << "Life Expectancy after job stress:  " << (start += i) << endl;
    cout << "Life Expectancy after breakfast:  " << (start += j) << endl;
    cout << "Life Expectancy after died:  " << (start += k) << endl;
    cout << "Life Expectancy after fruits:  " << (start += l) << endl;
    cout << "Life Expectancy after vegetables:  " << (start += m) << endl;
    cout << "Life Expectancy after friends:  " << (start += n) << endl;
    cout << "Life Expectancy after education level:  " << (start += o) << endl;

    cout << "\n\n************************************************\n\n"<< endl;
    cout << "            Name:     " << Name << endl;
    cout << "     Current Age:     " << Age << endl;
    cout << " Life Expectancy      " << life_expect << endl;
    cout << "\n\n************************************************" << endl;










    

    return 0;
}