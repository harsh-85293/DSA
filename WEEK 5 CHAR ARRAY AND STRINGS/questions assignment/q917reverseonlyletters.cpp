    #include <bits/stdc++.h>
    using namespace std;
     string reverseOnlyLetters(string s) 
    {
        int n=s.length();
        int i=0;
        int j=n-1;
        
        while(i<j)
        {
            if(!isalpha(s[i]))
            {
                i++;
            }
            else if(!isalpha(s[j]))
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
        return s;    
    }
    int main()
    {
        string f=reverseOnlyLetters("a-bC-dEf-ghIj");
        cout << f;
        return 0;
    }
    