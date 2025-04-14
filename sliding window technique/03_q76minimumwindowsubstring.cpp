class Solution {
    public:
        string minWindow(string s, string t) {
            int len1 = s.length();
            int len2 = t.length();
    
            if(len1 < len2){
                //no answer
                return "";
            }
    
            //in do variable ke basis par mai exact string find kar sakta hu
            int ansindex = -1;
            int anslen = INT_MAX;
    
            unordered_map<char, int>smap;
            unordered_map<char, int>tmap;
    
            //values fill krte hai tmap ke andar
            for(auto i:t){
                tmap[i]++;
            }
    
            int start = 0;
            int end = 0;
            //count tracks total matched characters in the window
            int count = 0;
    
            //variable size window vala logic run krte hai
            while(end < s.length()){
                char ch = s[end];
                //update karna h s,map, kyuklki s wali string ki window me kon kon se characters hai unhe track karna hai
                smap[ch]++;
                //possibility hai ye character t ke andar ho ya na ho
                // agar yai t wali ke andar haiu to matched wali ke andar hai ya nahi hai
                if(smap[ch] <= tmap[ch]){
                    count++;
                }
                //count == len2 => ans mil gaya
                if(count  == len2){
                    //minimize
                    while(smap[s[start]] > tmap[s[start]]){
                        smap[s[start]]--;
                        start++;
                    }
                    //ans store
                    int windowlength = end - start +1;
                    if(windowlength < anslen){
                        anslen  = windowlength;
                        ansindex = start;
                    }
                }
                //cant find a  valid answer 
                //expand
                end++;
            }   
            if(ansindex == -1){
                return "";
            }
            return s.substr(ansindex, anslen);
        }
    };