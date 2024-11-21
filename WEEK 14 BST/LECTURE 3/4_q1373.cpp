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


    class Info{
        public:
            int minvalue;
            int maxvalue;
            int sum;
            bool isbst;


    };

    class Solution {
    public:
        Info solve(TreeNode* root, int &sum){
            //base cases
            if(!root){
                Info temp;
                temp.minvalue = INT_MAX;
                temp.maxvalue = INT_MIN;
                temp.sum = 0;
                temp.isbst = true;
                sum = max(sum, temp.sum);
                return temp;
            }

            if(!root->left && !root->right){
                Info temp;
                temp.minvalue = root->val;
                temp.maxvalue = root->val;
                temp.sum = root->val;
                temp.isbst = true;
                sum = max(sum, temp.sum);
                return temp;
            }
            //LRN
            Info leftans = solve(root->left, sum);
            Info rightans = solve(root->right, sum); 
            
            //N
            Info currentans;
            currentans.minvalue = min(root->val, min(leftans.minvalue, rightans.minvalue));
            currentans.maxvalue = max(root->val, max(leftans.maxvalue, rightans.maxvalue));
            currentans.sum = leftans.sum + rightans.sum + root->val;
            currentans.isbst = (root->val > leftans.maxvalue && root->val < rightans.minvalue && leftans.isbst && rightans.isbst);

            if(currentans.isbst){
                sum = max(sum, currentans.sum);
            }
            return currentans;
        }

        int maxSumBST(TreeNode* root) {
            int sum = 0;
            Info temp = solve(root, sum);
            return sum;
        }
    };
    int main()
    {
    return 0;
    }