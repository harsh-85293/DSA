class Solution {
    public:
        int solveusingrec(int s, int e){
            //base case
            if(s >= e){
                return 0;
            }
    
            //1 case hum solve karenge
            int ans = INT_MAX;
            for(int i = s; i < e;i++){
                ans = min(ans, i + max( solveusingrec(s, i - 1), solveusingrec(i + 1, e) ));
            }
            return ans;
        }
        int solveusingmem(int s, int e, vector<vector<int>>&dp){
            //base case
            if(s >= e){
                return 0;
            }   
    
            if(dp[s][e] != -1){
                return dp[s][e];
            }
    
            //1 case hum solve karenge
            int ans = INT_MAX;
            for(int i = s; i < e;i++){
                ans = min(ans, i + max( solveusingmem(s, i - 1, dp), solveusingmem(i + 1, e, dp) ));
            }
            dp[s][e] = ans;
            return ans;
        }
    
        int solveusingtab(int n){
            vector<vector<int>>dp(n + 2, vector<int>(n + 2, 0));
    
            for(int s = n; s >= 1; s--){
                for(int e = 1; e <= n; e++){
                    if(s >= e){
                        continue;
                    }
                    else{
                        int ans = INT_MAX;
                        for(int i = s; i < e; i++){
                            ans = min(ans, i + max(dp[s][i - 1], dp[i + 1][e]));
                        }
                        dp[s][e] = ans;
                    }
                }
            }
            return dp[1][n];
        }
    
        
        int getMoneyAmount(int n) {
            // return solveusingrec(1, n);
            // vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
            // return solveusingmem(1, n, dp);
            return solveusingtab(n);
        }
    };