#include <iostream>
#include <vector>

using namespace std;

void printPiles(const vector<int> &piles);
bool isValidMove(const vector<int> &piles, int pileIndex, int numToRemove);
bool isGameOver(const vector<int> &piles);

int main()
{
    vector<int> piles = {3, 4, 5}; // Initial piles
    int pileIndex, numToRemove;

    while (!isGameOver(piles))
    {
        printPiles(piles);

        cout << "Enter pile index (0, 1, or 2): ";
        cin >> pileIndex;
        cout << "Enter number of objects to remove: ";
        cin >> numToRemove;

        if (isValidMove(piles, pileIndex, numToRemove))
        {
            piles[pileIndex] -= numToRemove;
        }
        else
        {
            cout << "Invalid move. Try again." << endl;
        }

        // AI Move (for simplicity, removes 1 object from the first non-empty pile)
        for (int i = 0; i < piles.size(); ++i)
        {
            if (piles[i] > 0)
            {
                piles[i]--;
                break;
            }
        }
    }

    printPiles(piles);
    cout << "Game over!" << endl;

    return 0;
}

void printPiles(const vector<int> &piles)
{
    for (int i = 0; i < piles.size(); ++i)
    {
        cout << "Pile " << i << ": " << piles[i] << " objects" << endl;
    }
}

bool isValidMove(const vector<int> &piles, int pileIndex, int numToRemove)
{
    return pileIndex >= 0 && pileIndex < piles.size() && piles[pileIndex] >= numToRemove && numToRemove > 0;
}

bool isGameOver(const vector<int> &piles)
{
    for (int pile : piles)
    {
        if (pile > 0)
        {
            return false;
        }
    }
    return true;
}
