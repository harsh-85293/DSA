//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int solve(Node *node){
        if(node == NULL){
            return 0;
        }
        
        if(node->left == NULL && node->right == NULL){
            int temp = node->data;
            node->data = 0;
            return temp;
        }
        
        int lsum = solve(node->left);
        int rsum = solve(node->right);
        int temp = node->data;
        node->data = lsum + rsum;
        return node->data + temp;
    }
    
    void toSumTree(Node *node)
    {
        // Your code here
        solve(node);
        
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        ob.toSumTree(root);
        inorder(root);
        cout<<endl;
    
cout << "~" << "\n";
}
    return 1;
}
// } Driver Code Ends