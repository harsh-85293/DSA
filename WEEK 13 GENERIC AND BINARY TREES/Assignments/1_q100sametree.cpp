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
        bool isSameTree(TreeNode* p, TreeNode* q) {

            //ek case mera
            if(p==NULL && q==NULL){
                return true;
            }

            if(p==NULL || q==NULL || p->val != q->val){
                return false;
            }
            
            if(p == q){
                return true;
            }

            //baaki recursion sambhal lega
            bool leftans = isSameTree(p->left, q->left);
            bool rightans = isSameTree(p->right, q->right);

            return (leftans && rightans);
        }
    };


    int main()
    {
        return 0;
    }