#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:

    void maxprofitfinder(vector<int>& prices,int index,int &minprice,int &maxprofit)
    {
        //base case
        if(index == prices.size()){
            return;
        }

        //sol for one case
        //minprice initially INT_MAX
        if(prices[index] < minprice){
            minprice = prices[index];
        }

        //calculate current profit
        int todayprofit = prices[index]-minprice;
        if(todayprofit > maxprofit){
            maxprofit = todayprofit;
        }

        //baaki recursion sambhal lega
        maxprofitfinder(prices,index+1,minprice,maxprofit);
    }
    int maxProfit(vector<int>& prices) 
    {
        int minprice=INT_MAX;
        int maxprofit=INT_MIN;
        maxprofitfinder(prices,0,minprice,maxprofit);
        return maxprofit;
    }
};