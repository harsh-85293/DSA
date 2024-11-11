class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        // Sort cars by position in descending order
        sort(cars.rbegin(), cars.rend());

        vector<double> time;
        for (int i = 0; i < cars.size(); i++) {
            double temp = (double)(target - cars[i].first) / cars[i].second;
            time.push_back(temp);
        }

        int fleets = 0;
        double lastTime = 0;

        for (double t : time) {
            if (t > lastTime) {
                fleets++;
                lastTime = t;
            }
        }

        return fleets;
    }
};
