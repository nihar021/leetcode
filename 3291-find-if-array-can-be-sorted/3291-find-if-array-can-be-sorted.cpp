class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n - i - 1; j++) { //in every pass, the max element bubbles up to right most index
                if(nums[j] <= nums[j+1]) { //no swap required
                    continue;
                } else { //pakka nums[j] > nums[j+1]
                    //swap is required
                    if(__builtin_popcount(nums[j]) == __builtin_popcount(nums[j+1])) {
                        swap(nums[j], nums[j+1]);
                    } else {
                        //not able to swap, hence can't sort it
                        return false;
                    }
                }
            }
        }

        return true;
    }
};