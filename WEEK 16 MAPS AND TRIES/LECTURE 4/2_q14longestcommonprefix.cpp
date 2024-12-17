   #include <bits/stdc++.h>
   using namespace std;

    class Solution {
    public:

        class TrieNode{
        public:
            char value;
            unordered_map<char, TrieNode*>childrenmap;
            bool isterminal;

            TrieNode(char data){
            value = data;
            isterminal = false;
            }
        };

        void insertinTrie(TrieNode* root, string word){
        //base case->ek time aisa aayega jab aapki string empty aaegi
        //tab terminal mark kar do
        if(word.length() == 0){
        root -> isterminal = true;
        return;
        }

        // 1 case solve karna
        // 1 character ko trie me insert karna
        char ch = word[0];
        TrieNode* child;
        
        //present hai to waha chale jao
        if(root -> childrenmap.count(ch) ==1 ){
        /*retrieves or initializes a child node in the unordered map childrenmap for the 
        character ch*/
        child = root -> childrenmap[ch];    
        }

        //absent hai to create kar do
        else{
        //absent
        child = new TrieNode(ch);
        //link 
        //assigns the child node to the childrenmap of the current root node, using ch as the key.
        root->childrenmap[ch] = child;
        }
        //baaki recursion sambhal lega
        insertinTrie(child, word.substr(1));
    }
        //single baccha -> answer insert
        void findlcp(TrieNode* root, string &ans){
            //base case
            if(root->isterminal == true){
                return;
            }
            //1 case solve karunga
            TrieNode* child;
            if(root->childrenmap.size() == 1){
                //1 hi bacha hai
                for(auto i : root->childrenmap){
                    char ch = i.first;
                    ans.push_back(ch);
                    child = i.second;
                }
            }
            else{
                return;
            }
            //baaki recursion sambhal lega
            findlcp(child, ans);
        }

        string longestCommonPrefix(vector<string>& strs) {
            TrieNode* root = new TrieNode('-');

            //insert all words into trie
            for(auto it:strs){
                insertinTrie(root, it);
            }

            //main logic
            string ans = "";
            findlcp(root, ans);
            return ans;
        }
    };

   int main()
   {
     return 0;
   }