#include <iostream>
#include <string>
using namespace std;


int sumOfNumbers(int num);

int main()
{
    int num = 0;
    cout << "Enter a number: ";
    cin >> num;
    cin.ignore();

    cout << "\nTotal: " << sumOfNumbers(num) << endl;

    

}

int sumOfNumbers(int num)
{
    
	if (num > 1)
    {
    return num + sumOfNumbers(num - 1);
    }

    else
    return 1;
}