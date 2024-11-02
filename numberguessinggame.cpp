#include <iostream>
#include <random>
using namespace std;
void secondphase();
int main()
{
    // It's a number guessing game
    cout << "\t\t\t =====It's Number Guessing Game bruhh.=====" << endl;
    cout << "\tSo, Let's Start --" << endl;
    int user_input{};
    cout << "\t\t Do you wish to continue ? -- " << endl;
    cout << "\t1.Yes \n \t2. No" << endl;
    cin >> user_input;
    switch (user_input)
    {
    case 1:
        secondphase();
        break;
    case 2:
        exit(0);
    case 3:
        cout << "Invalid chhosen." << endl;
    }
    return 0;
}

void secondphase()
{
    // Generate Random value
    random_device rd;                        // for unpredictable value, not that the value is based upon something algorithm
    mt19937 gen(rd());                       // something engine for random generate
    uniform_int_distribution<> distr(1, 20); // range

    int random_value = distr(gen);

    // now main logic
    bool flag = false; // for checking if number is matched or not
    int trying = 1;    // for check how many tries i have done
    int left = 8;      // setted left tries upto 8[as trying starts from 0]
    while (flag != true)
    {
        cout << "Guess a number from 1 to 20 as our range for this game is 1-20 : ";
        unsigned int guess_number{};
        cin >> guess_number;
        // trying++;
        left--;
        // adding trying limitation
        if (trying <= 8)
        {

            if (random_value == guess_number)
            {
                flag = 1;
            }
            else if (random_value < guess_number)
            {
                cout << "\ttry smaller bruhh !" << endl;
                trying++;
            }
            else
            {
                cout << "\ttry bigger bruhh !" << endl;
                trying++;
            }
            // now check
            if (flag == true)
            {
                cout << "\twhat !  It's matched . hu huuuuuuuuuuuuuu. " << endl;
                cout << "\tYou have done it in " << trying << " tries." << endl;
            }
            else
            {
                cout << "\t\tTry again : bruhh !\t" << left << " times left." << endl;
            }
        }
        else
        {
            cout << "---------------BAD LUCK----------------" << endl;
            cout << "You ran out of attempts. Better luck next time!" << endl;
            exit(0);
        }
    }
}