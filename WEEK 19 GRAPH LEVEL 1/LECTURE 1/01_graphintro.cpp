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
    };

    int main()
    {
        Graph g;
        g.addEdge(0, 1, 1);
        g.addEdge(0, 2, 1);
        g.addEdge(1, 2, 1);
        g.addEdge(2, 3, 1);
        g.printadjlist(4);
        return 0;
    }