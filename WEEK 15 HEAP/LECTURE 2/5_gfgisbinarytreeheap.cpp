   #include <bits/stdc++.h>
   using namespace std;
   
   struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
  };
    class Solution {
    public:   
      bool solve(Node* root){
              queue<Node*>q;
              q.push(root);
              bool nullfound  = false;

              while(!q.empty()){
                  Node* front = q.front();
                  q.pop();

                  if(front == NULL){
                      nullfound = true;
                      
                  }
                  else{
                      //front ek valid node hai
                      if(nullfound == true){
                          //not a cbt
                          return false;
                      }
                      else{
                          //maybe a cbt
                          q.push(front->left);
                          q.push(front->right);
                      }
                  }
              }
              return true;
          }
          
          bool checkmaxproperty(Node* root){
              if(!root ){
                  return true;
              }
              bool leftans = checkmaxproperty(root->left);
              bool rightans = checkmaxproperty(root->right);
              
              bool option1 = true;
              if(root->left && root->data < root->left->data){
                  option1 = false;
              }
              
              
              bool option2 = true;
              if(root->right && root->data < root->right->data){
                  option2 = false;
              }
              bool curr = option1 && option2;
              if(curr && leftans && rightans){
                  return true;
              }
              else{
                  return false;
              }
          }
          
          bool isHeap(struct Node* tree) {
              // code here 
              bool ans = solve(tree);
              bool ans2 = checkmaxproperty(tree);
              if(ans && ans2){
                  return true;
              }
              return false;
          }
  };
   int main()
   {
     return 0;
   }
