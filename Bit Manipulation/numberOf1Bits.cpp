#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        bitset<32> numInBits(n);

        int counter = 0;
        string numInString = numInBits.to_string();

        for (int i = 0; i < 32;i++)
        {
            if (numInString[i] == '1')
            {
                counter++;
            }
        }
        return counter;
    }
};