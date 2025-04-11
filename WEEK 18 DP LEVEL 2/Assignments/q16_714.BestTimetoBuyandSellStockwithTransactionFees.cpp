class Solution {
    public:
        int solve(int i, int buy, vector<int>& prices, int fee){
                if(i == prices.size()){
                    return 0;
                }
        
                int profit = 0;
                if(buy){
                    profit = max((-prices[i] + solve(i + 1, 0, prices, fee)), (0 + solve(i + 1, 1, prices, fee)));
                }
                else{
                    profit = max((prices[i] + solve(i + 1, 1, prices, fee) - fee), (0 + solve(i + 1, 0, prices, fee)));
                }
                return profit;
            }
        
            int solveusingmemo(int i, int buy, vector<int>& prices, vector<vector<int>>&dp, int fee){
                if(i == prices.size()){
                    return 0;
                }
        
                if(dp[i][buy] != -1){
                    return dp[i][buy];
                }
        
                int profit = 0;
                if(buy){
                    profit = max((-prices[i] + solveusingmemo(i + 1, 0, prices, dp, fee)), (0 + solveusingmemo(i + 1, 1, prices, dp, fee)));
                }
                else{
                    profit = max((prices[i] + solveusingmemo(i + 1, 1, prices, dp, fee) - fee), (0 + solveusingmemo(i + 1, 0, prices, dp, fee)));
                }
                return dp[i][buy] = profit;
            }
        int maxProfit(vector<int>& prices, int fee) {
            int n = prices.size();
            vector<vector<int>>dp(n + 1, vector<int>(2, -1));
            return solveusingmemo(0, 1, prices, dp, fee);
        }
    };