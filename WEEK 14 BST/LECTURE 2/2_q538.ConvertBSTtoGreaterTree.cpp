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
      void storeinorder(TreeNode* root, vector<int> &inorder){
          if(!root){
              return;
          }
          //LNR
          storeinorder(root->left, inorder);
          inorder.push_back(root->val);
          storeinorder(root->right, inorder);
      }

      void updatetree(TreeNode* root, vector<int> inorder, int &index){
          if(!root){
              return;
          }
          //LNR
          updatetree(root->left, inorder, index);
          root->val = inorder[index];
          index++;
          updatetree(root->right, inorder, index);
      }

      TreeNode* convertBST(TreeNode* root) {
          if(!root){
              return NULL;
          }
          if(!root->left && !root->right){
              return root;
          }
          //store inorder
          vector<int> inorder;
          storeinorder(root, inorder);
          
          //update inorder as per qustion rules
          int n = inorder.size();
          for(int i = n-1; i >= 0; i--){
              int curr = inorder[i];
              int nextval = 0;
              if(i + 1 < n){
                  nextval = inorder[i+1];
              }
              int sum = curr + nextval;
              inorder[i] = sum;
          }
          //update tree using inorder
          int index = 0;
          updatetree(root, inorder, index);
          return root;
      }
  };
  int main()
  {
    return 0;
  }