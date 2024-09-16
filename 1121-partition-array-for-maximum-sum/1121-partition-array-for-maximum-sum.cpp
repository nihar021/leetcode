class Solution {
public:
    // int solve(int ind,vector<int>& arr, int k){
    //     int n=arr.size();
    //     if(ind==n)return 0;
    //     int maxAns,sum=0,maxi=INT_MIN;
    //     int len=0;
    //     for(int i=ind;i<min(n,ind+k);i++){
    //         len++;
    //         maxi=max(maxi,arr[i]);
    //         sum=len*maxi+solve(i+1,arr,k);
    //         maxAns=max(maxAns,sum);
    //     }
    //     return maxAns;
    // }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // return solve(0,arr,k);
      int n = arr.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 0; // Base case: if index is at the end of the array, max sum is 0

        // Fill dp array from the back to the front
        for (int ind = n - 1; ind >= 0; ind--) {
            int maxAns = 0, sum = 0, maxi = INT_MIN;
            int len = 0;
            for (int i = ind; i < min(n, ind + k); i++) {
                len++;
                maxi = max(maxi, arr[i]);  // Track the maximum in the partition
                sum = len * maxi + dp[i + 1]; // Calculate the sum for this partition
                maxAns = max(maxAns, sum);  // Track the maximum answer
            }
            dp[ind] = maxAns; // Store the maximum sum in dp array at index 'ind'
        }
        
        return dp[0]; // Return the maximum sum possible starting from index 0
    }
};