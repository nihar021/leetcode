//T.C.=O(n^2)
//S.C.=O(n^2)
// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int r = matrix.size();  // Number of rows
//         int c = matrix[0].size();  // Number of columns
//         vector<vector<int>> result(r, vector<int>(c, 0)); 
        
//         // Fill the 'result' matrix with rotated elements
//         for (int i = 0; i < c; ++i) {
//             for (int j = r - 1; j >= 0; --j) {
//                 result[i][r - 1 - j] = matrix[j][i];
//             }
//         }

//         // Copy the 'result' matrix back to 'matrix'
//         matrix = result;
//     }
// };


//To reduce Space Complexity
//SC=O(1)
//TC=O(n^2)
//1.Transpose 2.revese Each row
#include<bits/stdc++.h>
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r = matrix.size();  // Number of rows
        int c = matrix[0].size();  // Number of columns
        
        // TransPose of the matrix(Only Upper mirror Half)
        for (int i = 0; i < r-1; ++i) {
            for (int j = i+1; j < c; ++j) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        // Reverse each row
        for(int i=0;i<r;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
