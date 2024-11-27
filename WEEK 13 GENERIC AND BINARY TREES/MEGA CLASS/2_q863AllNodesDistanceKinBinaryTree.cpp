/* Self Notes:
1) Mark each node to its parent to traverse upwards
2) We will do a BFS traversal starting from the target node
3) As long as we have not seen our node previously, Traverse up, left, right
   until reached Kth distance
4) when reached Kth distance, break out of BFS loop and remaining node's values
   in our queue is our result
*/

  #include <bits/stdc++.h>
  using namespace std;
    
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  
  class Solution {
  public:
      //step 1: we have to make child to parent mapping
      void mapparent(TreeNode* &root, unordered_map<TreeNode* , TreeNode*>&parentmap){
          if(!root){
              return;
          }

          if(root->left){
              parentmap[root->left] = root;
              mapparent(root->left, parentmap);
          }

          if(root->right){
              parentmap[root->right] = root;
              mapparent(root->right, parentmap);
          } 
      }

      vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
          unordered_map<TreeNode* , TreeNode*>parentmap;
          parentmap[root] = NULL;
          mapparent(root, parentmap);
          unordered_map<TreeNode*, bool>visited;
          queue<TreeNode*>q;
          q.push(target);
          visited[target] = true;

          int currentlevel = 0;
          while(!q.empty()){
              int size = q.size();
              if(currentlevel == k){
                  break;
              }
              currentlevel++;
              //processing current levels
              for(int i = 0; i < size; i++){
                  auto front = q.front();
                  q.pop();

                  if(front->left && visited.find(front->left) == visited.end()){
                      //front has its left child and is not visited
                      q.push(front->left);
                      visited[front->left] = true;
                  }

                  if(front->right && visited.find(front->right) == visited.end()){
                      //front has its left child and is not visited
                      q.push(front->right);
                      visited[front->right] = true;
                  }

                  //new thing here we need to map parent too
                  auto parentnodefront = parentmap[front]; 
                  if(parentnodefront && visited.find(parentnodefront) == visited.end()){
                      //front has its left child and is not visited
                      q.push(parentnodefront);
                      visited[parentnodefront] = true;
                  }
              }
          }
          vector<int> ans;
          while(!q.empty()){
              auto front = q.front();
              q.pop();
              ans.push_back(front->val);
          }
          return ans;
      }
  };
  int main()
  {
    return 0;
  }