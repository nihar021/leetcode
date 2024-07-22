class Solution {
public:
   int n;
   vector<vector<int>> dp;
   int solve(int i,int amount, vector<int>& coins){
    
    if(amount==0){
        return 1;
    }

    if(i==n || amount<0){
        return  0;
    }

 
    if(dp[i][amount]!=-1){
        return  dp[i][amount];
     } 

    int incl=solve(i,amount-coins[i],coins);
    int excl=solve(i+1,amount,coins);

    return dp[i][amount]=incl+excl;

      

   }
    int change(int amount, vector<int>& coins) {
        
        n=coins.size();
        dp = vector<vector<int>>(n, vector<int>(amount + 1, -1));
        int ans=solve(0,amount,coins);

        return ans;
        
    }
};