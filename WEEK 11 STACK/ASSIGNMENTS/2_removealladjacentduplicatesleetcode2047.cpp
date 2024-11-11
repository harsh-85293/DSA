//method 1
class Solution 
{
public:
    string removeDuplicates(string s) 
    {
        string ans="";
        int n=s.length();

        for(int i=0;i<n;i++)
        {
            char charcurrent=s[i];

            if(ans.empty()==1)
            {
                ans.push_back(charcurrent);
            }
            else if(charcurrent==ans.back())
            {
                ans.pop_back();
            }
            else
            {
                ans.push_back(charcurrent);
            }
        }
        return ans;
    }
};

//method 2:using stack
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        st.push(s[0]);
        for(int i=1; i<s.length(); i++)
        {
            char ch=s[i];
            if(!st.empty() && ch==st.top())
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
        string ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};