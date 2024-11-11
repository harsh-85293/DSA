    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        string s="abcddefg";
        char p='d';
        int n=s.length();
        int j=n-1;
        int ans=-1;
        while(j>=0)
        {
            if(s[j]==p)
            {
                ans=j;
                break;
            }
            j--;
        }
        cout <<  ans;
        return 0;
    }