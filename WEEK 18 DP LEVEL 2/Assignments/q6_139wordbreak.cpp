class Solution {
    public:
    
        bool check(vector<string>& wordDict, string &word){
            for(auto it : wordDict){
                if(it == word){
                    return true;
                }
            }
            return false;
        }
    
        bool solve(string &s, vector<string>& wordDict, int start){
            if(start == s.size()){
                return true;
            }
    
            string word = "";
            bool ans = false;
            for(int i = start; i < s.size(); i++){
                word += s[i];
                if(check(wordDict, word) == true){
                    ans  = ans || solve(s, wordDict, i + 1);
                }
            }
            return ans;
        }
    
        bool solveusingmem(string &s, vector<string>& wordDict, int start, vector<int>&dp){
            if(start == s.size()){
                return true;
            }   
    
            if(dp[start] != -1){
                return dp[start];
            }
    
            string word = "";
            bool ans = false;
            for(int i = start; i < s.size(); i++){
                word += s[i];
                if(check(wordDict, word) == true){
                    ans  = ans || solveusingmem(s, wordDict, i + 1, dp);
                }
            }
            dp[start] = ans;
            return dp[start];
        }
    
        bool wordBreak(string s, vector<string>& wordDict) {
           vector<int>dp(s.size() + 1, -1);
           return solveusingmem(s, wordDict, 0, dp);  
        }
    };