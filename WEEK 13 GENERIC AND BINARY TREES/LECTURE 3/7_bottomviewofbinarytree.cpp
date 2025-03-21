//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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


vector <int> bottomView(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
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
            
            distmap[hd] = frontnode;
        
            
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
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}



// } Driver Code Ends