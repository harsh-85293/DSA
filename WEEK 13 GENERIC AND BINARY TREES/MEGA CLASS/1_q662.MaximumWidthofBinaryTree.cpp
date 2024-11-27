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
      int widthOfBinaryTree(TreeNode* root) {
          unsigned long long maxwidth = 0;
          if(!root){
              return maxwidth;
          }

          queue<pair<TreeNode*, unsigned long long>>q;
          q.push({root, 1});

          while(!q.empty()){
              //this is my current number nodes
              unsigned long long size = q.size();
              unsigned long long leftmostindex = q.front().second;
              unsigned long long rightmostindex = q.back().second;
              unsigned long long currentwidth = rightmostindex - leftmostindex + 1;
              maxwidth = max(maxwidth, currentwidth);

              //Traverse over all nodes of current levels
              for(long long i = 0; i < size; i++){
                  auto front  = q.front();
                  q.pop();
                  auto node = front.first;
                  auto index = front.second;

                  //process its child and assign them index
                  if(node->left){
                      q.push({node->left, 2*index});
                  }
                  if(node->right){
                      q.push({node->right, 2*index + 1});
                  }
              }
          }
          return maxwidth;
      }
  };
  
  int main()
  {
    return 0;
  }