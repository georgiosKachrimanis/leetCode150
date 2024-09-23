#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        vector<pair<int, string>> romanNumbers = 
        {
            {1000, "M"}, {900, "CM"}, {500, "D"}, 
            {400, "CD"}, {100, "C"}, {90, "XC"}, 
            {50, "L"}, {40, "XL"}, {10, "X"}, 
            {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        int placeCounter = 0;
        int tempNumber;
        vector<char> tempRomanString;
        string romanNumString;

        for (const auto &[value, symbol] : romanNumbers)
        {
            while (num >= value)
            {
                romanNumString += symbol;
                num -= value;
            }
        }
        return romanNumString;
    }
};



/* 
This is the fastest solution in LeetCode. 
class Solution {
public:
    string intToRoman(int num) {
        string Roman = "";
        while(num >= 1000){
            Roman += "M";
            num -= 1000;
        }
        while(num >= 100){
            if((num / 100) == 9){
                Roman += "CM";
                num -= 900;
            } else if ((num / 100) == 4){
                Roman += "CD";
                num -= 400;
            } else if(num >= 500){
                Roman += "D";
                num -= 500;
            } else {
                Roman += "C";
                num -= 100;
            }
        }
        while(num >= 10){
            if((num / 10) == 9){
                Roman += "XC";
                num -= 90;
            } else if ((num / 10) == 4){
                Roman += "XL";
                num -= 40;
            } else if(num >= 50){
                Roman += "L";
                num -= 50;
            } else {
                Roman += "X";
                num -= 10;
            }
        }
        while(num > 0){
            if(num == 9){
                Roman += "IX";
                num -= 9;
            } else if (num == 4) {
                Roman += "IV";
                num -= 4;
            } else if(num >= 5){
                Roman += "V";
                num -= 5;
            } else {
                Roman += "I";
                num -= 1;
            }
        }
        
        return Roman;
    }
};


*/