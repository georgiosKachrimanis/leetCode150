#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // Sort the intervals based on the starting values because you know why...
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> newVector;
        vector<int> tempVector = intervals[0];

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= tempVector[1])
            {

                tempVector[1] = max(tempVector[1], intervals[i][1]);
            }
            else
            {
                newVector.push_back(tempVector);
                tempVector = intervals[i];
            }
        }

        newVector.push_back(tempVector);

        return newVector;
    }
};
