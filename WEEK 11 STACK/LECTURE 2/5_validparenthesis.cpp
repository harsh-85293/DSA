    //vvi question->q20 leetcode
    #include <bits/stdc++.h>
    using namespace std;
    
    bool isValid(string s) 
    {
        stack<char>st;
        for(int i=0; i<s.length(); i++)
        {
            char ch=s[i];

            //ch->either open bracket or a close bracket
            //open->sirf push karna hai
            //close->check same type ka open hai ya nahi

            if(ch == '(' || ch == '[' || ch == '{')
            {
                st.push(ch);
            }
            else
            {
                //mujhe close bracket mila hai
                //close bracket ke case me dekhna hai ki
                //mujhe same type ka open bracket mila ya nahi
                if(ch==')' && !st.empty() && st.top()=='(')
                {
                    st.pop();
                }
                else if(ch==']' && !st.empty() && st.top()=='[')
                {
                    st.pop();
                }
                else if(ch=='}' && !st.empty() && st.top()=='{')
                {
                    st.pop();
                }
                else
                {
                    //bracket not match
                    return false;
                } 
            }
        
        }
        if(st.size()==0)
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
        string s="()[]{}";
        bool ans=isValid(s);
        ans==1 ? cout << "valid" : cout << "invalid" << endl;
        return 0;
    } 