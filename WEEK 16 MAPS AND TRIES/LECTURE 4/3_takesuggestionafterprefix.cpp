    #include <bits/stdc++.h>
    using namespace std;

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

    bool searchTrie(TrieNode* root, string word){
        //base case-> check karo last character terminal hai ya nahi
        if(word.length() == 0){
          //iska matlab root mai last character pada hua hai
          if(root->isterminal == true){
            return true;
          }
          else{ 
            return false;
          }
        }

        //1 case mai solve karunga
        char ch = word[0];
        TrieNode* child;

        if(root->childrenmap.find(ch) != root->childrenmap.end()){
          //present
          child = root->childrenmap[ch];
        }
        else{
          //absent
          return false;
        }
        //baaki recursion sambhal lega
        bool recursionkaans = searchTrie(child, word.substr(1));
        return recursionkaans;
    }

    void deleteinTrie(TrieNode* root, string word){
        //base case
        //ek time aisa aayega jab word empty hoga 
        //aur root mai last character hoga
        if(word.length() == 0){
          root -> isterminal = false;
          return;
        }

        //1 case mai solve karunga
        char ch = word[0];
        TrieNode* child;

        if(root -> childrenmap.find(ch) != root->childrenmap.end()){
          //present
          child = root->childrenmap[ch];
        }
        //absent
        else{
          return;
        }

        //baaki recursion sambhal lunga
        deleteinTrie(child, word.substr(1));
    }

    void storestring(TrieNode* root, vector<string> &ans, string output){
        //base case
        if(root->isterminal){
          ans.push_back(output);
          //no need for return keyword
        }

        //1 case mai solve karunga
        for(auto it : root->childrenmap){
          char ch = it.first;
          TrieNode* child = it.second;
          output.push_back(ch);

          
        //baaki recursion sambhal lega
        storestring(child, ans, output);
        //backtracking
        output.pop_back();
        }
    }

    void findwithprefix(TrieNode* root, string prefix, vector<string>&ans){
        
        // base case 
        if(prefix.length() == 0){
          //prefix pura search ho chuka hai
          //and root abhi prefix string k last character ko store karegi

          //ab iss last node ke niche jitni bhi strings ban sakti hai
          //un sab ko create karke store karenge below function mai
          string temp = "";
          storestring(root, ans, temp);  
          return;
        }
        //1 case mai solve karunga 
        char ch = prefix[0];
        TrieNode* child;

        if(root->childrenmap.find(ch) != root->childrenmap.end()){
          //present
          child = root->childrenmap[ch];
        }

        else{
          //absent
          return;
        }

          // baaki recursion sambhal lega
        findwithprefix(child, prefix.substr(1), ans);
    }

    vector<vector<string>>getsuggestion(TrieNode* root, string prefix){

        vector<vector<string>>ans;
        string temp = "";
        
        for(int i = 0; i < prefix.length(); i++){

          vector<string>tempans;
          char currchar = prefix[i];
          temp.push_back(currchar);
          findwithprefix(root, temp, tempans);

          //add temp prefix in tempans array
          for(int j = 0; j < tempans.size(); j++){
            tempans[j] = temp + tempans[j];
          }
          ans.push_back(tempans);
        }
        return ans;
    }

    int main()
    {
        TrieNode* root = new TrieNode('-');
        
        insertinTrie(root, "babbar");
        insertinTrie(root, "baby");
        insertinTrie(root, "bala");
        insertinTrie(root, "baba");
        
        string prefix = "bal";
        vector<vector<string>> ans = getsuggestion(root, prefix);
        for(int  i = 0; i < ans.size(); i++){
          for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
          }
          cout << endl;
        }
        // findwithprefix(root, prefix, ans);
        // for(int i = 0; i < ans.size(); i++){
        //   string str = prefix + ans[i];
        //   ans[i] = str;
        //   cout << ans[i] << " " << endl;
        // } 
        // cout << "breaker" << endl;
        
        return 0;
    } 