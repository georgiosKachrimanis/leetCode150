#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {}; // Return an empty vector if there are no digits

        // Map the digits to associated characters
        map<char, string> numMap = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        vector<string> combinations;
        string currentCombination;
        backtrack(digits, numMap, 0, currentCombination, combinations);
        return combinations;
    }

private:
    void backtrack(const string &digits, map<char, string> &numMap, int index, string &currentCombination, vector<string> &combinations)
    {
        // Base case: if the current combination is as long as the input digits
        if (index == digits.size())
        {
            combinations.push_back(currentCombination);
            return;
        }

        // Get the letters corresponding to the current digit
        char currentDigit = digits[index];
        string letters = numMap[currentDigit];

        // Loop through each letter and append to the current combination
        for (char letter : letters)
        {
            currentCombination.push_back(letter);
            backtrack(digits, numMap, index + 1, currentCombination, combinations); // Recursive call
            currentCombination.pop_back();                                          // Backtrack
        }
    }
};
