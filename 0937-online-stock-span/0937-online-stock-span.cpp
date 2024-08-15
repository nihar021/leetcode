class StockSpanner {
public:
    stack<pair<int, int>> st;
    int index = -1;

    StockSpanner() {
        // Reinitialize for every new market start
        index = -1;
        while (!st.empty()) st.pop();  // Clearing the stack
    }
    
    int next(int price) {
        index++;  // Increment the index for each call to next()

        // Maintain decreasing order in stack from top to bottom
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }

        // Calculate the span
        int ans = index - (st.empty() ? -1 : st.top().second);

        // Push the current price and index onto the stack//prev greater elemnt
        st.push({price, index});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
