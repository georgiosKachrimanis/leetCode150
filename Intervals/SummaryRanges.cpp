#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> rangesVector;
        if (nums.empty())
            return rangesVector;
        int rangeStart = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if ((i == nums.size() - 1) || (nums[i] + 1 != nums[i + 1]))
            {
                if (rangeStart == nums[i])
                {
                    rangesVector.push_back(to_string(rangeStart));
                }
                else
                {
                    rangesVector.push_back(to_string(rangeStart) + "->" + to_string(nums[i]));
                }
                if (i != nums.size() - 1)
                {
                    rangeStart = nums[i + 1];
                }
            }
        }

        return rangesVector;
    }
};