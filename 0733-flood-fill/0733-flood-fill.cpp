class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& image, vector<vector<int>>& ans, int prevcol, int newcol) {
        int n = image.size();
        int m = image[0].size();
        ans[row][col] = newcol;  // Update the color at the current cell

        int delrow[4] = {-1, 0, +1, 0};
        int delcol[4] = {0, +1, 0, -1};

        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 
               && ans[nrow][ncol] != newcol && image[nrow][ncol] == prevcol) {
                dfs(nrow, ncol, image, ans, prevcol, newcol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prevcol = image[sr][sc];
        if (prevcol == color) return image;  // No need to fill if the target color is the same as the original color
        
        vector<vector<int>> ans = image;
        dfs(sr, sc, image, ans, prevcol, color);
        return ans;
    }
};
