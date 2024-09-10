#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        set<int> tempSet;
        vector<int> cleanedVector;
        // I use Set that automaticaly checks if there is an existing element with the same values.
        for (int element : nums)
        {
            tempSet.insert(element);
        }
        // Create a vector from the Set values.
        for (int element : tempSet)
        {
            cleanedVector.push_back(element);
        }
        nums = cleanedVector;
        return tempSet.size();
    }
};