   #include <bits/stdc++.h>
   using namespace std;
    class Solution {
    public:
        vector<string> findRepeatedDnaSequences(string s) {
            unordered_map<string, int>mp;//stored 10 sized substring
            vector<string>ans;

            if(s.size() < 10){
                return {};
            }

            //sliding 10 window size
            for(int i = 0; i <= s.size() - 10; i++){
                string curr =  s.substr(i, 10);
                mp[curr]++;
            }

            for(auto it : mp){
                if(it.second > 1){
                    ans.push_back(it.first);
                }
            }
            return ans;
        }
    };
   int main()
   {
     return 0;
   }
