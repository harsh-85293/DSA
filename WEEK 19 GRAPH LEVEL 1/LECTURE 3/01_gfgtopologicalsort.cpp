class Solution {
    public:
        void topoDfs(int src, unordered_map<int, bool> &visited, vector<vector<int>>& edges, vector<int>& ans) {
            visited[src] = true;
            for (auto nbr : edges[src]) {
                if (!visited[nbr]) {
                    topoDfs(nbr, visited, edges, ans);
                }
            }
            ans.push_back(src);
        }
        
        vector<int> topoSort(int V, vector<vector<int>>& edges_input) {
            // Build adjacency list from edge list
            vector<vector<int>> adj(V);  // Adjacency list for V vertices
            for (auto edge : edges_input) {
                int u = edge[0];  // Source node
                int v = edge[1];  // Destination node
                adj[u].push_back(v);  // Directed edge u -> v
            }
            
            unordered_map<int, bool> visited;
            vector<int> ans;
            
            for (int i = 0; i < V; i++) {
                if (!visited[i]) {
                    topoDfs(i, visited, adj, ans);
                }
            }
            
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };