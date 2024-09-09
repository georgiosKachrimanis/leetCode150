#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        
        string cleanString;
        string reverseCleanString;

        for (int i = 0; i < s.size(); i++){

            if (isalnum(s[i]))
            {
                cleanString += tolower(s[i]);
            }
        }

        if (cleanString == "")
        {
            return true;
        }
        else
        {
            reverseCleanString = cleanString;
            reverse(reverseCleanString.begin(), reverseCleanString.end());
            return reverseCleanString == cleanString;
        }
    }
};