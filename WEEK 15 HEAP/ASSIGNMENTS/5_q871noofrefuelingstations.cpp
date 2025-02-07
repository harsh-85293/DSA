class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int dist = 0;
        int stops = 0;
        int i = 0;
        int fuel = startFuel;
        priority_queue<int> pq; // Max heap for fuel

        while (dist < target) {
            // Add reachable fuel stations to the priority queue
            while (i < stations.size() && stations[i][0] <= dist + fuel) {
                pq.push(stations[i][1]);  // Push only fuel amount
                i++;
            }

            // Move forward as much as possible
            dist += fuel;
            fuel = 0;

            // If reached target, return stops
            if (dist >= target) return stops;

            // If no reachable fuel station, return -1
            if (pq.empty()) return -1;

            // Refuel with the largest available fuel
            fuel = pq.top();
            pq.pop();
            stops++;
        }
        return stops;
    }
};

