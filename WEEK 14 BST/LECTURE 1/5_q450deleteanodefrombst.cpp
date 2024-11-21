  #include <bits/stdc++.h>
  using namespace std;
    
     
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
     
    class Solution {
    public:

        int getmax(TreeNode* root){

        if(!root){
            return -1;
        }   
        while(root->right){
            root = root->right;
        }
        //iska matlab jab mai yaha pahuchunga tab root extreme right par khada hoga
        //aur wohi mera answer hai
        return root->val;
        }

        TreeNode* deleteNode(TreeNode* root, int key) {
            if(!root){
                return NULL;
            }
            //match
            if(root->val == key){
                //now i have to delete node

                //4 cases:

                //1st case : with 0 child
                if(!root->left && !root->right){
                    delete root;
                    return NULL;
                }
                //2nd case : with left child
                if(root->left && !root->right){
                    TreeNode* leftchild = root->left;
                    root->left = NULL;
                    delete root;
                    return leftchild;
                }
                //3rd case : with right child
                if(!root->left && root->right){
                    TreeNode* rightchild = root->right;
                    root->right = NULL;
                    delete root;
                    return rightchild;
                }
                //4th case : with both left and right child
                //just chota elkement nikala
                int maxval = getmax(root->left);
                //replace root with maxval
                root->val = maxval;
                //delete actual node of maxval
                root->left = deleteNode(root->left, maxval);
                return root;
            }

            //not match
            else{
                //left ya right jaao
                if(key < root->val){
                    root->left = deleteNode(root->left, key);
                }

                else{
                    root->right = deleteNode(root->right, key);
                }
            }
            return root;
        }
    };
  int main()
  {
    return 0;
  }