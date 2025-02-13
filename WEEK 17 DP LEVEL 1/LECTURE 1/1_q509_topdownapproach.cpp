class Solution {
    public:
        int solveusingrecursion(int n){
            //2 base cases
            if(n == 0){
                return 0;
            }
    
            if( n == 1){
                return 1;
            }
            int ans = solveusingrecursion(n-1) +  solveusingrecursion (n-2);
            return ans;
        }
        //1-D DP solution -> 1D DP array -> n to 0
        int solveusingmem(int n, vector<int>&dp){
            //2 base cases
            if(n == 0){
                return 0;
            }
    
            if( n == 1){
                return 1;
            }
    
            //step 3 : base case ke baad , check if ans already exist or not 
            if(dp[n] != -1){
                return dp[n];
            }
    
            //step 2 : dp array mai ans store karo and return karo
            dp[n] = solveusingmem(n-1, dp) +  solveusingmem(n-2, dp);
            return dp[n];
        }
    
        int fib(int n) {
            // int ans = solveusingrecursion(n);
            // return ans;
    
            //step 1 : create DP array and pass it in function
            vector<int>dp(n+1, -1);//any number of blocks can be taken
            return solveusingmem(n, dp);
        }
    };