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

    void levelordertraversal(Node* root){

        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){

            Node* front = q.front();
            q.pop();
             
            if(!front){
                cout << endl;
                if(!q.empty()){
                    q.push(NULL);
                }
            }

            else{
                cout << front->data << " ";
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                q.push(front->right);
                }
            }
        }
    }

    void preordertraversal(Node* root){
        
        if(root == NULL){
            return;
        }

        cout << root -> data << " ";
        preordertraversal(root->left);
        preordertraversal(root->right);
    }

    void inordertraversal(Node* root){

        if(root == NULL){
            return;
        }

        inordertraversal(root->left);
        cout << root -> data << " ";
        inordertraversal(root->right);
    }

    void postordertraversal(Node* root){

        if(root == NULL){
            return;
        }

        postordertraversal(root->left);
        postordertraversal(root->right);
        cout << root -> data << " ";
    }

    int getmin(Node* root){

      if(!root){
        return -1;
      }   
      while(root->left){
        root = root->left;
      }
      //iska matlab jab mai yaha pahuchunga tab root extreme left par khada hoga
      //aur wohi mera answer hai
      return root->data;
    }

    int getmax(Node* root){

      if(!root){
        return -1;
      }   
      while(root->right){
        root = root->right;
      }
      //iska matlab jab mai yaha pahuchunga tab root extreme right par khada hoga
      //aur wohi mera answer hai
      return root->data;
    }

    int main(){
        Node* root = createbst();

        cout << "printing level order traversal:" << endl;
        levelordertraversal(root);
        
        cout << endl << "printing preorder traversal:" << endl;
        preordertraversal(root);
        
        cout << endl << "printing inorder traversal:" << endl;
        inordertraversal(root);
        //NOTE: INORDER OF BST GIVES A SORTED ARRAY

        cout << endl << "printing post order traversal:" << endl;
        postordertraversal(root);cout << endl;
        
        cout << "MIN element:" << getmin(root) << endl;
        cout << "MAX element:" << getmax(root) << endl;
        return 0;
    }