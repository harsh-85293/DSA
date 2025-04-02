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

        bool checkCycleDfsHelper(int src, unordered_map<int,bool>& vis, vector<int> adj[], int parent) {
            vis[src] = true;
            
            for(auto nbr: adj[src]) {
                if(!vis[nbr]) {
                    bool ans = checkCycleDfsHelper(nbr, vis, adj, src);
                    if(ans == true) {
                        return true;
                    }
                }
                else if(vis[nbr] == true && nbr != parent) {
                    return true;
                }
            }
            return false;
        }
        bool isCycle(int V, vector<int> adj[]) {
            //handle disconnected components 
            int n = V;
            bool ans = false;
            unordered_map<int,bool> visited;
            int parent = -1;
            for(int i=0; i<V; i++) {
                if(!visited[i]) {
                    ans = checkCycleDfsHelper(i,visited,adj, parent);
                    if(ans) {
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
