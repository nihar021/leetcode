class Solution {
public:
    vector<vector<int>> generate(int numRows) {
     vector<vector<int>> pascals_triangle(numRows); 

     for(int row=0;row<numRows;row++){
        pascals_triangle[row].resize(row+1);
        pascals_triangle[row][0] = pascals_triangle[row][row] = 1;
        for(int pos=1;pos<row;pos++)
           pascals_triangle[row][pos]= pascals_triangle[row-1][pos-1]+ pascals_triangle[row-1][pos];
     } 
       return pascals_triangle;
    }
};