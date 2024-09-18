#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> elementsMap;

        // if vector is empty return 0;
        if (nums.empty())
        {
            return 0;
        }

        // count the occurrences of each number
        for (int num : nums)
        {
            elementsMap[num]++;
        }

        // Now search the map for the number with the most occurrences and return it. 
        int maxCount = 0;
        int mostFrequentNum = elementsMap[0];

        for (const auto& pair: elementsMap)
        {
            if (pair.second > maxCount){
                maxCount = pair.second;
                mostFrequentNum = pair.first;
            }
        }

        return mostFrequentNum;
    }
};
