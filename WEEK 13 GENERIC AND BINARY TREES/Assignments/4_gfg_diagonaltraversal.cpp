    #include <bits/stdc++.h>
    using namespace std;
    void solve(Node* &root, map<int, vector<int>>&mp, int d){
      
      if(!root){
          return;
      }
      mp[d].push_back(root->data);
      solve(root->left, mp, d+1);
      solve(root->right, mp, d);
    }


    vector<int> diagonal(Node *root)
    {
      // your code here
      map<int, vector<int>>mp;
      vector<int>ans;
      solve(root, mp, 0);
      for (auto it : mp) {
        ans.insert(ans.end(), it.second.begin(), it.second.end());
    }

        return ans;
      
    }
    int main()
    {
      return 0;
    }