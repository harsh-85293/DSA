  #include <bits/stdc++.h>
  using namespace std;
  /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int targetSum, int sum,vector<int> path, vector<vector<int>>&ans){
        if(root == NULL){
            return;
        }
        //root pakka not null hai
        sum += root->val;
        path.push_back(root->val);

        //check for leaf node
        if(root->left ==NULL && root->right == NULL){
            if(sum == targetSum){
                ans.push_back(path);
            }
            return;
        }

        solve(root->left, targetSum, sum, path, ans);
        solve(root->right, targetSum, sum, path, ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int> path;
        vector<vector<int>>ans;
        solve(root, targetSum, sum, path, ans);
        return ans;
    }
};
  int main()
  {
      return 0;
  }