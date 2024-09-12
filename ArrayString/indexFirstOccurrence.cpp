#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {

        int haystackSize = haystack.size();
        int needleSize = needle.size();

         for (int i = 0; i <= haystackSize - needleSize; i++) {
            // Check if the substring in haystack matches the needle
            int j;
            for (j = 0; j < needleSize; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;  // Mismatch found, break the inner loop
                }
            }
            // If the entire needle was matched, return the starting index
            if (j == needleSize) {
                return i;
            }
        }
        return -1;
    }
};