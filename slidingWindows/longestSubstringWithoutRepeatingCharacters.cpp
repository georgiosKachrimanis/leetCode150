/*


*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> charSet;
        int left = 0;
        int maxLength = 0;
        for (int right = 0; right < s.size(); right++)
        {
            char currentChar = s[right];

            while (charSet.find(currentChar) != charSet.end())
            {
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(currentChar);

            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};

/* This solution is a basic for loop: O(n^2) 223ms  so it is not suggested for real applications.
The first solution only needs about 16ms...O(n)
Still a good training exercise.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int maxStirngSize = 0;

        if (s.size() == 1)
        {
            return 1;
        }

        for (int i = 0; i < s.size(); i++)
        {
            vector<char> testString;
            int counter = 0;
            for (int j = i; j < s.size();j++)
            {
                char c = s[j];
                if (find(testString.begin(), testString.end(), c) != testString.end())
                {
                    maxStirngSize = max(maxStirngSize, counter);
                    break;
                }
                else
                {
                    testString.push_back(c);
                    counter++;
                }
            }
            maxStirngSize = max(maxStirngSize, counter);
        }
        return maxStirngSize;
        }
};

*/