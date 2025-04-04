  #include <bits/stdc++.h>
  using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

    class Solution {
    public:
        vector<vector<int>> verticalTraversal(TreeNode* root) {
            vector<vector<int>>ans;
            queue<pair<TreeNode*, pair<int, int>>>q;// Node(row, col)
            q.push({root, {0, 0}});
            map<int, map<int, multiset<int>>>mp;// col -> {row: [x,y,z........]}
            while(!q.empty()){
                auto front = q.front();
                q.pop();
                TreeNode* node = front.first;
                auto coordinate = front.second;
                int &row = coordinate.first;
                int &col  = coordinate.second;
                mp[col][row].insert(node->val);
                if(node->left){
                    q.push({node->left, {row + 1, col - 1}});
                }
                if(node->right){
                    q.push({node->right, {row + 1, col + 1}});
                }
            }
            //store the vertical order into ans vector
            for(auto it:mp){
                auto &colmap = it.second;
                vector<int>vline;
                for(auto colmapit:colmap){
                    auto &mset = colmapit.second;
                    vline.insert(vline.end(), mset.begin(), mset.end());
                }
                ans.push_back(vline);
            }
        
            return ans;
            
        }
    };

  int main()
  {
    return 0;
  }