class Solution {
public:
    int lowerBound(vector<int> &arr, int n, int x) {
        int low = 0, high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int max_cnt = 0;
        int index = 0;
        for (int i = 0; i < n; i++) {
            sort(mat[i].begin(),mat[i].end());
            int cnt_one = m - lowerBound(mat[i], m, 1);
            if (cnt_one > max_cnt) {
                max_cnt = cnt_one;
                index = i;
            }
        }
        return {index, max_cnt};
    }
};
