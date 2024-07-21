#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int nextGreaterElement(int n) {
        // Convert the number to a vector of digits
        std::vector<int> digits;
        int original = n;
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        
        // Since we have reversed digits, reverse them back
        std::reverse(digits.begin(), digits.end());

        // Find the first digit that is smaller than the digit to its right
        int i = digits.size() - 2;
        while (i >= 0 && digits[i] >= digits[i + 1]) {
            i--;
        }
        
        // If no such digit is found, return -1
        if (i == -1) {
            return -1;
        }
        
        // Find the smallest digit on right side of (i) which is larger than digits[i]
        int j = digits.size() - 1;
        while (digits[j] <= digits[i]) {
            j--;
        }
        
        // Swap the digits
        std::swap(digits[i], digits[j]);
        
        // Sort the digits after position i to get the smallest possible number
        std::sort(digits.begin() + i + 1, digits.end());
        
        // Convert the digits back to a number
        long long result = 0;
        for (int digit : digits) {
            result = result * 10 + digit;
            // Check if the number exceeds 32-bit integer range
            if (result > INT_MAX) {
                return -1;
            }
        }
        
        // Check if the result is greater than the original number
        return result > original ? result : -1;
    }
};
