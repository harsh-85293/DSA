class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int maxlen = 0;
        for(int i=0; i<s.length(); i++)
        {
            char ch = s[i];
            if(ch =='(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                //invalid case 
                if(st.empty())
                {
                    st.push(i);
                }
                int len  = i - st.top();
                maxlen = max(len, maxlen);
            }
        }
        return maxlen;
    }
};