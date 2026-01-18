/***********************************************************************************************
* --------------------------- Akiva, Caleb C, Caleb L, Matthew ---------------------------------
* 
* Sources: 
* Timers and chrono:
*     > https://stackoverflow.com/questions/30702759/implementing-a-timer-in-c
* Clearing Screen: 
*     > https://stackoverflow.com/questions/6486289/how-can-i-clear-console
* 
* 
***********************************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

struct Cell {
    int x, y;
    int parent_x, parent_y;
    float G, H, F;

    Cell(int x = 0, int y = 0, int parent_x = 0, int parent_y = 0, float G = 0, float H = 0, float F = 0) {
        this->x = x;
        this->y = y;
        this->parent_x = x;
        this->parent_y = y;
        this->G = G;
        this->H = H;
        this->F = F;
    }

    //Compares Cost for PQ
    bool operator>(const Cell& other) const {
        return F > other.F;
    }

    //Required to put the Cells in a Set
    bool operator<(const Cell& other) const {
        if (x == other.x) return y < other.y;
        return x < other.x;
    }

};
 
class Grid {
public:
    Grid(int rows = 0, int cols = 0) {
        this->rows = rows;
        this->cols = cols;
        grid = vector<vector<int>>(rows, vector<int>(cols, 0));
    }

    Grid(const vector<vector<int>>& inputGrid) {
        grid = inputGrid;
        rows = grid.size();
        cols = grid[0].size();
    }

    void addWall(int x, int y) {
        if (x >= 0 && x < rows && y >= 0 && y < cols) {
            grid[x][y] = 1;
        }
    }

    void removeWall(int x, int y) {
        if (x >= 0 && x < rows && y >= 0 && y < cols) {
            grid[x][y] = 0;
        }
    }

    void printGrid() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << (grid[i][j] == 1 ? "\033[31m#\033[0m"  : "\033[43m.\033[0m") << " ";
            }
            cout << endl;
        }
    }

    // Matthew K
    // Helper to clear terminal regardless of OS
    void clearScreen()
    {
        #ifdef _WIN32
                std::system("cls");  // Windows
        #else
                std::system("clear"); // Unix/Linux/macOS
        #endif
        return;
    }

    // Editing the grid
    pair<Cell, Cell> editGrid()
    {
        clearScreen();

        int gridCols = 0, gridRows = 0, x, y;
        string wall, start, end;
        char junk;

        // Prompt user for total area
        while (gridCols < 1 || gridRows < 1)
        {
            cout << "Number of grid Columns: ";
            cin >> gridCols;
            cout << "Number of grid Rows: ";
            cin >> gridRows;
            clearScreen();
        }
        cin.ignore();

        // Update size of grid and its vectors accoordingly
        cols = gridCols;
        rows = gridRows;
        grid.resize(rows);
        for (int i = 0; i < rows; i++)
        {
            grid[i].resize(cols);
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                grid[i][j] = 0;
            }
        }
        /* For testing */
        // cout << "Cols: " << gridCols << endl;
        // cout << "Rows: " << gridRows << endl;

        // Walls
        while (true)
        {
            // Prompt user for wall coordinates
            cout << "Enter coordinates for wall in the form x,x." << endl;
            cout << "To remove a wall enter its coordinates again." << endl;
            cout << "Leave blank to continue.\n";
            getline(cin, wall);
            stringstream coordinates(wall);
            coordinates >> x >> junk >> y;

            if (wall.empty()) // User is done adding walls
            {
                clearScreen();
                break;
            }

            if ((x >= 0 && y >= 0) && (x < cols && y < rows)) // add wall at specified Coordinates
            {
                // Check if wall exists
                if (grid[y][x] == 1) // Remove if so
                {
                    removeWall(y, x);
                    clearScreen();
                    cout << "Wall removed." << endl;
                    this_thread::sleep_for(chrono::seconds(1));
                }
                else // Add one if no wall exists in this location
                {
                    addWall(y, x);
                    clearScreen();
                    cout << " Wall added." << endl;
                    this_thread::sleep_for(chrono::seconds(1));
                }
            }
            else // input validation
            {
                clearScreen();
                cout << "Invalid input.\n";
                this_thread::sleep_for(chrono::seconds(1));

            }
            x = -1;
            y = -1;
            clearScreen();
        }

        // Setting the start/end 
        Cell Start(-1, -1), End(-1, -1);

        while (true)
        {
            // Prompt user for starting coordinates
            clearScreen();
            cout << "Enter coordinates for starting point in the form x,x." << endl;
            getline(cin, start);
            stringstream sCoordinates(start);
            sCoordinates >> x >> junk >> y;
            if (x < rows && x >= 0 && y < cols && y >= 0 && grid[x][y] != 1)
            {
                // Sets the beginning of the path if coordinates are valid
                Start = Cell(x, y); 
                clearScreen();
                cout << "Starting point set at (" << x << "," << y << ")\n";
                this_thread::sleep_for(chrono::seconds(1));
                break;
            }
            else
            {
                // Validate input
                clearScreen();
                cout << "Out of Bounds/invalid selection." << endl;
                this_thread::sleep_for(chrono::seconds(1));
                clearScreen();
            }
        }

        
        while (true)
        {
            // Prompt user for ending coordinates
            clearScreen();
            cout << "Enter coordinates for end point in the form x,x." << endl;
            getline(cin, end);
            stringstream eCoordinates(end);
            eCoordinates >> x >> junk >> y;
            if (x < rows && x >= 0 && y < cols && y >= 0 && grid[x][y] != 1)
            {
                // Sets the end of the path if coordinates are valid
                End = Cell(x, y);
                clearScreen();
                cout << "Endpoint point set at (" << x << "," << y << ")\n";
                clearScreen();
                this_thread::sleep_for(chrono::seconds(1));
                break;
            }
            else
            {
                // Validate input
                clearScreen();
                cout << "Out of Bounds/invalid selection." << endl;
                this_thread::sleep_for(chrono::seconds(1));
                clearScreen();
            }
        }

        // Returns both start and end cells
        return make_pair(Start, End);
    }

    // A* Algorithm
    using Path = list<Cell>;
    Path aStar(Cell start, Cell goal) {
        priority_queue<Cell, vector<Cell>, greater<Cell>> openList;
        set<Cell> closedList;

        openList.push(start);

        while (!openList.empty()) {
            Cell current = openList.top();
            openList.pop();

            //Finished Condition
            if (current.x == goal.x && current.y == goal.y) {
                Path finalPath;

                while (current.x != current.parent_x || current.y != current.parent_y) {
                    finalPath.push_front(current);

                    auto it = closedList.find(Cell(current.parent_x, current.parent_y));
                    if (it != closedList.end()) {
                        current = *it;
                    }
                }

                finalPath.push_front(current);

                return finalPath;
            }

            //Main
            closedList.insert(current);

            vector<Cell> neighbors = getNeighbors(current);
            for (auto& neighbor : neighbors) {
                if (closedList.find(neighbor) != closedList.end()) continue; 
                if (grid[neighbor.x][neighbor.y] == 1) continue;

                neighbor.G = current.G + 1;
                neighbor.H = heuristic(neighbor, goal);
                neighbor.F = neighbor.G + neighbor.H;

                neighbor.parent_x = current.x;
                neighbor.parent_y = current.y;

                openList.push(neighbor);
            }
        }

        cout << "There is no path between these two points" << endl;
        return {};
    }

    //A* visual
    void printPath(Cell start, Cell goal) {
        Path path = aStar(start, goal);

        if (path.empty()) {
            return;
        }


        vector<vector<string>> displayGrid(rows, vector<string>(cols, "\033[43m.\033[0m"));


        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    displayGrid[i][j] = "\033[31m#\033[0m";
                }
            }
        }

        //Mark the path with O's
        for (const auto& cell : path) {
            displayGrid[cell.x][cell.y] = "\033[33mO\033[0m";
        }

        for (const auto& row : displayGrid) {
            for (const auto& cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
    }

private:
    vector<vector<int>> grid;
    int rows, cols;

    float heuristic(const Cell& a, const Cell& b) {
        return abs(a.x - b.x) + abs(a.y - b.y);
    }

    //DIDN'T DO DIAGONALS - only up, down, left, right;
    vector<Cell> getNeighbors(const Cell& current) {
        vector<Cell> neighbors;
        int DIR_X = 0;
        int DIR_Y = 1;

        int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

        for (auto& dir : directions) {
            int newX = current.x + dir[DIR_X];
            int newY = current.y + dir[DIR_Y];

            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                neighbors.push_back(Cell(newX, newY));
            }
        }

        return neighbors;
    }
};
