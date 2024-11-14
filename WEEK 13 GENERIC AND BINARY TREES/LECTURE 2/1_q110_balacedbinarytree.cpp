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
        int getheight(TreeNode* root)
        {
            if(root == NULL)
            {
                return 0;
            }
            int leftsubtree = getheight(root->left);
            int rightsubtree = getheight(root->right);

            int maxi = max(leftsubtree, rightsubtree);
            int ans = maxi+1;

            return ans;
        }
        bool isBalanced(TreeNode* root) {

            if(root == NULL)
            {
                return true;
            }
            //current node ka nikalo
            //1 case khud karo
            int lh = getheight(root->left);
            int rh = getheight(root->right);
            int h = abs(lh - rh);
            bool status = (h<=1) ? true : false;

            //baaki recursion sambhal lega
            bool leftans = isBalanced(root->left);
            bool rightans = isBalanced(root->right);
            
            if(status && leftans && rightans)
            {
                return true;
            }
            return false;
        }
    };