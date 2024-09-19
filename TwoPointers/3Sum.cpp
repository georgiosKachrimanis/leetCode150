#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> threeSumOutput;

        int target = 0;

        set<vector<int>> tempThreeSum;

        // First sort the numbers to help us with finding the combinations we need.
        sort(nums.begin(), nums.end());

        // Now iterate through the nums and try to find combinations that will work.
        for (int i = 0; i < nums.size(); i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            // in this iteration if the sum of numbers i,j,k is less than the target means we need to add a bit more so we increase j.
            // If the sum is greater than the target we decrease k.
            // Do not forget the nums vector is now sorted thats why I use this technique!
            while(j<k)
            {
                int tempSum = nums[i] + nums[j] + nums[k];
                if (tempSum == target)
                {
                    tempThreeSum.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if (tempSum < target)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            } 
        }

        // Now iterate though the tempThreeSums and put them inside the vector.
        for(auto triplets: tempThreeSum)
        {
            threeSumOutput.push_back(triplets);
        }

        return threeSumOutput;
    }
};