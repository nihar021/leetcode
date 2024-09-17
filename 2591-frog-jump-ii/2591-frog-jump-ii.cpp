class Solution {
    bool IsPossible (int dist, const vector<int>& stones) {
        int n = stones.size();
        vector<bool> visited(n, false);
        
        int ind = 0;
        // Forward Journey
        while (ind < n-1) {
            int j = ind;
            while (j+1 < n && stones[j+1] <= (stones[ind] + dist)) j ++;
            
            if (j == ind) return false;
            ind = j;
            visited[ind] = true;
        }
        
        // Remove visited indexes to avoid increasing the time complexity :)
        vector<int> indexes;
        for (int j = 0; j < n-1; j ++) {
            if (visited[j] == false) indexes.push_back(j);
        }
        indexes.push_back(n-1);
                
        ind = indexes.size() - 1;
        // Backward Journey
        while (ind > 0) {
            int j = ind;
            while (j > 0 && stones[indexes[j-1]] >= (stones[indexes[ind]] - dist)) j--; 
            
            if (j == ind) return false;
            ind = j;
        }
        
        return true;
    }
    
public:
    int maxJump(vector<int>& stones) {
        //Binary Search
        int l = 0;
        int r = *max_element(stones.begin(), stones.end());;
        
        while (l < r) {
            int m = (l+r) >> 1;
            
            if (IsPossible(m, stones)) r = m;
            else l = m+1;
        }
        
        return l;
    }
};