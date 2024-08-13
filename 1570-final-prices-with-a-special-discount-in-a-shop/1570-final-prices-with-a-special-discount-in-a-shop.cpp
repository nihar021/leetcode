#include <vector>
#include <stack>

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        int n = prices.size();
        vector<int> ans(n);  // Initialize the vector to the size of `prices`
        int red;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() > prices[i]) {
                st.pop();
            }
            red = st.empty() ? 0 : st.top();
            ans[i] = prices[i] - red;
            st.push(prices[i]);
        }

        return ans;
    }
};
