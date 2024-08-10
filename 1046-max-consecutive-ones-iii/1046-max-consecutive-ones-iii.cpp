class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();  // Get the size of the input array
        int l = 0, r = 0;     // Initialize left and right pointers
        int maxlen = 0;       // Variable to store the maximum length of the subarray
        int zeros = 0;        // Counter to keep track of the number of zeros in the current window

        // Iterate through the array with the right pointer
        while (r < n) {
            // If the current element is zero, increment the zeros counter
            if (nums[r] == 0) zeros++;

            // If the number of zeros exceeds k, shrink the window from the left
            while (zeros > k) {
                // If the leftmost element in the window is zero, decrement the zeros counter
                if (nums[l] == 0) zeros--;
                l++; // Move the left pointer to the right
            }

            // Calculate the current window length and update the maximum length
            int len = r - l + 1;
            maxlen = max(len, maxlen);

            // Move the right pointer to expand the window
            r++;
        }

        // Return the maximum length of the subarray found
        return maxlen;
    }
};
