#include <bits/stdc++.h> 
using namespace std;

void permutation(string &s,vector<string> &ans,int i)
{
     if(i>=s.length())
    {
        ans.push_back(s);
        return;  
    }

    for(int j=i;j<s.length();j++)
    {
        swap(s[i],s[j]);//ek case mai karunga
        permutation(s,ans,i+1);//baaki recursion karegaa
        swap(s[i],s[j]);
    }
}

vector<string> findPermutations(string &s) 
{
    // Write your code here.
    vector<string>ans;
    int i=0;
    permutation(s, ans,i);
    
    return ans;
}