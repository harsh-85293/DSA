//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

class Solution 
{
  public:
    void leftboundary(Node *root, vector<int> &ans)
    {
        if(root == NULL){
            return ;
        }
        
        if(root->left == NULL && root->right == NULL){
            return ;
        }
        
        ans.push_back(root->data);
        
        if(root->left!=NULL){
            leftboundary(root->left, ans);
        }
        
        else{
            leftboundary(root->right, ans);
        }
        
    }
    
    void leafboundary(Node *root, vector<int> &ans)
    {
        if(root == NULL){
            return ;
        }
        
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
        }
        
        leafboundary(root->left, ans);
        leafboundary(root->right, ans);
    }
    void reverserightboundary(Node *root, vector<int> &ans)
    {
         if(root == NULL){
            return ;
        }
        
        if(root->left == NULL && root->right == NULL){
            return ;
        }
        
        if(root->right!=NULL){
            reverserightboundary(root->right, ans);
        }
        
        else{
            reverserightboundary(root->left, ans);
        }
        
        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) 
    {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        //A -> root node
        ans.push_back(root->data);
        //B -> left subtree -> left boundary
        leftboundary(root->left, ans);
        //C -> left subtree -> leaf boundary
        leafboundary(root->left, ans);
        //D ->right subtree -> leaf boundary
        leafboundary(root->right, ans);
        //E ->right subtree -> right boundary
        reverserightboundary(root->right, ans);
        
        return ans;
        
    }
};
