#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numbersMap;

        for (int i = 0; i < nums.size(); i++){
            numbersMap[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int difference = target - nums[i];
            if (numbersMap.count(difference) && numbersMap[difference] != i)
            {
                return {i, numbersMap[difference]};
            }
        }
        return {};
    }
};