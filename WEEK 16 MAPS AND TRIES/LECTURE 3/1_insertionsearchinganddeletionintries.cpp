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
      if(root -> childrenmap.count(ch) == 1 ){
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
    if(word.length() == 0)//it means all characters of the word have been processed.
    {
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
      child = root->childrenmap[ch];//proceeed further to check if full word is present and not just the part
    }
    //absent
    else{
      return;
    }

    //baaki recursion sambhal lunga
    deleteinTrie(child, word.substr(1));
  }

  int main()
  {
    TrieNode* root = new TrieNode('-');
    insertinTrie(root, "cover");
    insertinTrie(root, "care");
    insertinTrie(root, "snake");
    insertinTrie(root, "fivefoot");
    insertinTrie(root, "extremelywell");
    insertinTrie(root, "coward"); 
    insertinTrie(root, "selfobsessed");
    insertinTrie(root, "tag");
    insertinTrie(root, "take");
    insertinTrie(root, "took");

    string input;
    cout << "enter string:";
    cin >> input;

    //deleteinTrie(root, "cover");

    bool ans = searchTrie(root, input);

    if(ans){
      cout << input << " found";
    }
    else{
      cout << input << " not found";
    }

    return 0;
  }