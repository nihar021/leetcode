#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();

        vector<int> prev(m, 0); // Initialize a vector to store the previous row's path counts

        for (int i = 0; i < n; i++) {
            vector<int> temp(m, 0); // Initialize a temporary vector for the current row
            for (int j = 0; j < m; j++) {

                // Base conditions
                if ( obstacleGrid[i][j] == 1) {
                    temp[j] = 0; // If there's an obstacle at (i, j), no paths can pass through it
                    continue;
                }
                if (i == 0 && j == 0) {
                    temp[j] = 1; // If we are at the starting point, there is one path to it
                    continue;
                }

                int up = 0;
                int left = 0;

                // Check if we can move up and left (if not at the edge of the obstacleGrid)
                if (i > 0)
                    up = prev[j]; // Number of paths from above (previous row)
                if (j > 0)
                    left = temp[j - 1]; // Number of paths from the left (current row)

                // Total number of paths to reach (i, j) is the sum of paths from above and left
                temp[j] = up + left;
            }
            prev = temp; // Update the previous row with the current row
        }

        // The final result is stored in prev[m-1], which represents the destination in the last row
        return prev[m - 1];
    }
};


