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

	int main()
	{
       Node* root;
       root = createtree(); 
       cout << "printing root:" << root -> data << endl;
	   return 0;
	} 