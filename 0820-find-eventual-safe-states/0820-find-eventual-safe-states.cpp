class Solution {
  private:
   bool dfs(int node, vector<int> &visited, vector<int> &pathVis, vector<int> &Check, vector<vector<int>> &graph) {
       visited[node] = 1;
       pathVis[node] = 1;
       
       // Traverse adjacent nodes
       for (auto it : graph[node]) {
           if (!visited[it]) {
               if (dfs(it, visited, pathVis, Check, graph) == true) {
                   return true;  // Cycle found
               }
           } else if (pathVis[it]) {
               return true;  // Cycle found
           }
       }
       
       Check[node] = 1;  // Mark as safe after processing all neighbors
       pathVis[node] = 0;  // Remove the node from the current path
       return false;  // No cycle found
   }

  public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        int V = graph.size();
        vector<int> visited(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> Check(V, 0);  // Initialize Check with size V and all elements as 0
        vector<int> ans;
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, pathVis, Check, graph);
            }
        }
        
        for (int i = 0; i < V; i++) {
            if (Check[i] == 1) {
                ans.push_back(i);  // Push the node index if it is safe
            }
        }
        
        return ans;
    }
};
