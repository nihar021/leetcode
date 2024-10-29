#include <string>
#include <algorithm>  // for max()
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0, close = 0, maxlen = 0;

        // Left-to-right traversal
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                open++;
            else
                close++;

            if (open == close)
                maxlen = max(maxlen, 2 * open);
            else if (close > open) {
                open = 0;
                close = 0;
            }
        }

        // Reset open and close counters for right-to-left traversal
        open = close = 0;

        // Right-to-left traversal
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(')
                open++;
            else
                close++;

            if (open == close)
                maxlen = max(maxlen, 2 * open);
            else if (open > close) {
                open = 0;
                close = 0;
            }
        }

        return maxlen;
    }
};
