#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> myCharStack;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                myCharStack.push(c);
            }
            else {
                if (myCharStack.empty()) {
                    return false; // No matching opening bracket
                }

                if (c == ')' && myCharStack.top() == '(') {
                    myCharStack.pop();
                }
                else if (c == ']' && myCharStack.top() == '[') {
                    myCharStack.pop();
                }
                else if (c == '}' && myCharStack.top() == '{') {
                    myCharStack.pop();
                }
                else {
                    return false; // Mismatched brackets
                }
            }
        }

        return myCharStack.empty(); // Check if all brackets are closed
    }
};