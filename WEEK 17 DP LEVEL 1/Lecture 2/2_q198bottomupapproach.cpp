class Solution 
{
public:
    int solveusingtabulation(vector<int> &nums){
        int n = nums.size();
        vector<int>dp(n + 20, 0);
        
        for(int i = n - 1; i >= 0; i--){
            //include
            int includeans = nums[i] + dp[i + 2];
            //exclude
            int excludeans = 0 + dp[i + 1];
            dp[i] = max(includeans, excludeans);
        }
        return dp[0];
    }
    
    //1D dp
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        int i = 0;
        // int ans = solve(nums, n, i, dp);
        int ans = solveusingtabulation(nums);
        return ans;
    }
};