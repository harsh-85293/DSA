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
        TreeNode* solve(vector<int> &nums, int s, int e){
            if(s > e){
            return NULL;
            }

            //1 case mai kar deta hu
            int mid = s + (e-s)/2;
            int element = nums[mid];
            TreeNode* root  = new TreeNode(element);

            //baaki recursion sambhal lega
            root->left = solve(nums, s, mid-1);
            root->right = solve(nums, mid+1, e);
            return root;
        }   

        TreeNode* sortedArrayToBST(vector<int>& nums) {
            int s = 0;
            int n = nums.size();
            int e = n - 1;
            TreeNode* root = solve(nums, s, e);
            return root;
        }
    };
  int main()
  {
    return 0;
  }