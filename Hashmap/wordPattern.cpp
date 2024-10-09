#include <unordered_map>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string t)
    {
        vector<string> stringToWords;
        unordered_map<string, char> wordsToPattern;
        unordered_map<char, string> patternToWords;
        

        istringstream stringStreamT(t);

        string word;
        char patternChar;

        while (stringStreamT >> word)
        {
            stringToWords.push_back(word);
        }

        if (stringToWords.size() != pattern.size())
        {
            return false;
        }

        for (int i = 0; i < stringToWords.size(); i++)
        {
            word = stringToWords[i];
            patternChar = pattern[i];

            if (wordsToPattern.count(word))
            {
                if (wordsToPattern[word] != patternChar) return false;
            }
            else
            {
                wordsToPattern[word] = patternChar; 
            }

            if (patternToWords.count(patternChar))
            {
                if (patternToWords[patternChar] != word) return false;
            }
            else
            {
                patternToWords[patternChar] = word; 
            }
        }
        
        return true;

    }
};