#include <iostream>
#include <vector>
#include <cstdlib>
#include <unistd.h> // For sleep() on UNIX-based systems (use <windows.h> for Windows)
#include <conio.h>  // For _kbhit() and _getch() on Windows (for user input)

using namespace std;

// Define the board dimensions
const int ROWS = 20;
const int COLS = 40;

// Function prototypes
void initializeBoard(vector<vector<bool>> &board);
void displayBoard(const vector<vector<bool>> &board);
void updateBoard(vector<vector<bool>> &board);
int countLiveNeighbors(const vector<vector<bool>> &board, int row, int col);

int main()
{
    vector<vector<bool>> board(ROWS, vector<bool>(COLS, false));

    initializeBoard(board);

    cout << "Press 'q' to quit." << endl;

    while (true)
    {
        system("clear"); // Clear screen (use "cls" for Windows)
        displayBoard(board);
        updateBoard(board);

        // Check for user input to exit the loop
        if (_kbhit())
        {                       // For Windows
            char ch = _getch(); // For Windows
            if (ch == 'q' || ch == 'Q')
            {
                break;
            }
        }

        usleep(200000); // Sleep for 200 milliseconds (use Sleep(200) for Windows)
    }

    return 0;
}

void initializeBoard(vector<vector<bool>> &board)
{
    // Initialize the board with a simple pattern (Glider for example)
    board[1][2] = true;
    board[2][3] = true;
    board[3][1] = true;
    board[3][2] = true;
    board[3][3] = true;
}

void displayBoard(const vector<vector<bool>> &board)
{
    for (const auto &row : board)
    {
        for (bool cell : row)
        {
            cout << (cell ? '*' : ' ') << ' ';
        }
        cout << endl;
    }
}

void updateBoard(vector<vector<bool>> &board)
{
    vector<vector<bool>> newBoard(ROWS, vector<bool>(COLS, false));

    for (int row = 0; row < ROWS; ++row)
    {
        for (int col = 0; col < COLS; ++col)
        {
            int liveNeighbors = countLiveNeighbors(board, row, col);

            if (board[row][col])
            {
                if (liveNeighbors < 2 || liveNeighbors > 3)
                {
                    newBoard[row][col] = false; // Cell dies
                }
                else
                {
                    newBoard[row][col] = true; // Cell lives
                }
            }
            else
            {
                if (liveNeighbors == 3)
                {
                    newBoard[row][col] = true; // Cell becomes alive
                }
            }
        }
    }

    board = newBoard;
}

int countLiveNeighbors(const vector<vector<bool>> &board, int row, int col)
{
    int liveNeighbors = 0;

    for (int r = row - 1; r <= row + 1; ++r)
    {
        for (int c = col - 1; c <= col + 1; ++c)
        {
            if (r >= 0 && r < ROWS && c >= 0 && c < COLS && !(r == row && c == col) && board[r][c])
            {
                ++liveNeighbors;
            }
        }
    }

    return liveNeighbors;
}
