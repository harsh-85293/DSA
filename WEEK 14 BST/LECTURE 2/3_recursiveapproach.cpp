    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
    return 0;
    }
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
        void solve(TreeNode* root, int k, int &count, TreeNode* &ans){
            if(!root){
                return ;
            }
            //LNR
            solve(root->left, k, count, ans);
            count++;
            if(count == k){
                ans = root;
            }

            solve(root->right, k, count, ans);
        }   

        int kthSmallest(TreeNode* root, int k) {
            int count = 0;
            TreeNode* ans = nullptr;
            solve(root, k, count, ans);
            return ans->val;
        }
    };