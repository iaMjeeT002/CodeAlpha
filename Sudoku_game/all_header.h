
// header.h
#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
using namespace std;
class Sudoku
{
private:
    int sudoku[9][9] = {
        {3, 4, 0, 8, 0, 1, 0, 0, 2},
        {2, 0, 1, 0, 3, 0, 6, 0, 4},
        {0, 0, 0, 2, 0, 4, 0, 0, 0},
        {8, 0, 9, 2, 0, 4, 1, 0, 6},
        {4, 6, 0, 0, 0, 0, 0, 5, 0},
        {7, 0, 2, 0, 0, 0, 4, 0, 9},
        {0, 0, 0, 0, 5, 0, 9, 0, 9},
        {9, 0, 4, 0, 8, 0, 7, 0, 5},
        {6, 0, 0, 0, 0, 7, 0, 0, 3}};
    bool flag = false;
    bool block_check = false;
    bool entire_col_check = false;
    bool entire_row_check = false;
    void display();
    void replaceable(bool block_check, bool entire_col_check, bool entire_row_check, int value4, int row4, int column4);

public:
    void take_input();
    // bool flag = false;
    bool is_present(int row1, int column1, int value1);
    bool is_col_okay(int row2, int column2, int value3);
    bool is_row_okay(int row2, int column2, int value3);
};

#endif
