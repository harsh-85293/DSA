class Solution {
    public:
        vector<string>solve(string &s, unordered_map<string, bool>dict, int i){
    
            if(i == s.size()){
                return {""};
            }
    
            vector<string>ans;
            string word;
    
            for(int j = i; j < s.size(); j++){
                word.push_back(s[j]);
                if(dict.find(word) == dict.end()) continue;
    
                //found  a valid word
                auto right = solve(s, dict, j + 1);
                for(auto it:right){
                    string endpart;
                    if(it.size() > 0){
                        endpart = " " + it;
                    }
                    ans.push_back(word + endpart);
                }
            }
            return ans;
        } 
    
        vector<string> wordBreak(string s, vector<string>& wordDict) {
            unordered_map<string, bool>dict;
            for(auto it:wordDict){
                dict[it] = 1;
            }
            return solve(s, dict, 0);
        }
    };