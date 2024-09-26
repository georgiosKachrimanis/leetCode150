#include <iostream>
#include <vector>
using namespace std;

/*
Solution 1: Probably the worst option.
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k = k% nums.size(); // for cases that the size of k is bigger than the nums
        if (nums.size() == 0 || nums.size() == 1 )
        {
            return;
        }
        int newBeginPosition = nums.size() - k;
        vector<int> newNums;

        for (int i = newBeginPosition; i < nums.size(); i++)
        {
            newNums.push_back(nums[i]);
        }

        for (int i = 0; i < newBeginPosition; i++)
        {
            newNums.push_back(nums[i]);
        }

        nums = newNums;
    }
};

*/

/*
This solution is over the time limit///

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n; // In case k is larger than the size of the vector

        // Perform the rotation k times
        for (int j = 0; j < k; j++)
        {
            // Store the last element
            int last = nums[n - 1];

            // Shift all elements one position to the right
            for (int i = n - 1; i > 0; i--)
            {
                nums[i] = nums[i - 1];
            }

            // Set the first element to the last element (completing the rotation)
            nums[0] = last;
        }
    }
};

*/
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k = k% nums.size(); // for cases that the size of k is bigger than the nums

        reverse(nums.begin(), nums.end());

        reverse(nums.begin(), nums.begin() + k);

        reverse(nums.begin() + k, nums.end());
    }
};
