class Solution {
public:
    string decodeString(string s) {     
        stack<string> st;      
        for (auto ch : s) {
            if (ch == ']') {
                // Step 1: Retrieve string to repeat
                string stringtorepeat = "";
                while (!st.empty() && st.top() != "[") {
                    string top = st.top();
                    stringtorepeat = top + stringtorepeat;  // Prepend to maintain order
                    st.pop();
                }

                // Pop the '[' from the stack
                if (!st.empty() && st.top() == "[") {
                    st.pop();
                }

                // Step 2: Retrieve the number (k) for repetition
                string numericstring = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    numericstring = st.top() + numericstring;  // Prepend to maintain order
                    st.pop();
                }
                int n = stoi(numericstring);  // Convert numeric string to integer

                // Step 3: Repeat the string 'n' times
                string currentdecode = "";
                while (n--) {
                    currentdecode += stringtorepeat;
                }

                // Push the decoded string back to stack
                st.push(currentdecode);
            }
            else {
                // Convert the character to string and push to stack
                string temp(1, ch);
                st.push(temp);
            }
        } 

        // Step 4: Build the final result string from stack
        string ans;
        while (!st.empty()) {
            ans = st.top() + ans;  // Prepend to maintain order
            st.pop();
        }

        return ans;
    }
};