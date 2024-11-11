    #include <bits/stdc++.h>
    using namespace std;
    
    bool isvowel(char ch)
    {
        ch=tolower(ch);
        if( ch== 'a' || ch== 'e' || ch=='i' || ch=='o' || ch=='u')
        {
            return true;
        } 
        else
        {
            return false;
        }
    }

    int main()
    {
        string s="hello";
        int n=s.length();
        int i=0;
        int j=n-1;

        while(i<j)
        {
            if( isvowel( s[i] )==false )
            {
                i++;
            }
            else if( isvowel( s[j] ) ==false )
            {
                j--;
            }
            else
            {
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        cout << s;
        return 0;
    }
   