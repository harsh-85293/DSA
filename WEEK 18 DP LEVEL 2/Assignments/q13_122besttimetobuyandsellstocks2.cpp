class Solution {
    public:
        int solve(int i, int buy, vector<int>& prices){
            if(i == prices.size()){
                return 0;
            }
    
            int profit = 0;
            if(buy){
                profit = max((-prices[i] + solve(i + 1, 0, prices)), (0 + solve(i + 1, 1, prices)));
            }
            else{
                profit = max((prices[i] + solve(i + 1, 1, prices)), (0 + solve(i + 1, 0, prices)));
            }
            return profit;
        }
    
        int solveusingmemo(int i, int buy, vector<int>& prices, vector<vector<int>>&dp){
            if(i == prices.size()){
                return 0;
            }
    
            if(dp[i][buy] != -1){
                return dp[i][buy];
            }
    
            int profit = 0;
            if(buy){
                profit = max((-prices[i] + solveusingmemo(i + 1, 0, prices, dp)), (0 + solveusingmemo(i + 1, 1, prices, dp)));
            }
            else{
                profit = max((prices[i] + solveusingmemo(i + 1, 1, prices, dp)), (0 + solveusingmemo(i + 1, 0, prices, dp)));
            }
            return dp[i][buy] = profit;
        }
    
        int maxProfit(vector<int>& prices) {
            //return solve(0, 1, prices);
            int n = prices.size();
            vector<vector<int>>dp(n + 1, vector<int>(2, -1));
            return solveusingmemo(0, 1, prices, dp);
        }
    };
    