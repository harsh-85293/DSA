    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        string s="c1 O$d@eeD o1c";
        string s1;

        for (int i = 0; i < s.length(); i++) 
        {
        if (isalpha(s[i]) || isdigit(s[i])) 
        {
            s1.push_back(s[i]);
        }
        }

        transform(s1.begin(),s1.end(),s1.begin(),::tolower);
        cout << s1 << endl;
        bool ans=true;//maan liya ki palindrome hai
        int i=0;
        int n=s1.length();
        int j=n-1;

        while(i<j)
        {
            if (s1[i] != s1[j]) 
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
        cout << ans;
        return 0;
    }
