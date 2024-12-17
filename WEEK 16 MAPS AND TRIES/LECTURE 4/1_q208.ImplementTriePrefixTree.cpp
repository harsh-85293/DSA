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

  bool searchprefix(TrieNode* root, string word){
    //base case-> check karo last character terminal hai ya nahi
    if(word.length() == 0){
        return true;
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
    bool recursionkaans = searchprefix(child, word.substr(1));
    return recursionkaans;
  }  

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('-');
    }
    
    void insert(string word) {
        insertinTrie(root, word);
    }
    
    bool search(string word) {
        bool ans = searchTrie(root, word);
        return ans;
    }
    
    bool startsWith(string prefix) {
        bool ans = searchprefix(root, prefix);
        return ans;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
  int main()
  {
    return 0;
  }
 