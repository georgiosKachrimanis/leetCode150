#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) { 
        
        // Sorting the vector
        sort(nums.begin(),nums.end());
        // I search on pairs if the two numbers are not the same the previous number is unique.
        for(int i=1;i<nums.size();i+=2)
        {
            if(nums[i]!=nums[i-1])
                return nums[i-1];
        }
        return nums[nums.size()-1];
    }
};