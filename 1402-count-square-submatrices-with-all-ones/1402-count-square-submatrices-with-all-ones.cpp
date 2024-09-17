class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        // Initialize first row and first column with the same values from the matrix
        for (int i = 0; i < n; i++) dp[i][0] = matrix[i][0];
        for (int j = 0; j < m; j++) dp[0][j] = matrix[0][j];
        
        // Fill the dp table for the rest of the elements
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 1) {
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
                }
            }
        }
        
        // Calculate the total sum of squares
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += dp[i][j];
            }
        }
        
        return sum;
    }
};