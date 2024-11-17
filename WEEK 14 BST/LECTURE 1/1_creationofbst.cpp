#include <bits/stdc++.h>
  using namespace std;

  class Node{

    public:
        int data;
        Node* left;
        Node* right;

        Node(int value){
            this->data = value;
            left = NULL;
            right = NULL;
        }
    };

    //TC = 0(logn)
    Node* buildbst(int val, Node*root){

        if(!root){
            root  = new Node(val);
            return root;
        }

        else{
            if(val < root->data){
                //val->left subtree
                root->left = buildbst(val, root->left);
            }
            else{
                //val->right subtree
                root->right = buildbst(val, root->right);
            }
        }
        return root;
    }

    Node* createbst(){

        cout << "enter the value for node:" << endl;
        int val;
        cin >> val;
        Node* root = NULL;

        while(val != -1){
            root = buildbst(val, root);
            cout << "enter the value for node:" << endl;
            cin >> val;
        }
        return root;
    }

    int main(){
        Node* root = createbst();
        return 0;
    }