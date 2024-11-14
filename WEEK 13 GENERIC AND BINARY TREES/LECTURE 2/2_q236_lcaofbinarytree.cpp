  #include <bits/stdc++.h>
  using namespace std;
 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base cases
        if(root == NULL){
            return NULL;
        }

        if(root == p){
            return p;
        }

        if(root == q){
            return q;
        }

        TreeNode* leftans = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightans = lowestCommonAncestor(root->right, p, q);


        if(leftans == NULL && rightans == NULL){
            return NULL;
        }

        else if(leftans == NULL && rightans != NULL){
            return rightans;
        }

        else if(leftans != NULL && rightans == NULL){
            return leftans;
        }

        else{
            //leftans == NULL and rightans == NULL
            //root is the answer
            return root;
        }
        
    }
};
  int main()
  { 
    Solution S;
    return 0;
  }