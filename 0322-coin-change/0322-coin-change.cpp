class Solution {
public:
    int solvemem(vector<int>& coins, int t,vector<int> &dp){
       
        if(t==0){
            return 0;
        }

        if(t<0){
            return INT_MAX;
        }

        if(dp[t]!=-1){
            return dp[t];
        }
        
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){

                int ans=solvemem(coins,t-coins[i],dp);
            
                if(ans!=INT_MAX){
                   mini=min(mini,1+ans);
                }   
        }
        dp[t]=mini;
        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount+1,-1);        
        int ans=solvemem(coins,amount,dp);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
        
    }
};