class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9)); // or use a large number instead of INT_MAX

        // Adjacency Matrix 
        for (auto it : edges) {    
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        } 
        
        // Floyd-Warshall
        for (int i = 0; i < n; i++) dist[i][i] = 0;

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != 1e9 && dist[k][j] != 1e9) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int minCity = n;
        int cityno = -1;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            if (cnt <= minCity ) {
                minCity = cnt;
                cityno = i;
            }
        }
        
        return cityno;
    }
};
