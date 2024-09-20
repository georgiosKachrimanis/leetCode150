#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        // Sorting the vector
        sort(nums.begin(), nums.end());
        // I search the triplets if the 1st and 3rd numbers are not the same then 1st number is unique.
        for (int i = 2; i < nums.size(); i += 3)
        {
            if (nums[i] != nums[i - 2])
                return nums[i - 2];
        }
        return nums[nums.size() - 1];
    }
};
