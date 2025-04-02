#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
        //adjacency list graph declaration
        unordered_map<int, list<int>> adjList;

        void addEdge(int u, int v, bool direction){
            //direction = 0 -> undirected graph
            //direction = 1 -> directed graph
            if(direction == 0){
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
            else{
                //directed edge
                adjList[u].push_back(v);
            }
        }   

        void printadjlist(int n){
            for(int i = 0; i < n; i++){
                cout << i << ": ";
                cout << "{ ";  
                list<int> temp = adjList[i];
                for(auto j : temp){
                    cout << j << ", ";
                }
                cout << "}" << endl;
            }
        }

        bool dfsHelper(int node, unordered_map<int,bool>& vis, vector<int> adj[],
            unordered_map<int,bool>& dfsTracker) {
                
                vis[node] = true;
                dfsTracker[node] = true;
                
                for(auto nbr: adj[node]) {
                    if(!vis[nbr]) {
                        bool ans = dfsHelper(nbr, vis, adj, dfsTracker);
                        if(ans == true) {
                            return true;
                        }
                    }
                    else if(vis[nbr] == true && dfsTracker[nbr] == true) {
                        //cycle present
                        return true;
                    }
                }
                
                //backtrack
                dfsTracker[node] = false;
                return false;
            }
            bool isCyclic(int V, vector<int> adj[]) {
                bool ans = false;
                int n = V;
                unordered_map<int,bool> vis;
                unordered_map<int,bool> dfsTracker;
                
                for(int i=0; i<n; i++) {
                    if(!vis[i]) {
                        ans = dfsHelper(i,vis,adj, dfsTracker);
                        if(ans == true) {
                            break;
                        }
                    }
                }
                return ans;
            }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    //g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 0);
    g.printadjlist(4);

    bool ans = false;
    int n = 4;
    unordered_map<int, bool>visited;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            ans = g.cycledetectionbfs(i, visited);
            if(ans == true){
                break;
            }
        }
    }

    if(ans == true){
        cout << "cycle present";
    }
    else{
        cout << "cycle not present";
    }
    return 0;
}