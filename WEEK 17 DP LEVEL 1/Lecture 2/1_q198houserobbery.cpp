   #include <bits/stdc++.h>
   //using top down approach
    class Solution 
    {
    public:
    int solveusingrecursion(vector<int> &nums, int n, int i)
    {
        //base case
        if(i >= n)
        {
            return 0;
        }
        //include
        int includeans = nums[i] + solveusingrecursion(nums, n, i+ 2);
        //exclude
        int excludeans = 0 + solveusingrecursion(nums, n, i+1);

        int finalans = max(includeans, excludeans);

        return finalans;
    }
    int solve(vector<int> &nums, int n, int i, vector<int>&dp)
    {
        //base case
        if(i >= n)
        {
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }
        
        //include
        int includeans = nums[i] + solve(nums, n, i + 2, dp);
        //exclude
        int excludeans = 0 + solve(nums, n, i + 1, dp);

        dp[i] = max(includeans, excludeans);

        return dp[i];
    }

    //1D dp
    int rob(vector<int>& nums) 
    { 
        int n = nums.size();
        vector<int>dp(n + 1, -1);
        int i = 0;
        int ans = solve(nums, n, i, dp);
        return ans;
    }
    };