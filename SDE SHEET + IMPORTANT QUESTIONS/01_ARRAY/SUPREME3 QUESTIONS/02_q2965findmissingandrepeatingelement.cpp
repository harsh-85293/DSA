class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            unordered_map<int, int>mp;
            vector<int>v;
            for(int i = 0; i < grid.size(); i++){
                for(int j = 0; j < grid[0].size(); j++){
                    mp[grid[i][j]]++;
                    v.push_back(grid[i][j]);
                }
            }
            int rep;
            for(auto it:mp){
                if(it.second > 1){
                    rep = it.first;
                }
            }
    
            int sum = 0;
            set<int>st(v.begin(), v.end());
            int n = 1;
            for(int it:st){
                n++;
                sum += it;
            }
            int orsum = n*(n+1)/2;
            int  mis = orsum- sum;
    
            cout << orsum << " " << sum;
            return {rep, mis};
        }
    };