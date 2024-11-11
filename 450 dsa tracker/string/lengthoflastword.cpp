class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        istringstream iss(s);
        vector<string>words;
        string word;
        
        while (iss >> word) 
        {
            words.push_back(word);
        }
        int n=words.size();
        string ans=words[n-1];
        int g=ans.length();
        return g;
    }
};