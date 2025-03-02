class Solution {
    public:
        int solveusingrec(string &text1, string &text2, int i, int j){
            if(i >= text1.size()){
                return 0;
            }
            if(j >= text2.size()){
                return 0;
            }
    
            int ans = 0;
    
            if(text1[i] == text2[j]){
                ans = 1 + solveusingrec(text1, text2, i + 1, j + 1);
            }
            else{
                ans =  max(solveusingrec(text1, text2, i + 1, j), solveusingrec(text1, text2, i, j + 1));
            }   
            return ans;
        }   
        int solveusingmemo(string &text1, string &text2, int i, int j,  vector<vector<int>>&dp){
            if(i >= text1.size()){
                return 0;
            }
            if(j >= text2.size()){
                return 0;
            }
    
            if(dp[i][j] != -1){
                return dp[i][j];
            }
            int ans = 0;
    
            if(text1[i] == text2[j]){
                dp[i][j] = 1 + solveusingmemo(text1, text2, i + 1, j + 1, dp);
            }
            else{
                dp[i][j] =  max(solveusingmemo(text1, text2, i + 1, j, dp), solveusingmemo(text1, text2, i, j + 1, dp));
            }   
            return dp[i][j];
        }
    
        int solveusingtab(string &text1, string &text2, int i, int j){
            vector<vector<int>>dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));
    
            for(int i = text1.length() - 1; i >=0; i--){
                for(int j = text2.length() - 1;  j >=0; j--){
                    int ans = 0;
    
                    if(text1[i] == text2[j]){
                        ans = 1 + dp[i + 1][j + 1];
                    }
                    else{
                        ans =  max( dp[i + 1][j], dp[i][ j + 1] );
                    }   
                    dp[i][j] = ans;
                }
            }
            return dp[0][0];
        }
    
        int solveusingso(string &text1, string &text2, int i, int j){
            // vector<vector<int>>dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));
            vector<int>prev(text2.length() + 1, 0);
            vector<int>curr(text2.length() + 1, 0);
    
            for(int i = text1.length() - 1; i >=0; i--){
                for(int j = text2.length() - 1;  j >=0; j--){
                    int ans = 0;
    
                    if(text1[i] == text2[j]){
                        ans = 1 + prev[j + 1];
                    }
                    else{
                        ans =  max( prev[j], curr[ j + 1] );
                    }   
                    curr[j] = ans;
                }
                prev = curr;
            }
            return prev[0];
        }
    
        int longestCommonSubsequence(string text1, string text2) {
            int i = 0, j = 0;
            // return solveusingrec(text1, text2, i, j);
            vector<vector<int>>dp(text1.length() + 1, vector<int>(text2.length() + 1, -1));
            // return solveusingmemo(text1, text2, i, j, dp);
            // return solveusingtab(text1, text2, i, j);
            return solveusingso(text1, text2,  i,  j);
        }
    };