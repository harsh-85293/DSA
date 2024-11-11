#include <bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    void addre(string &num1, string & num2, int p1, int p2, int carry, string &ans)
    {
        //base case:p1 is pointing to -1 and p2 is also pointing to -1
        //"11" "123"
        if(p1<0 && p2<0)
        {
            //if carry is not zero then push carry to answer
            if(carry!=0)
            {
                //typecast int to char
                ans.push_back(carry+'0');
            }
            return ;
        }
        //1 case solve karo
        int n1=(p1>=0 ? num1[p1] :'0')-'0';//-'0' to convert in int
        int n2=(p2>=0 ? num2[p2] :'0')-'0';

        int csum = n1 + n2 + carry;
        int digit = csum%10;
        carry = csum/10;
        ans.push_back(digit+'0');

        //baaki recursion sambhal lega
        addre(num1, num2, p1-1, p2-1, carry, ans);
    }
    string addStrings(string num1, string num2)
    {
        string ans="";
        addre(num1, num2, num1.size()-1, num2.size()-1, 0, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};