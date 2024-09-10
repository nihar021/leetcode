class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        int c = cuts.size() - 2;  // Number of cuts excluding 0 and n

        // Create a DP table to store calculated values.
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

        // Start filling the DP table
        for (int i = c; i >= 1; i--) {
            for (int j = 1; j <= c; j++) {
                if (i > j) continue;

                int mini = INT_MAX;

                for (int ind = i; ind <= j; ind++) {
                    // Calculate the cost for making a cut at position 'ind'.
                    int ans = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];

                    mini = min(mini, ans);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][c];
    }
};
