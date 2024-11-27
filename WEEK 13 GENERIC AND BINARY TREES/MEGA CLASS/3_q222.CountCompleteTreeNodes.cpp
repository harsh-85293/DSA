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
        void inordertraversal(TreeNode* &root, int &count)
        {
            if(!root)
            {
                return ;
            }

            //LNR
            //L
            inordertraversal(root->left, count);
            //N
            count ++;
            //R
            inordertraversal(root->right, count);
        }

        int countNodes(TreeNode* root) {
            int count = 0;
            inordertraversal(root, count);
            return count;
        }
    };
    int main()
    {
    return 0;
    }