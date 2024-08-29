#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 9; // Size of the Sudoku grid

// Function prototypes
bool solveSudoku(vector<vector<int>> &board);
bool isValidMove(const vector<vector<int>> &board, int row, int col, int num);
bool findEmptyCell(const vector<vector<int>> &board, int &row, int &col);
void printBoard(const vector<vector<int>> &board);

int main()
{
    // Define the Sudoku puzzle (0 means empty cell)
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if (solveSudoku(board))
    {
        cout << "Sudoku solved successfully!" << endl;
        printBoard(board);
    }
    else
    {
        cout << "No solution exists." << endl;
    }

    return 0;
}

bool solveSudoku(vector<vector<int>> &board)
{
    int row, col;

    // Find an empty cell
    if (!findEmptyCell(board, row, col))
    {
        return true; // No empty cell found, puzzle solved
    }

    // Try all possible numbers (1 to 9)
    for (int num = 1; num <= 9; ++num)
    {
        if (isValidMove(board, row, col, num))
        {
            board[row][col] = num; // Place the number

            // Recursively attempt to solve the rest of the board
            if (solveSudoku(board))
            {
                return true; // Solved
            }

            // If placing num didn't lead to a solution, undo it
            board[row][col] = 0;
        }
    }

    return false; // Trigger backtracking
}

bool isValidMove(const vector<vector<int>> &board, int row, int col, int num)
{
    // Check row
    for (int x = 0; x < SIZE; ++x)
    {
        if (board[row][x] == num)
        {
            return false;
        }
    }

    // Check column
    for (int x = 0; x < SIZE; ++x)
    {
        if (board[x][col] == num)
        {
            return false;
        }
    }

    // Check 3x3 grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i + startRow][j + startCol] == num)
            {
                return false;
            }
        }
    }

    return true;
}

bool findEmptyCell(const vector<vector<int>> &board, int &row, int &col)
{
    for (row = 0; row < SIZE; ++row)
    {
        for (col = 0; col < SIZE; ++col)
        {
            if (board[row][col] == 0)
            {
                return true;
            }
        }
    }
    return false;
}

void printBoard(const vector<vector<int>> &board)
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}
