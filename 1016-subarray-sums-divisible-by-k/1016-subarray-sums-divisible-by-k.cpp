class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;  // To count subarrays that are initially divisible by k.
        int sum = 0, cnt = 0;
        
        for (int num : nums) {
            sum += num;
            int rem = sum % k;
            
            // Ensure the remainder is positive
            if (rem < 0) {
                rem += k;
            }
            
            cnt += mp[rem];
            mp[rem]++;
        }
        
        return cnt;
    }
};

