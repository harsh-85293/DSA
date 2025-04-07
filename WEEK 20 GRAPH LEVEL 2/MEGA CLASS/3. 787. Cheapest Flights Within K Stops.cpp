class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // let's build Adj list
        unordered_map<int, list<pair<int, int>>> graph;
        for (auto &flight : flights)
            graph[flight[0]].push_back({flight[1], flight[2]});

        // Priority Queue to select the next city with minimal cost
        // each element would be: {cost so far, current city, stops so far}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});

        // visited array storing minimum number of stops to reach a city
        vector<int> visited(n, INT_MAX);
        visited[src] = 0;

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int cost = curr[0];  // total cost so far
            int city = curr[1];  // current city
            int stops = curr[2]; // number of stops made so far

            if (city == dst)
                return cost;

            // if stops exceeds k, then skip this path
            if (stops > k)
                continue;

            // if we have already visited the city with fewer stops, skip this path
            if (visited[city] != INT_MAX && visited[city] < stops)
                continue;

            // update the mini stops for the current city
            visited[city] = min(visited[city], stops);

            // Explore all neighbours cities
            for (auto &nbr : graph[city])
            {
                int nextCity = nbr.first;
                int price = nbr.second;
                pq.push({cost + price, nextCity, stops + 1});
            }
        }
        return -1;
    }
};

//2 
class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            vector<vector<pair<int, int>>> adj(n);
            for(auto it : flights){
                adj[it[0]].push_back({it[1], it[2]});
            }
    
            queue<pair<int, pair<int, int>>>q;
            q.push({0,{src, 0}});
            vector<int>dist(n, 1e9);
            dist[src] = 0;
    
            while(!q.empty()){
                auto it = q.front();
                q.pop();
                int stops = it.first;
                int node = it.second.first;
                int cost = it.second.second;
    
                if(stops > k) {
                    continue;
                }
    
                for(auto i : adj[node]){
                    int adjNode = i.first;
                    int edw = i.second;
    
                    if(cost + edw < dist[adjNode] && stops <= k){
                        dist[adjNode] = cost + edw;
                        q.push({stops + 1, {adjNode, cost + edw}});
                    }
                }
            }
    
            if(dist[dst] == 1e9) return -1;
            return dist[dst];
    
        }
    };