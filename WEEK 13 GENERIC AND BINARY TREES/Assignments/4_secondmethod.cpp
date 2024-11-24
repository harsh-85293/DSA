    #include <bits/stdc++.h>
    using namespace std;

    struct Node
    {
        int data;
        Node* left, * right;
    }; 


    vector<int> diagonal(Node *root)
    {
    // your code here
    vector<int> ans;
    if(!root){
        return ans;
    }
    
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        while(temp){
            ans.push_back(temp->data);
            if(temp->left){
                // baad me dekhna hai
                q.push(temp->left);
            }
            temp = temp->right;
        }
    }
    return ans;
    }


    int main()
    {
    return 0;
    }