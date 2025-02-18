class Solution 
{
public:
    int solve(vector<int> &coins, int amount)
    {
        //base  case
        if(amount == 0)
        {
            return 0;
        }
        int mincoins = INT_MAX;
        //har amount ke liye  poore coins ke array ko traverse karenge
        for(int i = 0; i < coins.size(); i++)
        {
            int amt = amount;
            int coin = coins[i];

            //if coin value > amount value,no need to call recursive function
            if(coin <= amount)
            {
                int coin =  coins[i];
                //1 coin use ho gaya ,amoount becomes amount-coins
                //baki recursion sambhal lega
                int recursionkaans = solve(coins, amount - coin);

                //for invalid case->NT_MAX is the answer
                //valid case ->recursionans not equal to INT_MAX
                if(recursionkaans != INT_MAX)
                {
                    //valid answer
                    int coinsused = 1 + recursionkaans;
                    mincoins = min(mincoins, coinsused);
                }
            }
        }
        return mincoins;
    }//1-d dp

    int solveusingmem(vector<int> &coins, int amount, vector<int> &dp){
        //base  case
        if(amount == 0)
        {
            return 0;
        }

        if(dp[amount] != -1){
            return dp[amount];
        }
        
        int mincoins = INT_MAX;
        //har amount ke liye  poore coins ke array ko traverse karenge
        for(int i = 0; i < coins.size(); i++)
        {
            int coin = coins[i];

            //if coin value > amount value,no need to call recursive function
            if(coin <= amount)
            {
                int coin =  coins[i];
                //1 coin use ho gaya ,amoount becomes amount-coins
                //baki recursion sambhal lega
                int recursionkaans = solveusingmem(coins, amount - coin, dp);

                //for invalid case->NT_MAX is the answer
                //valid case ->recursionans not equal to INT_MAX
                if(recursionkaans != INT_MAX)
                {
                    //valid answer
                    int coinsused = 1 + recursionkaans;
                    mincoins = min(mincoins, coinsused);
                }
            }
        }
        //step2 : dp me answer store and return
        dp[amount] = mincoins;
        return dp[amount];
    }

    int solveusingtab(vector<int>& coins, int amount){
        vector<int>dp(amount + 1, -1);
        
        dp[0] = 0;

        for(int amt = 1; amt <= amount; amt++){
            int mincoins = INT_MAX;
            //har amount ke liye  poore coins ke array ko traverse karenge
            for(int i = 0; i < coins.size(); i++)
            {
                int coin = coins[i];

                //if coin value > amount value,no need to call recursive function
                if(coin <= amt)
                {
                    int coin =  coins[i];
                    //1 coin use ho gaya ,amoount becomes amount-coins
                    //baki recursion sambhal lega
                    int recursionkaans = dp[amt - coin];

                    //for invalid case->NT_MAX is the answer
                    //valid case ->recursionans not equal to INT_MAX
                    if(recursionkaans != INT_MAX)
                    {
                        //valid answer
                        int coinsused = 1 + recursionkaans;
                        mincoins = min(mincoins, coinsused);
                    }
                }
            }
            //step2 : dp me answer store and return
            dp[amt ] = mincoins;
    }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        // int ans = solve(coins, amount);
        
        // return ans;
        vector<int>dp(amount + 1, -1);
        // int ans = solveusingmem(coins, amount, dp);
        // if(ans == INT_MAX)
        // {
        //     return -1;
        // }
        // return ans;
        int ans = solveusingtab(coins, amount);
        if(ans == INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};