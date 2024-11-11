    #include <bits/stdc++.h>
    using namespace std;
    bool ispalindrome(string s)
    {
        int n=s.length();
        int i=0;
        int j=n-1;
        bool ans=true;
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                ans=false;
                break;
            }
            else
            {
                i++;
                j--;
            }
        }
        return ans;
    }
    int main() {
    string s = "babad";
    string ans = "";
    
    for (int i = 0; i < s.length(); i++) 
    {
        for (int len = 1; len <= s.length() - i; len++) 
        {
            string curr = s.substr(i, len);
            if (ispalindrome(curr)) 
            {
                if (curr.length() > ans.length()) 
                {
                    ans = curr;
                }
            }
        }
    }

    cout << ans;

    return 0;
}