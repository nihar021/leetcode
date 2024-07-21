#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.empty() || nums1.empty())
            return {};
        
        unordered_map<int, int> mp;
        stack<int> st;
        
        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {
            // Maintain the decreasing stack
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            // If stack is empty, then there is no greater element on the right
            mp[nums2[i]] = st.empty() ? -1 : st.top();
            // Push current element to stack
            st.push(nums2[i]);
        }
        
        // Prepare the result for nums1
        vector<int> result;
        for (int num : nums1) {
            result.push_back(mp[num]);
        }
        
        return result;
    }
};
