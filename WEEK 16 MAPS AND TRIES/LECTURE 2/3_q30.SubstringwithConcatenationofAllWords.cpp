   #include <bits/stdc++.h>
   using namespace std;
     class Solution {
     public:
     //track indivisual word count
     unordered_map<string, int>mp;
     vector<int> findSubstring(string s, vector<string>& words) {
          vector<int>ans;
          for(int i = 0; i < words.size(); i++){
               mp[words[i]]++;
          }

          int wordlength = words[0].length();
          //offset logic -. word length 0,1,2,....
          for(int offset = 0; offset < wordlength; offset++){
               unordered_map<string, int>visited;
               //ans mila kya check karne ke liye count = 0
               int count = 0;

               //ab mai wordlength kieliye substring uthaunga
               for(int i = offset; i + wordlength <= s.size(); i = i + wordlength){
                    string substr = s.substr(i, wordlength);

                    //check if the substring is valid or not
                    if(mp.find(substr) == mp.end()){
                         //invalid string
                         //purane saare answer ko bhul jaana chahiye
                         visited.clear();
                         count = 0;
                         continue;
                    }

                    else{
                         //valid string
                         visited[substr]++;
                         count++;

                         // GAME CHANGER -> removal
                         while(visited[substr] > mp[substr]){
                         //hr word visited mai aur count dono mai se
                         //vo word hatega
                         string temp = s.substr( i - (count - 1) * wordlength, wordlength) ;
                         visited[temp]--;
                         count--;

                         }
                         // GAME CHANGER

                         //ans mila kya
                         if(count == words.size()){
                         //ans mil gaya
                         //mujhe starting index return ans me insert karna hai
                         ans.push_back(i - (count - 1) * wordlength);
                         }
                    }
               }

          }
          return ans;
     }
     };
   int main()
   {
        return 0;
   }
