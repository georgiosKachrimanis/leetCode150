#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        map<char, int> magazineLetterCount;
        map<char, int> ransomNoteLetterCount;

        for (char character : ransomNote)
        {
            ransomNoteLetterCount[character]++;
        }

        for (char character : magazine)
        {
            magazineLetterCount[character]++;
        }

        for (const auto& pair: ransomNoteLetterCount)
        {
            char  letter = pair.first;
            int count1 = pair.second;

            if (magazineLetterCount.find(letter) == magazineLetterCount.end() || magazineLetterCount.at(letter) < count1)
            {
                return false;
            }
        }

        return true;

        }
};