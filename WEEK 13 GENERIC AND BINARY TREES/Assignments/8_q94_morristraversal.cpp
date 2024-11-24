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
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int>ans;
            TreeNode* curr = root;
            while(curr){
                //left node is NULL visit right
                if(!curr->left){
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
                else{
                    //left node is not NULL
                    //find inorder predescessor
                    TreeNode* pred = curr->left;
                    while(pred->right && pred->right != curr){
                        pred = pred->right;
                    }
                    //if right node is null then go left after establishing from predecessor from current
                    if(!pred->right){
                        pred->right = curr;
                        curr = curr->left;
                    }
                    else{
                        //left is already visited
                        //go right after visiting current node
                        pred->right = NULL;
                        ans.push_back(curr->val);
                        curr = curr->right;
                    }
                }
            }
            return ans;
        }
    };
  int main()
  {
    return 0;
  }