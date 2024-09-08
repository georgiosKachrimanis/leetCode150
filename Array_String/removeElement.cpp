#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {

        vector<int> tempVector;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                tempVector.push_back(nums[i]);
            }
        }
        nums.clear();
        nums = tempVector;
        return nums.size();
    }
};