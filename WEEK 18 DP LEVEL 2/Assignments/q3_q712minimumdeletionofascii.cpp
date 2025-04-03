class Solution {
    public:
        int solve(string &s1, string &s2, int i1, int i2){
            int cost = 0;
            if(i1 == s1.size() || i2 == s2.size()){
                //return the size of remaining characters ascii value
                for(int x = i1; x < s1.size(); x++){
                    cost += s1[x];
                } 
                for(int x = i2; x < s2.size(); x++){
                    cost += s2[x];
                } 
            }
    
            else if(s1[i1] == s2[i2]){
                cost = solve(s1, s2, i1 + 1, i2 + 1);
            }
            else{
                int cost1 = s1[i1] + solve(s1, s2, i1 + 1, i2);
                int cost2 = s2[i2] + solve(s1, s2, i1, i2 + 1);
                cost = min(cost1, cost2);
            }
            return cost;
        }
    
        int solvemem(string &s1, string &s2, int i1, int i2, vector<vector<int>>&dp){
    
            int cost = 0;
    
            if(dp[i1][i2] != -1){
                return dp[i1][i2];
            } 
    
            if(i1 == s1.size() || i2 == s2.size()){
                //return the size of remaining characters ascii value
                for(int x = i1; x < s1.size(); x++){
                    cost += s1[x];
                } 
                for(int x = i2; x < s2.size(); x++){
                    cost += s2[x];
                } 
            }
    
            else if(s1[i1] == s2[i2]){
                cost = solvemem(s1, s2, i1 + 1, i2 + 1, dp);
            }
            else{
                int cost1 = s1[i1] + solvemem(s1, s2, i1 + 1, i2, dp);
                int cost2 = s2[i2] + solvemem(s1, s2, i1, i2 + 1, dp);
                cost = min(cost1, cost2);
            }
            dp[i1][i2] = cost;
            return dp[i1][i2];
        }
    
        int minimumDeleteSum(string s1, string s2) {
            vector<vector<int>>dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
            return solvemem(s1, s2, 0, 0, dp);
        }
    };