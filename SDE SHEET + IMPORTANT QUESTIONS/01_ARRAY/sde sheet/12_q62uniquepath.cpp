class Solution {
    public:
        int solve(int i, int j, int m, int n){
            if(i > n || j > m){
                return 0;
            }
    
            if(i == n - 1 && j == m - 1){
                return 1;
            }
    
            int ans = solve(i + 1, j, m, n) + solve(i, j + 1, m, n);
    
            return ans;
        }
    
        int solvemem(int i, int j, int m, int n, vector<vector<int>>&dp){
             if(i >= m || j >= n){
                return 0;
            }
    
            if(i == m - 1 && j == n - 1){
                return 1;
            }
    
            if(dp[i][j] != -1){
                return dp[i][j];
            }
    
            dp[i][j] = solvemem(i + 1, j, m, n, dp) + solvemem(i, j + 1, m, n, dp);
    
            return dp[i][j];
        }
    
        int solveusingcombinatorics(int m, int n){
            int N = n + m - 2;
            int r = min(m-1, n - 1);
            double res = 1;
    
            for(int i = 1; i <= r; i++){
                res = res * (N - r + i) / i;
            }
    
            return (int)res;
        }
    
        int uniquePaths(int m, int n) {
            //return solve(0, 0, m, n);
            // vector<vector<int>>dp(m, vector<int>( n , -1));
            // return solvemem(0, 0, m, n, dp);
            return solveusingcombinatorics(m, n);
        }
    };