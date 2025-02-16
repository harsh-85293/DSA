class Solution 
{
public:
    int solveusingspaceoptimization(vector<int>& nums){
        int n = nums.size();

        int next1 = 0;
        int next2 = 0;
        for(int i = n - 1; i >= 0; i--){
            //include
            int includeans = nums[i] + next2;
            //exclude
            int excludeans = 0 + next1;
            int curr = max(includeans, excludeans);

            //shifting ->forgetting part
            next2 = next1;
            next1 = curr;
        }
        return next1;
    }
    //1D dp
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        //step 1 create and pass dp array
        //vector<int>dp(n + 1, -1);
        int i = 0;
        // int ans = solve(nums, n, i, dp);
        int ans = solveusingspaceoptimization(nums);
        return ans;
    }
};