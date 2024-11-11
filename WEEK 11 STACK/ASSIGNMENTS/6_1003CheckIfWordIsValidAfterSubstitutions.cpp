class Solution {
public:
    bool isValid(string s) {

        bool ans = false;
        stack<char>st;

        for(int i = 0; i < s.length(); i++)
        {
            char curr = s[i];
            
            if(!st.empty() && curr == 'c' && st.top() == 'b')
            {
                char g = st.top();
                st.pop();
                if(!st.empty() && st.top() == 'a')
                {
                    st.pop();
                }
                else
                {
                    st.push(g);
                }
            }
            else
            {
                st.push(curr);
            }
        }
        if(st.size() == 0)
        {
            ans = true;
        }
        return ans;
    }
};