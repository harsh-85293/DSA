//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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


// } Driver Code Ends
/* A binary tree node

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
 */

class Solution {
  public:
    void solve(Node *root, int level, vector<int> &ans){
        if(root == NULL){
            return ;
        }
        
        if(level == ans.size()){
            ans.push_back(root->data);
        }
        
        solve(root->left, level+1, ans);
        solve(root->right, level+1, ans);
    }
    vector<int> leftView(Node *root) {
        
        // code here
          
        vector<int>ans;
        solve(root, 0, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> vec = ob.leftView(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends