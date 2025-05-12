#include <ConsoleUI.h>
#include <iostream>
using namespace std;

int main()
{
    displayMenu();
    int i;
    cin >> i;
    if(i >5 || i < 1)
    {
        cout << "Invalid input. Please enter a number between 1 and 5." << endl;
        cin >> i;
    }
    while(i != 5)
    {
        displayMenu();
        cin >> i;
    }
    
    return 0;

}
