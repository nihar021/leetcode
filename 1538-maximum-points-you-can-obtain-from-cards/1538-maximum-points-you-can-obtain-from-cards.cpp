#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int lsum = 0, rsum = 0, maxsum = 0;

        // Sum the first k cards (left sum)
        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }
        maxsum = lsum;

        int rindex = n - 1;

        // Adjust the sum by removing cards from the left and adding cards from the right
        for (int i = k - 1; i >= 0; i--) { // Fix here: change k-- to i--
            lsum -= cardPoints[i];
            rsum += cardPoints[rindex];
            rindex--;
            maxsum = max(maxsum, lsum + rsum);
        }

        return maxsum;
    }
};
