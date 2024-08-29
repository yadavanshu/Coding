#include <iostream>
#include <vector>

using namespace std;

const char EMPTY = ' ';
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';

// Function prototypes
void printBoard(const vector<vector<char>> &board);
bool makeMove(vector<vector<char>> &board, int row, int col, char player);
bool checkWinner(const vector<vector<char>> &board, char player);
bool isBoardFull(const vector<vector<char>> &board);
bool isValidMove(const vector<vector<char>> &board, int row, int col);

int main()
{
    vector<vector<char>> board(3, vector<char>(3, EMPTY));
    char currentPlayer = PLAYER_X;
    bool gameWon = false;

    cout << "Tic-Tac-Toe Game\n";
    printBoard(board);

    while (!gameWon && !isBoardFull(board))
    {
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Validate move and apply it
        if (isValidMove(board, row, col))
        {
            makeMove(board, row, col, currentPlayer);
            printBoard(board);

            if (checkWinner(board, currentPlayer))
            {
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameWon = true;
            }
            else
            {
                // Switch player
                currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
            }
        }
        else
        {
            cout << "Invalid move. Try again." << endl;
        }
    }

    if (!gameWon)
    {
        cout << "It's a draw!" << endl;
    }

    return 0;
}

void printBoard(const vector<vector<char>> &board)
{
    cout << "  0 1 2\n";
    for (int i = 0; i < 3; ++i)
    {
        cout << i << ' ';
        for (int j = 0; j < 3; ++j)
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool makeMove(vector<vector<char>> &board, int row, int col, char player)
{
    board[row][col] = player;
    return true;
}

bool checkWinner(const vector<vector<char>> &board, char player)
{
    // Check rows and columns
    for (int i = 0; i < 3; ++i)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true;
    }

    return false;
}

bool isBoardFull(const vector<vector<char>> &board)
{
    for (const auto &row : board)
    {
        for (char cell : row)
        {
            if (cell == EMPTY)
            {
                return false;
            }
        }
    }
    return true;
}

bool isValidMove(const vector<vector<char>> &board, int row, int col)
{
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == EMPTY);
}
