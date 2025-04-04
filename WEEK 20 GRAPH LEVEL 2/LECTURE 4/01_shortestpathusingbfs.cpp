    #include <bits/stdc++.h>
    using namespace std;

    class Graph{
        public:
            unordered_map<int, list<int>>adj;

            void addEdge(int u, int v, bool direction){
                // direction -> 0 => undirected edge
                // direction -> 1 => directed edge
                
                if(direction == 0){
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }   
                else{
                    adj[u].push_back(v);
                }
            }

            void printadjlist(int n){
                for(int i = 0; i < n; i++){
                    cout << i << ": {";
                    for(auto j : adj[i]){
                        cout << j << ", ";
                    }
                    cout << "}" << endl;
                }
            }
            void shortestpathbfs(int &src, int &dest){
                unordered_map<int, bool>visited;
                unordered_map<int, int>parent;
                queue<int>q;

                //initial state
                q.push(src);
                visited[src] = true;
                parent[src] = -1;

                //main logic
                while(!q.empty()){
                    int frontnode = q.front();
                    q.pop();

                    for(auto nbr:adj[frontnode]){
                        if(!visited[nbr]){
                            q.push(nbr);
                            visited[nbr] = true;
                            parent[nbr] = frontnode;

                        }    
                    }
                }
                // parent array ready
                vector<int>path;
                int node = dest;

                while(node != -1){
                    path.push_back(node);
                    node = parent[node];
                }

                //reverse path
                reverse(path.begin(), path.end());

                //print path
                cout << "printing path: ";
                for(auto it:path){
                    cout << it << "->";
                }cout << endl;
            }
    };
 
    int main()
    {
        Graph g;
        g.addEdge(0, 1, 0);
        g.addEdge(1, 2, 0);
        g.addEdge(2, 3, 0);
        g.addEdge(2, 4, 0);
        g.addEdge(4, 5, 0);
        g.addEdge(5, 3, 0);

        int src = 0;
        int dest = 3;
        g.shortestpathbfs(src, dest);
        return 0;
    }