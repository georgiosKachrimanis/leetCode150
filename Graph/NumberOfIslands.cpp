/*
    Disclaimer this solution is not from me. I read it and then implemented it my self. 
    The reason of these problems is not on;y to test your abilities but also to teach you how to think some basic solutions.
    If it is too hard and you can not understand it is ok to search for a solution. The point is to understand and learn from it, not just copy/paste it.
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    void searchForConnectedLand(vector<vector<char>> &grid, int i, int j)
    {
        stack<pair<int, int>> landSquare;
        landSquare.push({i, j});

        // Search directions (up, down, left, right)
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Now we will check if the stack has any land('1')
        while (!landSquare.empty())
        {
            pair<int, int> currentSquare = landSquare.top();
            landSquare.pop();
            int x = currentSquare.first;
            int y = currentSquare.second;
            // We check first if we are out of bounds and if the coordinates are still an land.
            if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != '1')
            {
                continue;
            }

            // Now we mark the square as visited(counted in the island)
            grid[x][y] = '0';

            // Now I add the squares around the current one to stack to be searched
            for (auto direction : directions)
            {
                int newSquareX = x + direction.first;
                int newSquareY = y + direction.second;

                landSquare.push({newSquareX, newSquareY});
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty() || grid[0].empty())
        {
            return 0;
        }

        int numberOfIslands = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    numberOfIslands++;
                    searchForConnectedLand(grid, i, j);
                }
            }
        }

        return numberOfIslands;
    }
};

// The following solution causes a stack overflow in Cpp...
/* class Solution
{
public:
    void searchForConnectedLand(vector<vector<char>> &grid, int i, int j)
    {
        // We check first if we are out of bounds and if the coordinates are still an land.
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
        {
            return;
        }

        // now we change the land to '0' so we will not count it on the next search.(The land is visited).
        // Search up from the current land
        searchForConnectedLand(grid, i - 1, j);
        // Search down from the current land
        searchForConnectedLand(grid, i + 1, j);
        // Search left from the current land
        searchForConnectedLand(grid, i, j - 1);
        // Search right from the current land
        searchForConnectedLand(grid, i, j + 1);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        // manage empty grid
        if (grid.empty() || grid[0].empty())
        {
            return 0;
        }

        int numberOfIslands = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    numberOfIslands++;
                    searchForConnectedLand(grid, i, j);
                }
            }
        }

        return numberOfIslands;
    }
}; */
