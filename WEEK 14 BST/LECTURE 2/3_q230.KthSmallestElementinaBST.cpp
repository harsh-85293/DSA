  // FIRST APPROACH
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
        void storeinorder(TreeNode* root, vector<int> &inorder){
            if(!root){
                return;
            }
            //LNR
            storeinorder(root->left, inorder);
            inorder.push_back(root->val);
            storeinorder(root->right, inorder);
        }
        int kthSmallest(TreeNode* root, int k) {
            vector<int> inorder;
            storeinorder(root, inorder);
            return inorder[k-1];
        }
    };
  int main()
  {
    return 0;
  }