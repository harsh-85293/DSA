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
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    

    class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(!root){
                return NULL;
            }
            // step A:p and q on left side
            //right neglect left select
            if(p->val < root->val && q->val < root->val){
                TreeNode* leftans = lowestCommonAncestor(root->left, p, q);
                if(leftans){
                    return leftans;
                }
            }
            // step B:p and q on right side
            if(p->val > root->val && q->val > root->val){
                TreeNode* rightans = lowestCommonAncestor(root->right, p, q);
                if(rightans){
                    return rightans;
                }
            }
            // step c : p left q right
            // step d : p right q left
            // no check in both cases
            return root;
        }
    };