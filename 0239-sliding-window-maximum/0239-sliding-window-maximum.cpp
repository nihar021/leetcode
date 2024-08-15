class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;  // To store the results
        deque<int> dq;  // Deque to store indices

        for (int i = 0; i < n; i++) {
            // Maintain window size
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();  // Remove indices that are out of the current window
            }

            // Maintain the deque in decreasing order
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // Add the current element index to the deque
            dq.push_back(i);

            // Start adding the max value to the result from the index where we have at least k elements
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};
