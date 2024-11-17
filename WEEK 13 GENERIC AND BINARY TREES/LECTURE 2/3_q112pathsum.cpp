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
        bool solve(TreeNode* root, int targetSum, int sum){
            if(root == NULL){
                return false;
            }

            //root pakka not null hai
            sum += root -> val;

            if(root->left == NULL && root->right == NULL){
                //root is a leaf node
                if(sum == targetSum){
                    return true;
                }
                else{
                    return false;
                }
            }

            bool leftkaans = solve(root->left, targetSum, sum);
            bool rightkaans = solve(root->right, targetSum, sum);

            return leftkaans||rightkaans;
        }

        bool hasPathSum(TreeNode* root, int targetSum) {
            int sum = 0;
            bool ans = solve(root, targetSum, sum);
            return ans;
        }
    };
    int main()
    {
        return 0;
    }