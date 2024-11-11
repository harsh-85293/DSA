class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.length()) {
            return "0";
        }
        stack<char> st;

        for(int i = 0; i < num.size(); i++) {
            char ch = num[i];

            while(k > 0 && !st.empty() && st.top() > ch) {
                st.pop();
                k--;
            }

            st.push(ch);
        }

        // Pop remaining elements if k > 0
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        // Remove leading zeroes
        while(ans.size() > 0 && ans.back() == '0') {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());

        return ans.empty() ? "0" : ans;
    }
};
