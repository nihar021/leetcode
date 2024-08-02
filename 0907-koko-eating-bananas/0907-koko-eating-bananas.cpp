class Solution {
public:
     bool canFinish(const vector<int>& piles, int k, int h) {
        int hours = 0;
        for (int pile : piles) {
            hours += ceil(static_cast<double>(pile) / k); // Calculate hours needed for each pile
        }
        return hours <= h; // Check if total hours is within the allowed time
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canFinish(piles, mid, h)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};