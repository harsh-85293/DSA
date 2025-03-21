class Solution {
    public:
        int numbersquarehelper(int n, vector<int>&dp)
        {
            if(n == 0) return 1;
            if(n < 0) return 0;
    
            if(dp[n] != -1){
                return dp[n];
            }
    
            int ans = INT_MAX;
            int i = 1;
            int end = sqrt(n);
    
            while(i <= end)
            {
                int perfectsquare = i * i;
                int numberofperfectsquares = 1 + numbersquarehelper(n - perfectsquare, dp);
                
                if(numberofperfectsquares < ans)
                {
                    ans = numberofperfectsquares;
                    dp[n] = ans;
                }
                i++;
            }
            return dp[n];
        }
    
        int numSquares(int n) 
        {
            vector<int>dp(n + 1, -1);
            return numbersquarehelper(n, dp) - 1;
        }
    };

    //Error:

    // while (i <= end) {
    //     int perfectsquare = i * i;
    //     int numberofperfectsquares = 1 + numbersquarehelper(n - perfectsquare, dp);
        
    //     ans = min(ans, numberofperfectsquares); // Ensure ans gets updated
    //     dp[n] = ans; // Store the correct minimum value in dp[n]
    
    //     i++;
    // }
    