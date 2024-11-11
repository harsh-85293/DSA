//q680 leetcode
class Solution {
public:

    bool checkPalindrome(string str,int s,int e)
    {
        int n=str.length();
       
        while(s<=e)
        {
            if(str[s]==str[e])
            {
                s++;
                e--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) 
    {
        int n=s.length();
        int i=0;
        int j=n-1;

        while(i<=j)
        {
            if(s[i]==s[j])
            {
                //same
                i++;
                j--;
            }
            else
            {
                //different
                //delete ith wala yaa delete jth wala
                bool ansone=checkPalindrome(s,i+1,j);//ith wala
                bool anstwo=checkPalindrome(s,i,j-1);//jth wala
                int finalans=ansone||anstwo;
                return finalans;
            }
        }
        return true;

    }
};