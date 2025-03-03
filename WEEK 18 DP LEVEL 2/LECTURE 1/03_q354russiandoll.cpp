//same
class Solution {
    public:
        
        bool issafe(vector<int>e1, vector<int>e2){
            if(e1[0] < e2[0] && e1[1] < e2[1]){
                return true;
            }
            return false;
        }
    
        int solveusingso2(vector<vector<int>> &cuboids, int curr, int prev){
            int n = cuboids.size();
    
            vector<int>currrow(n + 1, 0);
            for(int curr = n - 1; curr >= 0; curr--){
                for(int prev = - 1; prev <= curr - 1; prev++){
                    int incl = 0;
                    if( prev == -1 || issafe( cuboids[prev], cuboids[curr] ) ){
                        incl = 1 + currrow[curr + 1];
                    }
                    int excl = 0 + currrow[prev + 1];
    
                    currrow[prev + 1] = max(incl, excl);
                }
            }
            return currrow[0];
        }
        int maxEnvelopes(vector<vector<int>>& cuboids) {
            int curr = 0;
            int prev = -1;
            sort(cuboids.begin(), cuboids.end());
            return solveusingso2(cuboids, curr, prev);
        }
        
    };