#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
       int n=prices.size(); 
       if (n == 0) return 0; // Edge case: No stocks to trade.

            // Create a 2D DP array with dimensions (n+1) x 2, initialized to 0
            vector<vector<int>> dp(n + 1, vector<int>(2, 0));

            // Loop through the stock prices from the end to the beginning
            for (int ind = n - 1; ind >= 0; ind--) {
                for (int buy = 0; buy <= 1; buy++) {
                    int profit;

                    if (buy == 0) { // We can buy the stock
                        profit = max(0 + dp[ind + 1][0], -prices[ind] + dp[ind + 1][1]);
                    }

                    if (buy == 1) { // We can sell the stock
                        profit = max(0 + dp[ind + 1][1], prices[ind] - fee + dp[ind + 1][0]);
                    }

                    dp[ind][buy] = profit;
                }
            }

    return dp[0][0]; // Return the maximum profit for buying.
    }
};

