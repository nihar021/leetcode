class Solution {
public:
    int solve(vector<int>& nums, int goal){

        int l=0,r=0,cnt=0;
        unordered_map<int , int> mpp;

        while(r<nums.size()){

           mpp[nums[r]]++;
          
           while(mpp.size() > goal){
              mpp[nums[l]]--;
              if(mpp[nums[l]]==0){
                mpp.erase(nums[l]);
              }
              l++;
           }
           cnt+=(r-l+1);
           r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (solve(nums,k)-solve(nums,k-1));
    }
};