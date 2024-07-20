class Solution {
public:
    int solve(string& a, string& b, int i, int j, vector<vector<int>>& memo) {
        // base case
        if (i == a.length()) {
            return b.length() - j;
        }
        if (j == b.length()) {
            return a.length() - i;
        }

        // check if the result is already computed
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int ans = 0;
        if (a[i] == b[j]) {
            ans = solve(a, b, i + 1, j + 1, memo);
        } else {
            // insert
            int insertAns = 1 + solve(a, b, i, j + 1, memo);
            // delete
            int deleteAns = 1 + solve(a, b, i + 1, j, memo);
            // replace
            int replaceAns = 1 + solve(a, b, i + 1, j + 1, memo);

            ans = min(insertAns, min(deleteAns, replaceAns));
        }

        // store the result in memo array
        memo[i][j] = ans;
        return ans;
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.length() + 1, vector<int>(word2.length() + 1, -1));
        return solve(word1, word2, 0, 0, memo);
    }
};
