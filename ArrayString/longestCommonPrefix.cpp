#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

if (strs.empty()) return "";

    // Iterate over each character index up to the length of the first string
    for (int i = 0; i < strs[0].size(); i++) {
        char current_char = strs[0][i];
        
        // Compare the current character with the corresponding character in other strings
        for (int j = 1; j < strs.size(); j++) {
            // If we reach the end of a string or find a mismatch, return the prefix so far
            if (i >= strs[j].size() || strs[j][i] != current_char) {
                return strs[0].substr(0, i);
            }
        }
    }

    // If no mismatch is found, the entire first string is the prefix
    return strs[0];
    }
};