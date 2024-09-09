#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
    map<char, int> frequencyMapS;
    map<char, int> frequencyMapT;

    // first we check if the strings are the same size...
    if (s.size() != t.size())
    {
        return false;
    }
    // Loop through each character in the strings and count the appearance.
    for (int i = 0; i < s.size();i++)
    {
        frequencyMapS[s[i]]++;
        frequencyMapT[t[i]]++;
    }

    // Now we check if the maps of s and t are the same.
    return frequencyMapS == frequencyMapT;
    }
};