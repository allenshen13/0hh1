/**
 * test.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1 Test Suite
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#A description of the project here#>
 */

#include <iostream>
#include "utility.h"
#include "ohhi.h"

void test_count_unknown_squares();
void test_row_Has_No_Threes_Of_Color();
void test_col_Has_No_Threes_Of_Color();
void test_board_has_no_threes();
void test_rows_are_different();
void  test_cols_are_different();
void test_board_has_no_duplicates();
void test_solve_three_in_a_row();
void test_solve_three_in_a_column();
void test_solve_balance_row();
void test_solve_balance_column();
void test_check_valid_input();
void test_board_is_solved();
void test_check_valid_move();

   



// declare more test functions here

void startTests() {
    test_count_unknown_squares();
    test_row_Has_No_Threes_Of_Color();
    test_col_Has_No_Threes_Of_Color();
    test_board_has_no_threes();
    test_rows_are_different();
    test_cols_are_different();
    test_board_has_no_duplicates();
    test_solve_three_in_a_row();
    test_solve_three_in_a_column();
    test_solve_balance_row();
    test_solve_balance_column();
    test_check_valid_input();
    test_board_is_solved();
    test_check_valid_move();
    // add your calls to test functions here
}


void test_count_unknown_squares() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"XOXO",
                             "X-OO",
                             "X--X",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: 6, Actual: ";
    cout << count_unknown_squares(board, size_1) << endl;

    string test_board_2[] = { "----",
                            "----",
                            "----",
                            "----" };
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << "Expected: 16, Actual: ";
    cout << count_unknown_squares(board, size_2) << endl;

    string test_board_3[] = { "XOOX",
                            "OXOX",
                            "XOXO",
                            "XOOX" };
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << "Expected: 0, Actual: ";
    cout << count_unknown_squares(board, size_3) << endl;
    // add more tests here
}


void test_row_Has_No_Threes_Of_Color() {
    int board[MAX_SIZE][MAX_SIZE];

    string test_board_1[] = { "XOXO",
                             "-XXX",
                             "---X",
                             "--O-" };

    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << row_has_no_threes_of_color(board, size_1, 1, RED) << endl;


}
void test_col_Has_No_Threes_Of_Color() {
    int board[MAX_SIZE][MAX_SIZE];

    string test_board_1[] = { "XOOX",
                             "XXXX",
                             "X-OO",
                             "--OO" };

    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << col_has_no_threes_of_color(board, size_1, 0, RED) << endl;
}

void test_board_has_no_threes() {
    int board[MAX_SIZE][MAX_SIZE];

    string test_board_1[] = { "XOOX",
                             "XXXX",
                             "X-OO",
                             "--OO" };
    
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: 0, Actual: ";
    cout << board_has_no_threes(board, size_1) << endl;

    string test_board_2[] = { "XOOX",
                              "XOXX",
                              "O-OO",
                              "--OO" };

    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << "Expected: 1, Actual: ";
    cout << board_has_no_threes(board, size_2) << endl;
}

// define more test functions here
void test_rows_are_different() {
    int board[MAX_SIZE][MAX_SIZE];

    string test_board_1[] = { "XOOX",
                             "XOOX",
                             "X-OO",
                             "--OO" };

    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: 0, Actual: ";
    cout << rows_are_different(board, size_1, 0, 1) << endl;

    int board2[MAX_SIZE][MAX_SIZE];
    string test_board_2[] = { "XOO-",
                             "XOO-",
                             "X-OO",
                             "--OO" };

    int size_2 = 4;
    read_board_from_string(board2, test_board_2, size_2);
    cout << "Expected: 1, Actual: ";
    cout << rows_are_different(board2, size_2, 0, 1) << endl;

    int board3[MAX_SIZE][MAX_SIZE];
    string test_board_3[] = {"XOO-",
                            "XOOO",
                            "XOOO",
                            "--OO" };

    int size_3 = 4;
    read_board_from_string(board3, test_board_3, size_3);
    cout << "Expected: 0, Actual: ";
    cout << rows_are_different(board3, size_3, 1, 2) << endl;

}
void test_cols_are_different(){
    int board[MAX_SIZE][MAX_SIZE];

    string test_board_1[] = {"XXOX",
                             "XXXX",
                             "XXOO",
                             "OOOO" };

    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: 0, Actual: ";
    cout << cols_are_different(board, size_1, 0, 1) << endl;

}
void test_board_has_no_duplicates(){
    cout << "Testing board_has_no_duplicates" << endl;
    int board[MAX_SIZE][MAX_SIZE];

    string test_board_1[] = { "XXOX",
                             "XXXX",
                             "XXOO",
                             "OOOO" };

    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: 0, Actual: ";
    cout << board_has_no_duplicates(board, size_1) << endl;

    int board2[MAX_SIZE][MAX_SIZE];
    int size_2 = 4;
    string test_board_2[] = { "XXOX",
                             "XXXX",
                             "-XOO",
                             "OOOO" };

    read_board_from_string(board2, test_board_2, size_2);
    cout << "Expected: 1, Actual: ";
    cout << board_has_no_duplicates(board2, size_2) << endl;
}


void test_solve_three_in_a_row() {
    int board[MAX_SIZE][MAX_SIZE];
    cout << "Testing solve_three_in_a_row: " << endl;

    // test case 1
    string test_board_1[] = { "XX-O",
                             "-OO-",
                             "X--X",
                             "--O-" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    solve_three_in_a_row(board, size_1, 0, true);
    solve_three_in_a_row(board, size_1, 1, true);


    int board2[MAX_SIZE][MAX_SIZE];
    string test_board_2[] = { "XX-O",
                            "-OO-",
                            "X--X",
                            "--O-" };
    int size_2 = 4;
    read_board_from_string(board2, test_board_2, size_2);
    solve_three_in_a_row(board2, size_2, 3, true);
    solve_three_in_a_row(board2, size_2, 2, true);


}

void test_solve_three_in_a_column() {
    int board[MAX_SIZE][MAX_SIZE];
    cout << "Testing solve_three_in_a_column: " << endl;

    // test case 1
    string test_board_1[] = { "XX-O",
                             "-XO-",
                             "X--X",
                             "--O-" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    solve_three_in_a_column(board, size_1, 0, true);
    solve_three_in_a_column(board, size_1, 1, true);


    // test case 1
    string test_board_2[] = { "XX-O",
                             "-XO-",
                             "X--X",
                             "--O-" };
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    solve_three_in_a_column(board, size_2, 0, true);
    solve_three_in_a_column(board, size_2, 1, true);



}


void test_solve_balance_row() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_2[] = { "X--O",
                             "X-OO",
                             "X--X",
                             "--O-" };
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    solve_balance_row(board, size_2, 2, true);

    string test_board_3[] = { "X--X",
                           "X-OO",
                           "X--X",
                           "--O-" };
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    solve_balance_row(board, size_3, 0, true);


    string test_board_4[] = { "X--O",
                          "X-OO",
                          "X--X",
                          "--O-" };
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    solve_balance_row(board, size_4, 0, true);

    string test_board_5[] = { "X--OOX",
                          "X-OOXO",
                          "X--X--",
                          "--O-XO",
                          "X--X-X",
                          "O-X-XO" };
    int size_5 = 6;
    read_board_from_string(board, test_board_5, size_5);
    solve_balance_row(board, size_5, 0, true);
    solve_balance_row(board, size_5, 2, true);

    }

void test_solve_balance_column() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"XOXO",
                             "X-OO",
                             "X--X",
                             "-OO-" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    solve_balance_column(board, size_1, 1, true);




}
void test_check_valid_input() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
   
    int row = 2, col = 1;

    cout << check_valid_input(4, 4, 'b', 'z', row, col) << endl;

  
    string test_board_2[] = { "OXOX",
                             "OXXO",
                             "XOXO",
                             "XOOX" };
    int size_2 = 4;
    int row1 = 2, col1 = 1;
    read_board_from_string(board, test_board_2, size_2);
    cout << check_valid_input(4, 1, 'b', 'X', row1, col1) << endl;
}



void test_board_is_solved() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    cout << "Testing board_is_solved()" << endl;
    string test_board_1[] = { "OXOX",
                             "OXXO",
                             "XOXO",
                             "XOOX" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << board_is_solved(board, size_1) << endl;


    string test_board_2[] = { "OXOX",
                             "OXXO",
                             "XOXO",
                             "XOOX" };
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << board_is_solved(board, size_2);
}

void test_check_valid_move() {
    cout << "Testing test_check_valid_move() " << endl;
    int board[MAX_SIZE][MAX_SIZE];
    string test_board_1[] = { "----",
                            "XXO-",
                            "-XO-",
                            "--X-" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << board_is_solved(board, size_1);
    
    int board2[MAX_SIZE][MAX_SIZE];
    string test_board_2[] = { "---X",
                            "XXOO",
                            "XXO-",
                            "--X-" };
    int size_2 = 4;
    read_board_from_string(board2, test_board_2, size_2);
    check_valid_move(board, board2, size_1, 2, 3, BLUE);
    check_valid_move(board, board2, size_1, 1, 3, UNKNOWN);
    check_valid_move(board, board2, size_1, 2, 3, RED);
    check_valid_move(board, board2, size_1, 3, 2, BLUE);
}
