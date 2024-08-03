#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
   
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0] = nums[0];

         // Iterate through the elements of the numsay
        for (int i = 1; i < n; i++) {
            // Calculate the maximum value by either picking the current element
            // or not picking it (i.e., taking the maximum of dp[i-2] + nums[i] and dp[i-1])
            int pick = nums[i];
            if (i > 1)
                pick += dp[i - 2];
            int nonPick = dp[i - 1];
            
            // Store the maximum value in the dp numsay
            dp[i] = max(pick, nonPick);
        }
        // The last element of the dp numsay will contain the maximum sum
    return dp[n - 1];
    }
};


