#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> numbersMap;
        // First create an unordered map with the values of nums
        for (int i = 0; i < nums.size(); i++)
        {
            numbersMap[nums[i]] = i;
        }

        // Now for each number in the nums vector, I will check if there is a number inside the numbersMap
        // that is equal to the difference of target - current value of nums iteration. If there is such a number(difference) and is not the same number as the current iteration of nums
        // then I return the position of the curent iteration and the position of the difference.
        for (int i = 0; i < nums.size(); i++)
        {
            int difference = target - nums[i];
            if (numbersMap.count(difference) && numbersMap[difference] != i)
            {
                return {i + 1, numbersMap[difference] + 1};
            }
        }
        return {};
    }
};