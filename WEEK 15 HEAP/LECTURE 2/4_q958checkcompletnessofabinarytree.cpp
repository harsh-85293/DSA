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
        bool solve(TreeNode* root){
            queue<TreeNode*>q;
            q.push(root);
            bool nullfound  = false;

            while(!q.empty()){
                TreeNode* front = q.front();
                q.pop();

                if(front == NULL){
                    nullfound = true;
                }
                else{
                    //front ek valid node hai
                    if(nullfound == true){
                        //not a cbt
                        return false;
                    }
                    else{
                        //maybe a cbt
                        q.push(front->left);
                        q.push(front->right);
                    }
                }
            }
            return true;
        }

        bool isCompleteTree(TreeNode* root) {
            bool ans = solve(root);
            return ans;
        }
    };
   int main()
   {
     return 0;
   }
