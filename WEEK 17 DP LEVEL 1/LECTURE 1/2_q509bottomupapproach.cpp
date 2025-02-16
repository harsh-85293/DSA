class Solution {
    public:
        int solveusingTabulation(int n){
            //step1:crete dp array
            vector<int>dp(n+1, -1);
    
            //step2:analyze base cases and update the answer
            dp[0] = 0;
            if(n == 0){//for 1 size array dp[1] will not be there so code will not be compiled
                return 0;
            }
            dp[1] = 1;
    
            //step3: check parameter and reverse it and run a loop
            //recursion -> n to 0
            //reverse -> 0 to n
            for(int i = 2; i <= n;i++){
                //copy paste
                dp[i] = dp[i-1] +  dp[i-2];
            }
            //answer return 
            return dp[n];
        }
    
        int fib(int n) {
            // int ans = solveusingrecursion(n);
            // return ans;
    
            //step 1 : create DP array and pass it in function
            //vector<int>dp(n+1, -1);
            return solveusingTabulation(n);
        }
    };