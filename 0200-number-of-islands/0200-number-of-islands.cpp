class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited, int n, int m) {
        visited[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row, col});

        // These arrays represent the four possible directions (up, down, left, right)
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int curRow = q.front().first;
            int curCol = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {  // Only four directions instead of eight
                int nRow = curRow + delRow[i];
                int nCol = curCol + delCol[i];
                if (nRow < n && nRow >= 0 && nCol < m && nCol >= 0 
                    && grid[nRow][nCol] == '1' && !visited[nRow][nCol]) {
                    visited[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!visited[row][col] && grid[row][col] == '1') {
                    cnt++;
                    bfs(row, col, grid, visited, n, m);
                }
            }
        }
        return cnt;
    }
};
