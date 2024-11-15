//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}



// } Driver Code Ends
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        queue<pair<Node*, int>>q;
        //to maintain initial state
        q.push(make_pair(root, 0));
        
        unordered_map<int, Node*>distmap;
        int mindist = INT_MAX;
        int maxdist = INT_MIN;
        
        //rule->left(-1), rightr(+1) in distance
        
        while(!q.empty()){
            
            pair<Node*,int> frontpair = q.front();
            q.pop();
            
            Node* frontnode = frontpair.first;
            int hd = frontpair.second;
            mindist = min(mindist,  hd);
            maxdist = max(maxdist, hd);
            
            if(distmap.find(hd) == distmap.end()){
                //is distance ke liye ab tak koi node insert nahi hui hai
                distmap[hd] = frontnode;
            }
            
            //left child check
            if(frontnode->left != NULL){
                q.push(make_pair(frontnode->left, hd-1));
            }
            //right child check
            if(frontnode->right != NULL){
                q.push(make_pair(frontnode->right, hd+1));
            }
        }
        
        vector<int> ans;
        for(int i = mindist; i <= maxdist; i++){
             Node* temp = distmap[i];
             ans.push_back(temp->data);
        }
        return ans;
    }

};



//{ Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends