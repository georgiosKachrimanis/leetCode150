#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<pair<int, int>> zeroPositions;

        // We wil first store the locations that are 0 on the original matrix.
        // I know some of you may complain that this is like creating a new matrix but I need to mention that I am not creating a new matrix but a small vector.
        // This solution makes a much simpler and easier code to understand comparing with some of the solutions on this problem
        //
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    zeroPositions.push_back({i, j});
                }
            }
        }

        for (auto element : zeroPositions)
        {
            // First change the rows
            for (int j = 0; j < matrix[0].size(); j++)
            {
                matrix[element.first][j] = 0;
            }

            // Now we change the columns
            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][element.second] = 0;
            }
        }
    }
};