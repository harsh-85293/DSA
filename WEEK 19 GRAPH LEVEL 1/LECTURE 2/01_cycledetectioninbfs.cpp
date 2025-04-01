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

            bool cycledetectionbfs(int src, unordered_map<int, bool>&visited){
                queue<int>q;
                unordered_map<int, int>parent;
                
                
                //initial state
                q.push(src);
                visited[src] = true;
                parent[src]  = -1;

                //main logic
                while(!q.empty()){
                    int frontnode = q.front();
                    q.pop();

                    for(auto nbr : adjList[frontnode]){
                        if(!visited[nbr]){
                            q.push(nbr);
                            visited[nbr] = true;
                            parent[nbr] = frontnode;
                        }

                        //cycle detection case
                        else if(visited[nbr] == true && nbr != parent[frontnode]){
                            //cycle present return true
                            return true;
                        }
                    }
                }
                return false;
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