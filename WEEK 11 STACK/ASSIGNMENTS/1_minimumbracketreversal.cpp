
int countRev (string s)
{
    // your code here
    if(s.size()%2!=0)
    {
        return -1;
    }
    stack<char> st;
    int ans = 0;
    for(int i=0; i<s.length(); i++)
    {
        char ch = s[i];
        
        if(ch == '{')
        {
            st.push(ch);
        }
        else 
        {
            if(!st.empty() && ch == '}' && st.top() == '{')
            {
                st.pop();
            
            }
            else
            {
                st.push(ch);
            }
        }
    }
    
    int count = st.size();
    if(count == 0)
    {
        return 0;
    }
    while(!st.empty())
    {
        char ch1 = st.top();
        st.pop();
        char ch2 = st.top();
        st.pop();
        if(ch1 == ch2)
        {
            ans+=1;
        }
        else
        {
            ans+=2;
        }
    }
    return ans;
   
}