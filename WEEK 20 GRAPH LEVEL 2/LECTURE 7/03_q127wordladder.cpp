class Solution {
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            queue<pair<string, int>>q;
            q.push({beginWord, 1});
    
            unordered_set<string>st(wordList.begin(), wordList.end());
            // set and queue are ready
    
            //kyoki mai begib word use kar chuka hu
            // so i should erase it from dictionary or set
            st.erase(beginWord);
    
    
            //main traversal logic
            while(!q.empty()){
                pair<string, int>frontpair  = q.front();
                q.pop();
    
                string frontstring = frontpair.first;
                int frontdistance = frontpair.second;
    
                //check if frontkeynode is the answer
                if(frontstring == endWord){
                    return frontdistance;
                }
    
                for(int i = 0; i < frontstring.length(); i++){
                    
                    char original = frontstring[i];
                    
                    for(char ch = 'a' ; ch <= 'z'; ch++){
                        frontstring[i] = ch;
                        //check if thew new string is in the dictionary
                        if(st.find(frontstring) != st.end()){
                            //valid string because it is found in the dictionary 
                            q.push({frontstring, frontdistance + 1});
                            st.erase(frontstring);
                        }
                    }
                   //backtrack
                    frontstring[i] = original;
                }
            }
            return 0;
        }
    }; 