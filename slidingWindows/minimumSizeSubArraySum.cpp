#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {

        // Before we start any real searching I will see if there is a number equal to the target in nums this runs for 35ms
        // If you remove this part then you are at 27ms... It is up to you!
        if (count(nums.begin(), nums.end(), target))
        {
            return 1;
        }

        int startingPosition = 0;
        int currSum = 0;
        int minSize = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            currSum += nums[i];

            while (currSum >= target)
            {
                minSize = min(minSize, i - startingPosition + 1);
                currSum -= nums[startingPosition];
                startingPosition++;
            }
        }
        // For people not used to ternary operator-> condition ? value_if_true : value_if_false;
        return (minSize != INT_MAX) ? minSize : 0;
    }
};