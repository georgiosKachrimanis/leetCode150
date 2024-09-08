#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        vector<int> tempVector;
        vector<int> cleanedVector;

        for (int element : nums)
        {
            if (count(tempVector.begin(), tempVector.end(), element) >= 0 && count(tempVector.begin(), tempVector.end(), element) <= 1)
            {
                tempVector.push_back(element);
            }
        }

        nums = tempVector;
        return tempVector.size();
    }
};