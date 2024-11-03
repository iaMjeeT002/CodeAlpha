#include "all_header.h"
#include <iomanip>
// take_input
void Sudoku::take_input()
{
    cout << "\nHere the game values are given and 0 represent the [EMPTY_CELLS] ----" << endl;
    display();

    // cout << endl
    //      << soduku << endl;
    int row_understand{}, column_understand{};
    int value{};
    cout << "\nEnter row and column one by one : ";
    cin >> row_understand >> column_understand;
    cout << "\nEnter value , you want to insert :" << endl;
    cin >> value;
    int row = row_understand - 1, column = column_understand - 1;
    cout << endl;
    // for checking if the block_check function is okay to go not..
    bool block_check = is_present(row, column, value);
    // for entire straight row and column check
    bool entire_col_check = is_col_okay(row, column, value);
    bool entire_row_check = is_row_okay(row, column, value);
    // now i will call a fun. with all 3 bool values and entered i/p
    replaceable(block_check, entire_col_check, entire_row_check, value, row, column);
}
// the function body
bool Sudoku::is_present(int row1, int column1, int value1)
{
    int temprow1{};
    int tempcolumn1{};
    temprow1 = row1 - (row1 % 3);
    tempcolumn1 = column1 - (column1 % 3);
    // ending position
    int temp_row1_end = temprow1 + 3;
    int temp_column1_end = tempcolumn1 + 3;
    for (int i = temprow1; i < temp_row1_end; i++)
    {
        for (int j = tempcolumn1; j < temp_column1_end; j++)
        {
            if (value1 == sudoku[i][j])
            {
                // cout << "\nThat value is present within the block." << endl;
                flag = false;
                // exit(1);
            }
            else
            {
                flag = true;
                // cout << "Condition = " << flag << endl;
            }
        }
    }
    return flag;
}
// function is_okay
bool Sudoku::is_col_okay(int row2, int column2, int value2)
{
    int col_temp{};
    bool col_okay = false; // for checking entire column
    // row fixed..means i will traverse columnwise
    int i = row2;
    col_temp = 0;
    while (col_temp < 9)
    {
        if (value2 == sudoku[i][col_temp])
        {
            col_okay = false;
            break;
        }
        else
        {
            col_okay = true;
        }
        col_temp++;
    }
    return col_okay;
}

// row check
bool Sudoku::is_row_okay(int row2, int column2, int value2)
{
    int row_temp{};
    bool row_okay = false; // for checking entire row
    // col fixed..means i will traverse rowwise
    int i = column2;
    row_temp = 0;
    while (row_temp < 9)
    {
        if (value2 == sudoku[row_temp][i])
        {
            row_okay = false;
            break;
        }
        else
        {
            row_okay = true;
        }
        row_temp++;
    }
    return row_okay;
}

// if replaceable
void Sudoku::replaceable(bool block_check, bool entire_col_check, bool entire_row_check, int value4, int row4, int column4)
{
    if (block_check == true && entire_col_check == true && entire_row_check == true)
    {
        sudoku[row4][column4] = value4;
        cout << "\n\t\t\t\t\t\t\t\t\t SUCCESS" << endl;
        display();
    }
    // else{
    //     cout<<"\nI"
    // }
    else if (block_check == false)
    {
        cout << "\n In block the value is already present---" << endl;
    }
    else if (entire_col_check == false && entire_row_check == false)
    {
        cout << "\nThe value is already present both ro-wise and column-wise..." << endl;
    }
    else if (entire_col_check == false)
    {
        cout << "\nThe value is already present row-wise..." << endl;
    }
    else
    {
        cout << "\nThe value is already present column-wise..." << endl;
    }
}
void Sudoku::display()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            setfill('-');
            cout << setw(2) << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}