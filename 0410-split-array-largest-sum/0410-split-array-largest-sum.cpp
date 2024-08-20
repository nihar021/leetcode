class Solution {
public:
    int func(vector<int>& arr, int mid, int n) {
        int noPage = 0, cnt = 1; // Start cnt at 1, since one student is needed at least.
        for (int i = 0; i < n; i++) {
            if (arr[i] + noPage <= mid) {
                noPage += arr[i];
            } else {
                cnt++;
                noPage = arr[i];
            }
        }
        return cnt;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int mid = 0;
        
        while (low <= high) {
            mid = low + (high - low) / 2;
            int cnt = func(nums, mid, n);
            if (cnt <= k)
                high = mid - 1;  // Narrow down the upper limit
            else
                low = mid + 1;   // Increase the lower limit
        }
        
        return low;
    }
};
