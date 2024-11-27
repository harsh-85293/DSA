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
      int solve(TreeNode* root, int &cameras){
          if(!root){
              return 1;//null noes are assume to be covered
          }
          int left = solve(root->left, cameras);
          int right = solve(root->right, cameras);
          
          //either nodes are not covered
          if(left == 0 || right == 0){
              cameras++;
              return 2;// my cam is installed
          }
          
          if(left == 2 || right == 2){
              return 1;// yeah i am already covered by my child
          }

          return 0;//i am not covered

      }

      int minCameraCover(TreeNode* root) {
          int cameras = 0;
          int rootstates = solve(root, cameras);
          if(rootstates == 0){
              cameras++; 
          }
          return cameras;
      }
  };
  int main()
  {
    return 0;
  }