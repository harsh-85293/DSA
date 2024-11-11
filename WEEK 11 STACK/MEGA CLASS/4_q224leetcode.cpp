//BASIC CALCULATOR
class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int result = 0;
        int sign = 1;
        int num = 0;

        for(char ch:s)
        {
            if(ch >= '0' && ch <= '9')
            {
                num = num*10 + (ch - '0');
            }
            else if(ch == '+')
            {
                result += sign * num;
                sign = 1;
                num = 0; 
            }
            else if(ch == '-')
            {
                result += sign * num;
                sign = -1;
                num = 0; 
            }
            else if(ch == '(')
            {
                //push the curr result and onto stack
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }
            else if(ch == ')')
            {
                result += sign * num;
                //pop the sign and then, result jo push hua tha
                int sign = st.top();
                st.pop();
                result *= sign;
                result += st.top();
                st.pop();
                num = 0;
            }
        }  
        result += sign*num;
        return result;   
    }
};