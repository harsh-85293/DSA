  #include <bits/stdc++.h>
  using namespace std;
  
  // Structure for tree and linked list
  struct Node
  {
      int data;
      struct Node* left;
      struct Node* right;

      Node(int x){
          data = x;
          left = right = NULL;
      }
  };


  // This function should return head to the DLL
  class Solution {
    public:
      void solve(Node* root, Node* &head){
          if(!root){
              return;
          }
          // RNL
          // R
          solve(root->right, head);
          // assume kar sakta hu right part ki ll ban gayi hogi
          // and head right part ki ll ke start node par hoga
          root->right = head;
          if(head){
              head->left = root;
          }
          // yaha tak aapki R ans N ki ll ban chuki hai
          // update head
          head = root;
          // ab tree ka left part pending hsi 
          // L
          solve(root->left, head);
      }
      
      Node* bToDLL(Node* root) {
          // code here
          Node* head = NULL;
          solve(root, head);
          return head;
      }
  };
