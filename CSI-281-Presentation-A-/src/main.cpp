#include <iostream>
#include <list>
#include <cctype>

#include "GridMap.h"
using namespace std;

int main() {
    vector<vector<int>> inputGrid = {
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0, 0, 0, 0, 1, 0},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
    };
    
    Grid grid(inputGrid);

    // Matthew K
    // TEST GRID EDITOR---------------------------------------------------------------------------------
    char answer;
    Cell start(0,0), goal(9,9);
    cout << "Edit grid? (y/n): ";

    while (true)
    {
        cin >> answer;
        if (tolower(answer) == 'y')
        {
            pair<Cell, Cell> newGrid = grid.editGrid();
            start = newGrid.first;
            goal = newGrid.second;
            break;
        }
        else if (tolower(answer) == 'n')
        {
            break;
        }
        else
        {
            cout << "Please enter 'y' or 'n': ";
        }
    }
    
    
    //TEST GRID PRINT-----------------------------------------------------------------------------------
    grid.printGrid();
    cout << endl;


    //TEST PATHFIND ------------------------------------------------------------------------------------
    list<Cell> path = grid.aStar(start, goal);

    cout << "Path found:" << endl;
    for (const auto& cell : path) {
        cout << "(" << cell.x << ", " << cell.y << ") ";
    }
    cout << endl;
    cout << endl;

    //TEST PRINT ---------------------------------------------------------------------------------------
    grid.printPath(start, goal);

    return 0;
}
