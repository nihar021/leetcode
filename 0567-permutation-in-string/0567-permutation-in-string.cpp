class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 > n2) return false;
        
        int hash1[26] = {0};
        int hash2[26] = {0};

        // Initialize the frequency arrays for the first window
        for (int i = 0; i < n1; i++) {
            hash1[s1[i] - 'a'] += 1;
            hash2[s2[i] - 'a'] += 1;
        }

        // Sliding Window
        int left = 0;
        for (int right = n1; right < n2; right++) {
            if (equal(begin(hash1), end(hash1), begin(hash2))) return true;

            // Slide the window to the right
            hash2[s2[right] - 'a'] += 1; // include new character
            hash2[s2[left] - 'a'] -= 1;  // exclude old character
            left++;
        }
        
        // Check the last window
        return equal(begin(hash1), end(hash1), begin(hash2));
    }
};
