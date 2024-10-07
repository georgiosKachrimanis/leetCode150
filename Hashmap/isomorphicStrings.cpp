#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> sStringToT;
        unordered_map<char, char> tStringToS;
        char sChar;
        char tChar;

        if (s.size() != t.size())
        {
            return false;
        }

        for (int i = 0; i < s.size(); i++)
        {
            sChar = s[i];
            tChar = t[i];

            // If sChar is already mapped, check if it maps to the same character in t
            if (sStringToT.count(sChar))
            {
                if (sStringToT[sChar] != tChar) return false;
            }
            else
            {
                sStringToT[sChar] = tChar; // Map sChar to tChar
            }

            // If tChar is already mapped, check if it maps to the same character in s
            if (tStringToS.count(tChar))
            {
                if (tStringToS[tChar] != sChar) return false;
            }
            else
            {
                tStringToS[tChar] = sChar; // Map tChar to sChar
            }
        }
        return true;

    }
};