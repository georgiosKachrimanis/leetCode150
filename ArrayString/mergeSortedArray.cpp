#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {

        int count = 0;
        if (n > 0 && m > 0)
        {
            for (int i = m; i < nums1.size(); i++)
            {
                nums1[i] = nums2[count];
                count++;
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                nums1[i] = nums2[i];
            }
        }
        // Using build in functions to help with sorting. No need to reinvent the wheel if is not needed!
        sort(nums1.begin(), nums1.end());
    }
};