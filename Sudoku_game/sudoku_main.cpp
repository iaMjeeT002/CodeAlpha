#include <iostream>
#include <iomanip>
#include <string>
#include "all_header.h"
using namespace std;

int main()
{
    // soduku_game
    cout << "\t\t\t====Soduku_Game====" << endl;
    Sudoku s1;
    char choice;
    // cout << "Do you wanna continue(y or n) ? ";
    // cin >> choice;
    while (choice != 'n')
    {
        cout << "Do you wanna continue(y or n) ? ";
        cin >> choice;
        cout << endl;

        if (choice == 'y')
        {
            s1.take_input();
        }
        else if (choice == 'n')
        {
            exit(0);
        }
        else
        {
            cout << "\n y and n is valid not others." << endl;
        }
    }
    return 0;
}