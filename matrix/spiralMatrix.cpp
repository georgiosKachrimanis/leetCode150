#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> spiralVector;

        if (matrix.empty())
            return spiralVector;

        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        while (top <= bottom && left <= right)
        {
            // Traverse top row
            for (int i = left; i <= right; i++)
            {
                spiralVector.push_back(matrix[top][i]);
            }
            top++; // Move the top boundary down

            // Traverse from top to bottom along the right column
            for (int i = top; i <= bottom; i++)
            {
                spiralVector.push_back(matrix[i][right]);
            }
            right--; // Move the right boundary to the left(inside)

            // Traverse from right to left along the bottom row (if there's still a row left)
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    spiralVector.push_back(matrix[bottom][i]);
                }
                bottom--; // Move the bottom boundary up
            }

            // Traverse from bottom to top along the left column (if there's still a column left)
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    spiralVector.push_back(matrix[i][left]);
                }
                left++; // Move the left boundary to the right
            }
        }

        return spiralVector;
    }
};

/*
    I add here the solution I found for the problem in LeetCode and It is really good idea to study it
    if you are not feeling super comfortable with algorithms ( I am also pointing the finger to myself ).

*/
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int x = 0;
        int y = 0;
        int dx = 1;
        int dy = 0;
        vector<int> res;

        for (int i = 0; i < rows * cols; i++)
        {
            res.push_back(matrix[y][x]);
            matrix[y][x] = -101;

            if (!(0 <= x + dx && x + dx < cols && 0 <= y + dy && y + dy < rows) || matrix[y + dy][x + dx] == -101)
            {
                int temp = dx;
                dx = -dy;
                dy = temp;
            }

            x += dx;
            y += dy;
        }

        return res;
    }
};