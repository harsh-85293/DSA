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
        int getheight(TreeNode* root){
            if(root == NULL){
                return 0;
            }
            int left = getheight(root->left);
            int right = getheight(root->right);
            int maxi = max(left, right);
            int totalheight = maxi + 1;
            return totalheight; 
        }
        int diameterOfBinaryTree(TreeNode* root) {
            if(root == NULL){
                return 0;
            }

            int option1 = diameterOfBinaryTree(root->left);
            int option2 = diameterOfBinaryTree(root->right);
            int option3 = getheight(root->left) + getheight(root->right);
            int maxdiameter = max(option1, max(option2, option3) );
            return maxdiameter;
        }
    };
  int main()
  {
      return 0;
  }