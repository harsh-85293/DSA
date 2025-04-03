class Solution {
    public:
        int solve(string &s, string &t, int i, int j){
            if(j == t.size()){
                return 1;
            }
    
            if(i == s.size()){
                return 0;
            }
    
            int ans = 0;
    
            if(s[i] == t[j]){
                ans += solve(s, t, i + 1, j + 1);
            }
    
            ans += solve(s, t, i + 1, j);
            return ans;
        }
    
        int solveusingmem(string &s, string &t, int i, int j, vector<vector<int>>&dp){
            if(j == t.size()){
                return 1;
            }
    
            if(i == s.size()){
                return 0;
            }
    
            if(dp[i][j] != -1){
                return dp[i][j];
            }
    
            int ans = 0;
    
            if(s[i] == t[j]){
                ans += solveusingmem(s, t, i + 1, j + 1, dp);
            }
    
            ans += solveusingmem(s, t, i + 1, j, dp);
            dp[i][j] = ans;
            return dp[i][j];
        }
    
    
    
        int numDistinct(string s, string t) {
            int n = s.size();
            vector<vector<int>>dp(n, vector<int>(n, -1));
            return solveusingmem(s, t, 0, 0, dp);
        }
    };