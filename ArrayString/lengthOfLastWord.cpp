#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {

        vector<string> wordsVector;
        istringstream wordsStream(s);
        string word;

        while (wordsStream >> word)
        {
            wordsVector.push_back(word);
        }

        return wordsVector.back().length();
    }
};