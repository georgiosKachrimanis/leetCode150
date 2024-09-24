#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    void rotate(vector<vector<int>> &matrix)
    {
        // First transpose the matrix
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j > i)
                {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }

        // Now reverse the order of each row and done!
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        return;
    }
};