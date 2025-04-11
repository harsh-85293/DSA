class Solution {
    public:
        int solve(int i, int buy, vector<int>& prices, int limit){
            if(i == prices.size() || limit == 0){
                return 0;
            }
    
            int profit = 0;
            if(buy){
                profit = max((-prices[i] + solve(i + 1, 0, prices, limit)), (0 + solve(i + 1, 1, prices, limit)));
            }
            else{
                profit = max((prices[i] + solve(i + 1, 1, prices, limit - 1)), (0 + solve(i + 1, 0, prices, limit)));
            }
            return profit;
        }
        int solveusingmemo(int i, int buy, vector<int>& prices, vector<vector<vector<int>>> &dp, int limit){
            if(i == prices.size() || limit == 0){
                return 0;
            }
    
            if(dp[i][buy][limit] != -1){
                return dp[i][buy][limit];
            }
    
            int profit = 0;
            if(buy){
                profit = max((-prices[i] + solveusingmemo(i + 1, 0, prices, dp, limit)), (0 + solveusingmemo(i + 1, 1, prices, dp, limit)));
            }
            else{
                profit = max((prices[i] + solveusingmemo(i + 1, 1, prices, dp, limit - 1)), (0 + solveusingmemo(i + 1, 0, prices, dp, limit)));
            }
            return dp[i][buy][limit] = profit;
        }
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
            return solveusingmemo(0, 1, prices, dp, 2);
        }
    };