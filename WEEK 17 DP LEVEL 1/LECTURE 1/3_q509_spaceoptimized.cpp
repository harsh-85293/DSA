class Solution {
    public:
        int solveusingTabulation_spaceoptimization(int n){
            //crete dp array
            // vector<int>dp(n+1, -1);
    
            //step2:analyze base cases and update the answer
            //dp[0] = 0;
            if(n == 0){
                return 0;
            }
    
            if( n == 1){
                return 1;
            }
            int prev = 0;
            // if(n == 0){//for 1 size array dp[1] will not be there so code will not be compiled
            //     return 0;
            // }
            //dp[1] = 1;
            int curr = 1;

            //step3: check parameter and reverse it and run a loop
            //recursion -> n to 0
            //reverse -> 0 to n
            for(int i = 2; i <= n;i++){
                int ans = curr + prev;
                prev = curr;
                curr = ans;
            }
            //answer return 
            return curr;        
        }
    
        int fib(int n) {
            // int ans = solveusingrecursion(n);
            // return ans;
    
            //step 1 : create DP array and pass it in function
            //vector<int>dp(n+1, -1);
            return solveusingTabulation_spaceoptimization(n);
        }
    };