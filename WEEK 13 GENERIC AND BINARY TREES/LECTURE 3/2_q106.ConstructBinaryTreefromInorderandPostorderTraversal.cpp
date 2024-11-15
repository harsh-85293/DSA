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
        void createmapping(unordered_map<int, int>&valuetoindex, vector<int>& inorder){
            for(int i=0; i<inorder.size(); i++){
                int element = inorder[i];
                int index = i;
                valuetoindex[element] = index;
            }
        }
        TreeNode* constructtree(unordered_map<int, int> &valmap,vector<int>& postorder, vector<int>&inorder,
        int &postindex, int inorderstart, int inorderend, int size)
        {
            //base cases
            if(postindex < 0){
                return NULL;
            }
            if(inorderstart > inorderend){
                return NULL;
            }

            int element = postorder[postindex];
            postindex--;
            TreeNode* root = new TreeNode(element);
            int index = valmap[element];

            //right call
            root->right = constructtree(valmap, postorder, inorder, postindex, index + 1, inorderend, size);
            //left call
            root->left = constructtree(valmap, postorder, inorder, postindex, inorderstart, index-1, size);
            
            return root;
        }
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            int postindex = postorder.size()-1;
            int inorderstart = 0;
            int inorderend = inorder.size()-1;
            unordered_map<int, int>valmap;
            int size = inorder.size();
            createmapping(valmap, inorder);
            TreeNode* root = constructtree(valmap, postorder, inorder, postindex, inorderstart, inorderend, size);
            return root;
        }
    };
  int main()
  {
      return 0;
  }