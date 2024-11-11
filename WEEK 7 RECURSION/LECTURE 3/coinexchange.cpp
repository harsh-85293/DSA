#include <bits/stdc++.h>
class Solution 
{
public:
    int solve(vector<int> &coins,int amount)
    {
        //base  case
        if(amount==0)
        {
            return 0;
        }
        int mincoins=INT_MAX;
        //har amount ke liye  poore coins ke array ko traverse karenge
        for(int i=0;i<coins.size();i++)
        {
            int amt=amount;
            int coin=coins[i];

            //if coin value > amount value,no need to call recursive function
            if(coin<=amount)
            {
                int coin=coins[i];
                //1 coin use ho gaya ,amoount becomes amount-coins
                //baki recursion sambhal lega
                int recursionkaans=solve(coins,amount-coin);

                //for invalid case->NT_MAX is the answer
                //valid case ->recursionans not equal to INT_MAX
                if(recursionkaans!=INT_MAX)
                {
                    //valid answer
                    int coinsused=1+recursionkaans;
                    mincoins=min(mincoins,coinsused);
                }
            }
        }
        return mincoins;
    }

    int coinChange(vector<int>& coins, int amount) 
    {
        int ans=solve(coins,amount);
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};