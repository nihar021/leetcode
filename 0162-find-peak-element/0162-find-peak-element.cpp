//Peak=> nums[i-1] < nums[i] > nums[i+1]
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       int n=nums.size(); 
    
       if(n==1) return 0;
       if(nums[0]>nums[1]) return 0;
       if(nums[n-1]>nums[n-2]) return n-1;
    
       int low=1,high=n-2;
       while(low<=high){
          int mid=(low+high)/2;
          int left=mid-1;
          int right=mid+1;
          if(nums[mid]>nums[left] && nums[mid]>nums[right]){
            return mid;
          }else if(nums[mid]>nums[left]){
            low=mid+1;
          }else if(nums[mid]>nums[right]){
            high=mid-1;
          }
          //nums[left]>nums[mid]<nums[right]
          else{
            low=mid+1;
          }
       }
       return -1;
    
    }
};

 