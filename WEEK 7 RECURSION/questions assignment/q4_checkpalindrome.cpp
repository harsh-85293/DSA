    #include <bits/stdc++.h>
    using namespace std;
    
    void checkpalindrome(string s,int i,int j,bool &ans)
    {
        //base case
        //string;s starting character value equal nahi hai ending character value ke
        //to return false kar do
        if(s[i] != s[j])
        {
            ans=false;
            return ;
        }
        //termination condition
        //if starting >ending
        if(i > j)
        {
            return ;
        }

        //1 case solve mai karunga
        if(s[i]==s[j])
        {
            ans = true;
        }
        //baaki recursion sambhal lega
        checkpalindrome(s,i+1,j-1,ans);
    }
    
    int main()
    {
        string str = "harsh";
        int startingindex = 0;
        int endingindex = str.length()-1;

        bool ans = true;//maan liya ki palindrome hai

        checkpalindrome(str,startingindex,endingindex,ans);
        cout << ans;
        return 0;
    } 