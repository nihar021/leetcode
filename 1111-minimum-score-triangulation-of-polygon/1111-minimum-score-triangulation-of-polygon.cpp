class Solution {
public:
    int solveMem(vector<int>& v,int i,int j,vector<vector<int>> &dp){
        if(i+1==j){
            return 0;
        }
        int ans=INT_MAX;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        for(int k=i+1;k<j;k++){
            ans=min(ans,v[i]*v[j]*v[k]+solveMem(v,i,k,dp)+solveMem(v,k,j,dp));
        }
        dp[i][j]=ans;
        return ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ans=solveMem(values,0,n-1,dp);
        return ans;
        
    }
};