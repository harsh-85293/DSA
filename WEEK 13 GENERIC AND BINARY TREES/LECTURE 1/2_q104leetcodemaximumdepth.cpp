  //Height of a tree
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

    class TreeNode
    {
        public:
            int data;
            TreeNode* left;
            TreeNode* right;    

            TreeNode(int value)
            {
                this -> data = value;
                left = NULL;
                right = NULL;
            }
    };
    class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if(root == NULL){
                return 0;
            }

            int leftsubtree = maxDepth(root->left);
            int rightsubtree = maxDepth(root->right);

            int maxi = max(leftsubtree, rightsubtree);
            int  ans = maxi + 1;//for root node
            return ans;
        }
    };
  int main()
  {
      return 0;
  }