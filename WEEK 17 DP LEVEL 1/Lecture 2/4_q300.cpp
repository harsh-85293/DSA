class Solution {
    public:
        int solveMem(vector<int>& nums, int lastindex, int i, vector<vector<int>>&dp){
            //base case 
            if(i >= nums.size()){
                return 0;
            }
            //step 3 : check if answer already exists
            if(dp[lastindex + 1][i] != -1){
                return dp[lastindex + 1][i];
            }
    
            //1 case mera baaaki recursion sambhal lega
            //include tabhi kar sakte ho jab current element last element se bada hoga
            int curr =  nums[i];
            int inc  = 0;
            //include 
            if(lastindex == -1 || curr > nums[lastindex]){
                inc = 1 + solveMem(nums, i, i + 1, dp);
            }
            //exclude
            int exc = 0 + solveMem(nums, lastindex, i + 1, dp);
    
            //step 2: store and return in dp array
            dp[lastindex + 1][i] = max(inc, exc);
            return dp[lastindex + 1][i];
        }// 2d dp
    
        int solveusingtab(vector<int>& nums){
            int n = nums.size();
            //step 1 : create dp array
            vector<vector<int>>dp(n + 3, vector<int>(n + 1, -1));
    
            //step 2: base case analyze
            for(int row = 0; row < n+ 3; row++){
                dp[row][n] = 0;
            }
    
            //step 3 : find range, loop and copy paste
            for(int lastindex = n + 1; lastindex >= 0; lastindex--){
                for(int i = n - 1; i >= 0; i--){
                    //logic
                    int curr =  nums[i];
                    int inc  = 0;
                    //include ff
                    if(lastindex == -1 || (lastindex < n && curr > nums[lastindex]) ){
                        inc = 1 + dp[i][i + 1];
                    }
                    //exclude
                    int exc = 0 + dp[lastindex][i + 1];
    
                    //step 2: store and return in dp array
                    dp[lastindex + 1][i] = max(inc, exc);
                    dp[lastindex + 1][i] = dp[lastindex + 1][i];
                }
            }
            return dp[0][0];
        }
        
        int lengthOfLIS(vector<int>& nums) {
            int lastindex = -1;
             int i = 0;
            // return solve(nums, lastindex, i);
            //create and pass 2d dp
            int n = nums.size();
            vector<vector<int>>dp(n + 2, vector<int>(n + 1, -1));
            // 2d array n+1 * n+1 size initialized with value -1
            //return solveMem(nums, lastindex, i, dp);
    
            return solveusingtab(nums);
        }
    };