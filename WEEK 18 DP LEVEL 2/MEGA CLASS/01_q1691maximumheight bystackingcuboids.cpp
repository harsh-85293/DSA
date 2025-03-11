class Solution {
    public:
        bool issafe(vector<int>c1, vector<int> c2){
            if(c1[0] <= c2[0] && c1[1] <= c2[1] && c1[2] <= c2[2]){
                return true;
            }
            return false;
        }
    
        int solveusingrec(vector<vector<int>> &cuboids, int curr, int prev){
            // Base case
            if (curr >= cuboids.size()) {
                return 0;
            }
    
            //include exclude pattern
            int incl = 0;
            if( prev == -1 || issafe( cuboids[prev], cuboids[curr] ) ){
                incl = cuboids[curr][2] + solveusingrec(cuboids, curr + 1, curr);
            }
            int excl = 0 + solveusingrec(cuboids, curr + 1, prev);
    
            int finalans = max(incl, excl);
            return finalans;
        }
    
        int solveusingmemo(vector<vector<int>> &cuboids, int curr, int prev,  vector<vector<int>>&dp){
             // Base case
            if (curr >= cuboids.size()) {
                return 0;
            }
    
            if(dp[curr][prev + 1] != -1){
                return dp[curr][prev + 1];
            }
    
            //include exclude pattern
            int incl = 0;
            if( prev == -1 || issafe( cuboids[prev], cuboids[curr] ) ){
                incl = cuboids[curr][2] + solveusingmemo(cuboids, curr + 1, curr, dp);
            }
            int excl = 0 + solveusingmemo(cuboids, curr + 1, prev, dp);
    
            dp[curr][prev + 1] = max(incl, excl);
            return dp[curr][prev + 1];
        }
    
        int solveusingtab(vector<vector<int>> &cuboids, int curr, int prev){
            int n = cuboids.size();
            vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));
    
            for(int curr = n - 1; curr >= 0; curr--){
                for(int prev = curr - 1; prev >= -1; prev--){
                    int incl = 0;
                    if( prev == -1 || issafe( cuboids[prev], cuboids[curr] ) ){
                        incl = cuboids[curr][2] + dp[curr + 1][curr + 1];
                    }
                    int excl = 0 + dp[curr + 1][prev + 1];
    
                    dp[curr][prev + 1] = max(incl, excl);
                }
            }
            return dp[0][0];
        }
    
        int solveusingso(vector<vector<int>> &cuboids, int curr, int prev){
            int n = cuboids.size();
            //vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));
            vector<int>prevrow(n + 1, 0);        
            vector<int>currrow(n + 1, 0);
            for(int curr = n - 1; curr >= 0; curr--){
                for(int prev = curr - 1; prev >= -1; prev--){
                    int incl = 0;
                    if( prev == -1 || issafe( cuboids[prev], cuboids[curr] ) ){
                        incl = cuboids[curr][2] + prevrow[curr + 1];
                    }
                    int excl = 0 + prevrow[prev + 1];
    
                    currrow[prev + 1] = max(incl, excl);
                }
                //shifting
                prevrow = currrow;
            }
            return prevrow[0];
        }
    
        int solveusingso2(vector<vector<int>> &cuboids, int curr, int prev){
            int n = cuboids.size();
            //vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));
            // vector<int>prevrow(n + 1, 0);        
            vector<int>currrow(n + 1, 0);
            for(int curr = n - 1; curr >= 0; curr--){
                for(int prev = - 1; prev <= curr - 1; prev++){
                    int incl = 0;
                    if( prev == -1 || issafe( cuboids[prev], cuboids[curr] ) ){
                        incl = cuboids[curr][2] + currrow[curr + 1];
                    }
                    int excl = 0 + currrow[prev + 1];
    
                    currrow[prev + 1] = max(incl, excl);
                }
                //shifting
                // prevrow = currrow;
            }
            return currrow[0];
        }
        
        int maxHeight(vector<vector<int>>& cuboids) {
            //sorting individual cuboids so that we can have longest cuboid at last
            for(auto &cuboid : cuboids){
                sort(cuboid.begin(), cuboid.end());
            }
            int curr = 0;
            int prev = -1;
            int n = cuboids.size();
            //sorting all cuboids
            sort(cuboids.begin(), cuboids.end());
    
            // return solveusingrec(cuboids, curr, prev);
            
            // vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
            // return solveusingmemo(cuboids, curr, prev, dp);
    
            //return solveusingtab(cuboids, curr, prev);
    
            //return solveusingso(cuboids, curr, prev);
    
            return solveusingso2(cuboids, curr, prev);
        }
    };