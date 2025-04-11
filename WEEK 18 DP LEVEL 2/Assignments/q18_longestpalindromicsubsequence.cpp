class Solution {
    public:
        int solve(string &s, int i, int j) {
            if(i > j) return 0;
            if(i == j) return 1;
    
            if(s[i] == s[j]) {
                return 2 + solve(s, i + 1, j - 1);
            } else {
                return max(solve(s, i + 1, j), solve(s, i, j - 1));
            }
        }
        int solveusingmemo(string &s, int i, int j, vector<vector<int>>&dp) {
            if(i > j) return 0;
            if(i == j) return 1;
    
            if(dp[i][j] != -1){
                return dp[i][j];
            }
            
            if(s[i] == s[j]) {
                return dp[i][j] =  2 + solveusingmemo(s, i + 1, j - 1, dp);
            } 
            
            else {
                return dp[i][j] = max(solveusingmemo(s, i + 1, j, dp), solveusingmemo(s, i, j - 1, dp));
            }
        }
    
        int longestPalindromeSubseq(string s) {
            int n = s.size();
            vector<vector<int>>dp(n+1, vector<int>(n + 1, -1));
            return solveusingmemo(s, 0, s.size() - 1, dp);
        }
    };
    