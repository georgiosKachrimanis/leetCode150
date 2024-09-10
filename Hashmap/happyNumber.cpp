/*
I need to be honest about this one. I found the solution online. 
But is really brilliant way of creating an exit condition from an infinite loop.
I am really glad that I found about it and will definitely use it in the future!

*/

#include <iostream>

using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        int fast;
        int slow;

        slow = getSquaredNumberSum(n);
        fast = getSquaredNumberSum(getSquaredNumberSum(n));

        while (fast != slow && fast != 1)
        {
            slow = getSquaredNumberSum(slow);
            fast = getSquaredNumberSum(getSquaredNumberSum(fast));
        }
        return fast == 1;
    }

    int getSquaredNumberSum(int n)
    {
        int squaredSum = 0;

        while (n != 0)
        {
            int temp = n % 10;
            squaredSum += temp * temp;
            n /= 10;
        }
        return squaredSum;
    }
};