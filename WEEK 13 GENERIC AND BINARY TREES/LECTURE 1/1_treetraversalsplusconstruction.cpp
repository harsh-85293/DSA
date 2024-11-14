	#include <bits/stdc++.h>
	using namespace std;
    
    class Node
    {
        public:
            int data;
            Node* left;
            Node* right;  

            Node(int value)
            {
                this -> data = value;
                left = NULL;
                right = NULL;
            }
    };

    Node* createtree()
    {
        cout << "enter the value for Node:" << endl;
        int value;
        cin >> value;

        if(value == -1)
        {
            return NULL;
        }

        else
        {
            //valid value
            Node * root = new Node(value);

            //1 case maine kar liya , baaki left and right recursion dekh lega
            cout << "adding left child for " << value  << endl;
            root -> left = createtree();

            cout << "adding right child for " << value  << endl;
            root -> right = createtree();
            return root;
        }
    }

    void preordertraversal(Node* root)
    {
        if(root == NULL)
        {
            return ;
        }

        //NLR
        //N
        cout << root->data << endl;
        //L
        preordertraversal(root->left);
        //R
        preordertraversal(root->right);
    }

    void inordertraversal(Node* root)
    {
        if(root == NULL)
        {
            return ;
        }

        //LNR
        //L
        inordertraversal(root->left);
        //N
        cout << root->data << endl;
        //R
        inordertraversal(root->right);
    }

    void postordertraversal(Node* root)
    {
        if(root == NULL)
        {
            return ;
        }

        //LRN
        //L
        postordertraversal(root->left);
        //R
        postordertraversal(root->right);
        //N
        cout << root->data << endl;
    }

    void levelordertraversal(Node* root){
        if(root == NULL){
            return;
        }
        queue<Node*>q;
        //initial state maintain
        q.push(root);
        q.push(NULL);

        //logic -> step A B C
        while(!q.empty()){
            Node* front  = q.front();

            if(front == NULL){
                //iska matlab purana level complete ho gaya hai
                cout << endl;
                if(!q.empty()){
                    q.push(NULL); 
                }
            }

            else{
                q.pop(); 

                //print karo
                cout << front->data << " ";

                //iske bacche khao->matlab queue me insert karo
                if(front->left != NULL){
                    q.push(front->left);
                }
                if(front->right != NULL){
                    q.push(front->right);
                }
            }
        }
    }

	int main()
	{
       Node* root;
       root = createtree(); 
       cout << "printing root:" << root -> data << endl;
	   return 0;
	} 