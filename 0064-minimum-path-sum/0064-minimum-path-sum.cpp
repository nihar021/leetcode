#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> prev(m, 0); // Initialize a vector to store the previous row's minimum path sums

        for (int i = 0; i < n; i++) {
            vector<int> temp(m, 0); // Initialize a temporary vector for the current row
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0)
                    temp[j] = grid[i][j]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
                else {
                    // Calculate the minimum path sum considering moving up and moving left
                    int up = grid[i][j];
                    if (i > 0)
                        up += prev[j]; // Include the minimum path sum from above (previous row)
                    else
                        up += 1e9; // A large value if moving up is not possible (out of bounds)
                        

                    int left = grid[i][j];
                    if (j > 0)
                        left += temp[j - 1]; // Include the minimum path sum from the left (current row)
                    else
                        left += 1e9; // A large value if moving left is not possible (out of bounds)

                    
                    temp[j] = min(up, left);
                }
            }
            prev = temp;
        }

        return prev[m - 1];
            
    }
};

