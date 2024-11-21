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
        void storeinorder(TreeNode* root, vector<int>&inorder){
            if(!root){
                return;
            }

            //LNR
            storeinorder(root->left, inorder);
            inorder.push_back(root->val);
            storeinorder(root->right, inorder);
        }

        bool findTarget(TreeNode* root, int k) {
            
            if(!root->left && !root->right){
            return false;
            }

            bool ans = false;
            vector<int>inorder;
            storeinorder(root, inorder);
            int i = 0;
            int j = inorder.size() - 1;
            while(i < j){
                if(inorder[i] + inorder[j] == k){
                    ans = true;
                    break;
                }
                else if(inorder[i] + inorder[j] < k){
                    i++;
                }
                else{
                    j--;
                }
            }
            return ans;
        }
    };
  int main()
  {
    return 0;
  }