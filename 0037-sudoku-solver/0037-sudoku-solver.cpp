class Solution {
public:
   bool isSafe(int row,int col,vector<vector<char>>& board,int val){
    for(int i=0;i<9;i++){
        if(board[row][i]==val){
            return false;
        }
        if(board[i][col]==val){
            return false;
        }
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val)//from row and column number you can get all i,j value of the box
          return false;
    }
    return true;
   }
    bool solve(vector<vector<char>>& board){
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col]=='.'){
                    for(int val='1';val<='9';val++){
                        if(isSafe(row,col,board,val)){
                            board[row][col]=val;

                            //recursive call
                            bool nextSolution=solve(board);
                            if(nextSolution){
                                return true;
                            }
                            else {
                                //backtrack
                                board[row][col]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        
    }
};