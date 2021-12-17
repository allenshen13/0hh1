/**
 * ohhi.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1
 *
 * <Allen Shen and Rishi Baronia>
 * <shenal and rbaronia>
 *
 * <Ohhi Project, implementation of different functions that make up the Ohhi game using 
 two dimensional arrays, pass by reference, loops, and other C++ techniques>
 */

#include <iostream>
#include <cctype>
#include "utility.h"
#include "ohhi.h"

/**
 * --------------------------------------------------------
 * ---------- UTILITY FUNCTIONS ---------------------------
 * --------------------------------------------------------
 */

int count_unknown_squares(const int board[MAX_SIZE][MAX_SIZE], int size) {
    int count = 0;
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (board[row][col] == UNKNOWN) {
                count++;
            }
        }
    }
    // only increments count if array at [row][col] is unknown
   
    return count;
}


/**
 * --------------------------------------------------------
 * --------- VALIDITY CHECKING FUNCTIONS ------------------
 * --------------------------------------------------------
 */

bool row_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int row,
                                int color) {

    
    int count = 0;
    bool noThreeColors = true;
    for (int col = 0; col < size; col++) {
        if (board[row][col] == color) {
            count++;
        }
        else {
            count = 0;
        }
      
        if (count == 3) {
            noThreeColors = false;
        }
    }
    return noThreeColors;
  
    

}

bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int col,
                                int color) {
    
    int count = 0;
    bool noThreeColors = true;
    for (int row = 0; row < size; row++) {
        if (board[row][col] == color) {
            count++;
        }
        else {
            count = 0;
        }

        if (count == 3) {
            noThreeColors = false;
        }
    }
    return noThreeColors;
}

bool board_has_no_threes(const int board[MAX_SIZE][MAX_SIZE], int size) {
    
    for (int i = 0; i < size; i++) {
        if (!(row_has_no_threes_of_color(board, size, i, BLUE) && 
            col_has_no_threes_of_color(board, size, i, BLUE))) {
            return false;
        }
        else if (!(row_has_no_threes_of_color(board, size, i, RED) &&
            col_has_no_threes_of_color(board, size, i, RED))) {
            return false;
        }

    }

    return true; 
}

bool rows_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int row1,
                        int row2) {
    // write your code here
    for (int col = 0; col < size; col++) {
        if (board[row1][col] == UNKNOWN 
            || board[row2][col] == UNKNOWN) {
            return true;
        }
        if (board[row1][col] != board[row2][col]) {
            return true;
        }
    }
    return false;
}

bool cols_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int col1,
                        int col2) {
    for (int row = 0; row < size; row++) {
        if (board[row][col1] == UNKNOWN 
            || board[row][col2] == UNKNOWN) {
            return true;
        }
        if (board[row][col1] != board[row][col2]) {
            return true;
        }
    }
    return false;
}

bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size - 1 ; i++) {
        for (int j = i + 1; j < size; j++) {
            if (!(cols_are_different(board, size, i, j) && 
                rows_are_different(board, size, i, j))) {
                return false;
            }
        }

    }
    return true;
}


/**
 * --------------------------------------------------------
 * ---------- SOLVING FUNCTIONS ---------------------------
 * --------------------------------------------------------
 */

void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int row,
                          bool announce) {
    

    
    for (int col = 0; col < size - 1; col++) {
        // Case for two in a row and adding one at the end
        if (board[row][col + 1] == board[row][col]) {
            if (board[row][col] == RED || board[row][col] == BLUE) {
                if (col - 1 >= 0 && board[row][col - 1] == UNKNOWN) {
                    mark_square_as(board, size, row, col - 1,
                        opposite_color(board[row][col]), announce);
                }
                if (col + 2 < size && board[row][col + 2] == UNKNOWN) {
                    mark_square_as(board, size, row, col + 2,
                        opposite_color(board[row][col]), announce);
                }

            }
        }
        //case to fill in middle value to prevent 3 in a row
        if (col + 2 < size) {
            if (board[row][col] == board[row][col + 2]) {
                if (board[row][col] == RED || board[row][col] == BLUE) {
                    if (board[row][col + 1] == UNKNOWN) {
                        mark_square_as(board, size, row, col + 1,
                            opposite_color(board[row][col]), announce);
                    }
                }
            }
        }
    }


   

    return;
}

void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
                             int size,
                             int col,
                             bool announce) {
    
  
    
    for (int row = 0; row < size - 1; row++) {
        // Case for two in a row and adding one at the end
        if (board[row + 1][col] == board[row][col]) {
            if (board[row][col] == RED || board[row][col] == BLUE) {
                if (row - 1 >= 0 && board[row - 1][col] == UNKNOWN) {
                    mark_square_as(board, size, row - 1, col,
                        opposite_color(board[row][col]), announce);
                }
                if (row + 2 < size && board[row + 2][col] == UNKNOWN) {
                        mark_square_as(board, size, row + 2, col,
                            opposite_color(board[row][col]), announce);
                }

                
            }
        }
        //case to fill in middle value to prevent 3 in a row
        if (row + 2 < size) {
            if (board[row][col] == board[row + 2][col]) {
                if (board[row][col] == RED || board[row][col] == BLUE){
                    if (board[row + 1][col] == UNKNOWN) {
                        mark_square_as(board, size, row + 1, col,
                            opposite_color(board[row][col]), announce);
                    }
                }
            }
        }
    }



   

    return;
}


void solve_balance_row(int board[MAX_SIZE][MAX_SIZE],
                       int size,
                       int row,
                       bool announce) {
    int redColorCount = 0;
    int blueColorCount = 0;
    for (int col = 0; col < size; col++) {
        if (board[row][col] == RED) {
            redColorCount++;
        }
        if (board[row][col] == BLUE) {
            blueColorCount++;
        }
    }

    if (redColorCount == (size / 2)) {
        for (int col = 0; col < size; col++) {
            if (board[row][col] == UNKNOWN) {
                mark_square_as(board, size, row, col, BLUE, announce);
            }
        }
    }

    if (blueColorCount == (size / 2)) {
        for (int col = 0; col < size; col++) {
            if (board[row][col] == UNKNOWN) {
                mark_square_as(board, size, row, col, RED, announce);
            }
        }
    }


    return;
}

void solve_balance_column(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int col,
                          bool announce) {
    
    int redColorCount = 0;
    int blueColorCount = 0;
    for (int row = 0; row < size; row++) {
        if (board[row][col] == RED) {
            redColorCount++;
        }
        if (board[row][col] == BLUE) {
            blueColorCount++;
        }
    }

    if (redColorCount == (size / 2)) {
        for (int row = 0; row < size; row++) {
            if (board[row][col] == UNKNOWN) {
                mark_square_as(board, size, row, col, BLUE, announce);
            }
        }
    }

    if (blueColorCount == (size / 2)) {
        for (int row = 0; row < size; row++) {
            if (board[row][col] == UNKNOWN) {
                mark_square_as(board, size, row, col, RED, announce);
            }
        }
    }

    return;


    return;
}


/**
 * --------------------------------------------------------
 * ---------- GAMEPLAY FUNCTIONS --------------------------
 * --------------------------------------------------------
 */

bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size) {
    return (board_is_valid(board, size) &&
        count_unknown_squares(board, size) == 0);


}

bool check_valid_input(int size, int row_input, char col_input,
    char color_char, int& row, int& col) {

    col_input = toupper(col_input);
    if (!(row_input <= size && row_input >= 1)) {
        cout << "Sorry, that's not a valid input." << endl;
        return false;
    }
    else if (!(col_input >= 'A' && col_input <= 'A' + size - 1)) {
        cout << "Sorry, that's not a valid input." << endl;
        return false;
    }
    else if (toupper(color_char) != UNKNOWN_LETTER
        && toupper(color_char) != RED_LETTER
        && toupper(color_char) != BLUE_LETTER) {
        cout << "Sorry, that's not a valid input." << endl;
        return false;
    }
    else {
        row_input -= 1;
        col_input -= 65;
        row = row_input;
        col = col_input;
        return true;
    }




}

bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
                      const int current_board[MAX_SIZE][MAX_SIZE],
                      int size, int row, int col, int color) {
    int copied_board[MAX_SIZE][MAX_SIZE];
    copy_board(current_board, copied_board, size);

    copied_board[row][col] = color;
    if (original_board[row][col] != RED && original_board[row][col] != BLUE) {
        if (board_is_valid(copied_board, size)) {
            return true;
        }
        else {
            cout << "Sorry, that move violates a rule.";
        }
    }
    else {
        cout << "Sorry, original squares cannot be changed.";
    }

    return false;


}
