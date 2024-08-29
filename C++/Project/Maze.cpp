#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <utility>

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 10;

// Directions for moving in the maze
const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// Function prototypes
void generateMaze(vector<vector<int>> &maze);
void printMaze(const vector<vector<int>> &maze);
int solveMaze(const vector<vector<int>> &maze, vector<vector<int>> &solution);
int isValidMove(const vector<vector<int>> &maze, int x, int y, vector<vector<int>> &visited);

int main()
{
    srand(time(0));

    vector<vector<int>> maze(HEIGHT, vector<int>(WIDTH, 1));     // 1 represents walls
    vector<vector<int>> solution(HEIGHT, vector<int>(WIDTH, 0)); // 0 represents empty

    generateMaze(maze);
    printMaze(maze);

    if (solveMaze(maze, solution))
    {
        cout << "\nMaze solved!" << endl;
        printMaze(solution);
    }
    else
    {
        cout << "\nNo solution found!" << endl;
    }

    return 0;
}

void generateMaze(vector<vector<int>> &maze)
{
    // Depth-First Search (DFS) maze generation
    stack<pair<int, int>> s;
    vector<vector<int>> visited(HEIGHT, vector<int>(WIDTH, false));

    int startX = 0, startY = 0;
    s.push({startX, startY});
    visited[startX][startY] = true;

    while (!s.empty())
    {
        auto [x, y] = s.top();
        s.pop();

        vector<pair<int, int>> neighbors;
        for (auto [dx, dy] : DIRECTIONS)
        {
            int nx = x + dx * 2;
            int ny = y + dy * 2;
            if (nx >= 0 && nx < HEIGHT && ny >= 0 && ny < WIDTH && !visited[nx][ny])
            {
                neighbors.emplace_back(nx, ny);
            }
        }

        if (!neighbors.empty())
        {
            s.push({x, y});
            auto [nx, ny] = neighbors[rand() % neighbors.size()];
            maze[nx][ny] = 0;
            maze[x + (nx - x) / 2][y + (ny - y) / 2] = 0;
            visited[nx][ny] = true;
            s.push({nx, ny});
        }
    }
}

void printMaze(const vector<vector<int>> &maze)
{
    for (const auto &row : maze)
    {
        for (int cell : row)
        {
            cout << (cell ? "#" : " ");
        }
        cout << endl;
    }
}

int solveMaze(const vector<vector<int>> &maze, vector<vector<int>> &solution)
{
    vector<vector<int>> visited(HEIGHT, vector<int>(WIDTH, false));
    queue<pair<int, int>> q;
    vector<pair<int, int>> prev(HEIGHT * WIDTH, {-1, -1});

    q.push({0, 0});
    visited[0][0] = true;
    prev[0] = {0, 0};

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (x == HEIGHT - 1 && y == WIDTH - 1)
        {
            // Trace back the path
            while (!(x == 0 && y == 0))
            {
                solution[x][y] = 1;
                auto [px, py] = prev[x * WIDTH + y];
                x = px;
                y = py;
            }
            solution[0][0] = 1;
            return true;
        }

        for (auto [dx, dy] : DIRECTIONS)
        {
            int nx = x + dx;
            int ny = y + dy;
            if (isValidMove(maze, nx, ny, visited))
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
                prev[nx * WIDTH + ny] = {x, y};
            }
        }
    }
    return false;
}

int isValidMove(const vector<vector<int>> &maze, int x, int y, vector<vector<int>> &visited)
{
    return x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH && !visited[x][y] && maze[x][y] == 0;
}
