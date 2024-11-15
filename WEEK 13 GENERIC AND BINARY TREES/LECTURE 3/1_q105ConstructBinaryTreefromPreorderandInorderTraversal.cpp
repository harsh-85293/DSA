  #include <bits/stdc++.h>
  using namespace std;
    /**
     * Definition for a binary tree node.
     * struct TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     * };
     */
    class Solution {
    public:
        int getindexinorder(vector<int>& inorder, int target){
            int n = inorder.size();
            for(int i=0; i<n; i++){
                if(inorder[i] == target){
                    return i;
                }
            }
            return -1;
        }

        TreeNode* constructtree(vector<int>& preorder,vector<int>& inorder,int &preorderindex,int inorderstart, int inorderend, int size)    
        {
            if(preorderindex >= size){
                return NULL;
            }

            if(inorderstart > inorderend){
                return NULL;
            }

            // process the first element of preorder as root
            // step 1 : get element from preorder and create root node for it
            int element = preorder[preorderindex];
            preorderindex++;
            TreeNode* root = new TreeNode(element);
            
            // step 2 : find this element inside inorder and call for left and right
            int elementindexinorder = getindexinorder(inorder, element);

            //inorder ka left part : inorderstart se lekar elementindexinorder-1 tak
            //inorder ka right part : elementindexinorder + 1 se lekar inorderend
            root->left = constructtree(preorder, inorder, preorderindex, inorderstart, elementindexinorder-1, size);
            root->right = constructtree(preorder, inorder, preorderindex, elementindexinorder+1, inorderend, size);
            return root;
        }

        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            int preorderindex = 0;
            int inorderstart= 0;
            int inorderend = inorder.size() - 1;
            int size = inorder.size();
            TreeNode* root = constructtree(preorder, inorder, preorderindex, inorderstart, inorderend, size);
            return root;
        }
    };
  int main()
  {
    Solution S;
      return 0;
  }