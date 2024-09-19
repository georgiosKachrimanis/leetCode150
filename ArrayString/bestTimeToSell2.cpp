#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;
        int tempProfit = 0;
        int tempMinPrice = prices[0];
        int minPrice = prices[0];
        

        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < minPrice)
            {
                minPrice = prices[i];
            }
            else if(prices[i]- minPrice > maxProfit)
            {
                maxProfit = prices[i] - minPrice;
            }

            // Now with this if and else if I am checking the following prices. 
            //If they are higher value than the minimum then I sell and add the selling value to the tempProfit.
            
            if (prices[i] < tempMinPrice)
            {
                tempMinPrice = prices[i];
            }
            else if(prices[i] > tempMinPrice)
            {
                tempProfit += prices[i] - tempMinPrice;
                tempMinPrice = prices[i];
            }
        }

        // I return the value that is greater, the one time sell or the multiple selling actions.
        return max(maxProfit, tempProfit);
    }
};