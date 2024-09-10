/*

This is a basic solution, if you check the problem you will find really inspiring solutions for the same problem. 
I suggest to see the solutions from other people because it is a good way to expand your knowledge and way of thinking.

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        char romanChar;
        int total = 0;

        for (int i = 0; i < s.size(); i++)
        {
            romanChar = s[i];
            switch(romanChar)
            {
                case 'I':
                    if (s[i+1] == 'X')
                    {
                        total += 9;
                        i++;
                        break;
                    }
                    else if (s[i+1] == 'V')
                    {
                        total += 4;
                        i++;
                        break;
                    }
                    else
                    {
                        total++;
                        break;
                    }
                case 'V':
                    {
                        total += 5;
                        break;
                    }
                case 'X':
                    if (s[i+1] == 'C')
                    {
                        total += 90;
                        i++;
                        break;
                    }
                    else if (s[i+1] == 'L')
                    {
                        total += 40;
                        i++;
                        break;
                    }
                    else
                    {
                        total += 10;
                        break;
                    }
                case 'L':
                {
                    total += 50;
                    break;
                }
                case 'C':
                    if (s[i+1] == 'M')
                    {
                        total += 900;
                        i++;
                        break;
                    }
                    else if (s[i+1] == 'D')
                    {
                        total += 400;
                        i++;
                        break;
                    }
                    else
                    {

                        total += 100;
                        break;
                    }
                case 'D':
                    {
                        total += 500;
                        break;
                    }
                case 'M':
                    {
                        total += 1000;
                        break;
                    }
            }
  
        }
        return total;
    }
};