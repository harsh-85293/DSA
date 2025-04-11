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
        int solve(TreeNode* root){
            if(!root){
                return 0;
            }
            int rob = 0;
            int dontrob = 0;
    
            rob = root->val;
            if(root->left){
                    rob += solve(root->left->left) + solve(root->left->right);
            }
    
            if(root->right){
                    rob += solve(root->right->left) + solve(root->right->right);
            }
        
            dontrob = solve(root->left) + solve(root->right);
            return max(rob, dontrob);
        }
        int solveusingmemo(TreeNode* root, unordered_map<TreeNode*, int>&dp){
            if(!root){
                return 0;
            }
    
            if( dp.find(root) != dp.end() ){
                return dp[root];
            }
    
            int rob = 0;
            int dontrob = 0;
    
            rob = root->val;
            if(root->left){
                    rob += solveusingmemo(root->left->left, dp) + solveusingmemo(root->left->right, dp);
            }
    
            if(root->right){
                    rob += solveusingmemo(root->right->left, dp) + solveusingmemo(root->right->right, dp);
            }
        
            dontrob = solveusingmemo(root->left, dp) + solveusingmemo(root->right, dp);
            dp[root] =  max(rob, dontrob);
            return dp[root];
        }
        
        int rob(TreeNode* root) {
            //return solve(root);
            unordered_map<TreeNode*, int>dp;
            return solveusingmemo(root, dp);
        }
    };