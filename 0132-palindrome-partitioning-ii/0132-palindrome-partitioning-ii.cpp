class Solution {
private:
    // Check if a substring str[ind...j] is a palindrome
    bool isPalindrome(int ind, int j, string &str) {
        while (ind < j) {
            if (str[ind] != str[j]) 
                return false;
            ind++;
            j--;
        }
        return true;
    }

    // Memoized recursive function to find the minimum cuts
    int solve(int ind, int n, string &str, vector<int> &dp) {
        if (ind == n) 
            return 0;  // No more cuts needed

        if (dp[ind] != -1) 
            return dp[ind];  // Return cached result

        int minCost = INT_MAX;
        for (int j = ind; j < n; j++) {
            if (isPalindrome(ind, j, str)) {
                // If str[ind...j] is a palindrome, make a cut after j
                int cost = 1 + solve(j + 1, n, str, dp);
                minCost = min(minCost, cost);
            }
        }
        return dp[ind] = minCost;
    }

public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n, -1);  // Initialize DP array with -1
        return solve(0, n, s, dp) - 1;  // Subtract 1 because we don't need a cut at the end
    }
};
