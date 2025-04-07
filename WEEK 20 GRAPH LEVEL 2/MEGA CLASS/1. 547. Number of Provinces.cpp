class Solution

{
public:
    void dfs(int curr, vector<vector<int>> &isConnected, vector<bool> &visited)
    {
        visited[curr] = true;
        // check all cities that are connected to the curr city
        for (int j = 0; j < isConnected.size(); j++)
        {
            if (isConnected[curr][j] && !visited[j])
                dfs(j, isConnected, visited);
        }
    }

    void bfs(int node, vector<vector<int>> &isConnected, vector<bool> &visited)
    {
        queue<int> q;
        q.push(node);
        visited[node] = true;
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            // check all cities that are connected to the curr city
            for (int j = 0; j < isConnected.size(); j++)
            {
                if (isConnected[curr][j] && !visited[j])
                {
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        // need to traverse, and number of traversals will be my answer
        vector<bool> visited(isConnected.size(), false);
        int provinces = 0;

        for (int i = 0; i < isConnected.size(); i++)
        {
            if (!visited[i])
            {
                dfs(i, isConnected, visited);
                provinces++;
            }
        }
        return provinces;
    }
};

//2nd

class Solution {
    private:
        void dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
            vis[node] = 1;
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    dfs(it, adj, vis);
                }
            }
        }
    
    public:
        int findCircleNum(vector<vector<int>>& isConnected) {
            int V = isConnected.size();
            vector<vector<int>> adj(V);
    
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (isConnected[i][j] == 1 && i != j) {
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }
    
            vector<int> vis(V, 0);
            int cnt = 0;
            for (int i = 0; i < V; i++) {
                if (!vis[i]) {
                    cnt++;
                    dfs(i, adj, vis);
                }
            }
            return cnt;
        }
    };
    