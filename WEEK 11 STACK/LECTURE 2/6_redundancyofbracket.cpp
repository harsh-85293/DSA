    #include <bits/stdc++.h>
    using namespace std;
    stack<char>st;
    int checkRedundancy(string s) 
    {
        // code here
        int ans=0;
        for(int i=0; i<s.length(); i++)
        {
            char ch=s[i];
            if(ch == '(' || ch == '+' || ch == '*' || ch == '/' || ch == '-')
            {
                st.push(ch);
            }
            else
            {
                if( ch==')' && !st.empty() && (st.top()=='+' || st.top()=='-' || st.top()=='*' || st.top()=='/') )
                {
                    ans=1;
                    break;
                    st.pop();
                }
                else if(isalpha(ch))
                {
                    continue;
                }
            }
        }
        return ans;
    }
    int main()
    {
        string s="((a+b))";
        int ans=checkRedundancy(s);
        cout << ans << endl;
        return 0;
    } 