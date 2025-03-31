#include <bits/stdc++.h>
using namespace std;

    class Graph{
    public:
        // adjacency list graph declaration
        unordered_map<int, list<pair<int, int>>> adjList;

        void addEdge(int u, int v, int weight, bool direction)
        {
            // direction = 0 -> undirected graph
            // direction = 1 -> directed graph
            if (direction == 0)
            {
                adjList[u].push_back({v, weight});
                adjList[v].push_back({u, weight});
            }
            else
            {
                // directed edge
                adjList[u].push_back({v, weight});
            }
        }

        void printadjlist(int n)
        {
            for (int i = 0; i < n; i++)
            {
                cout << i << ": ";
                cout << "{ ";
                list<pair<int, int>> temp = adjList[i];
                for (auto j : temp)
                {
                    cout << "(" << j.first << "," << j.second << "), ";
                }
                cout << "}" << endl;
            }
        }

        void dfsHelper(int src, unordered_map<int, bool> &visited)
        {
            visited[src] = true;
            cout << src << ", ";

            for (auto nbr : adjList[src])
            {
                // nbr -> pair
                // first-> node
                // second -> weight
                int node = nbr.first;
                if (!visited[node])
                {
                    dfsHelper(node, visited);
                }
            }
        }

        void dfsTraversal(int n)
        {
            unordered_map<int, bool> visited;

            for (int src = 0; src < n; src++)
            {
                if (!visited[src])
                    dfsHelper(src, visited);
            }
        }
};

int main()
{
    Graph g;
    g.addEdge(0, 3, 3, 1);
    g.addEdge(0, 5, 3, 1);
    g.addEdge(0, 2, 3, 1);
    g.addEdge(2, 5, 3, 1);
    g.addEdge(3, 5, 3, 1);
    g.addEdge(5, 4, 3, 1);
    g.addEdge(5, 6, 3, 1);
    g.addEdge(4, 1, 3, 1);
    g.addEdge(6, 1, 3, 1);
    int n = 7;
    g.printadjlist(n);
    cout << endl << "DFS: " ;
    g.dfsTraversal(7);
    return 0;
}