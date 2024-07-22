#include <vector>
#include <queue>


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Create a min-heap with std::greater<int> as the comparator
        priority_queue<int,vector<int>, greater<int>> pq;

        // Iterate through the elements of the nums vector
        for (int num : nums) {
            pq.push(num); // Push each element into the heap

            // If the heap size exceeds k, pop the smallest element
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // The top element of the min-heap is the k-th largest element
        return pq.top();
    }
};
