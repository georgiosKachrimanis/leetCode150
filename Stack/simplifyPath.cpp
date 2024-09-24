#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {

        stack<string> pathStack;
        string clearPath;
        stringstream ss(path);
        string tokenString;

        while (getline(ss, tokenString, '/'))
        {
            if (tokenString == "" || tokenString == ".")
            {
                // skip empty of current directory tokenStrings.
                continue;
            }
            else if (tokenString == "..")
            {
                // Now if the stack is not empty we will pop out the last entry, this directory is no needed any more
                if (!pathStack.empty())
                {
                    pathStack.pop();
                }
            }
            else
            {
                // There is a valid path string and is to be added in the path.
                pathStack.push(tokenString);
            }
        }

        // Now I create the new path with the items from the stack!
        while (!pathStack.empty())
        {
            clearPath = "/" + pathStack.top() + clearPath;
            pathStack.pop();
        }

        return clearPath.empty() ? "/" : clearPath;
    }
};