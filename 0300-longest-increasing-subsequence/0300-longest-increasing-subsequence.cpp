class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi=1,lastIndex=0;
        vector<int> dp(n,1),hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]>nums[prev] && dp[i]<dp[prev]+1){
                    dp[i]=dp[prev]+1;
                    hash[i]=prev;
                }
            
            }
            if(dp[i]>maxi){
                 maxi=dp[i];
                 lastIndex=i;
             }

        }
        return maxi;
        
    }
};