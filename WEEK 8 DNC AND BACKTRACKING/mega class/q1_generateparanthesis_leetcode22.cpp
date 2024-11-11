    #include <bits/stdc++.h>
    using namespace std;

    class Solution 
    {
    public:

        void solve(vector<string>&ans, string &out, int open, int close,int n)
        {
            //base case 
            if(open +close==2*n)
            {
                ans.push_back(out);
                return;
            }

            //open bracket ko exhaust karne ke baad backtrack karenge
            if(open<n)
            {
                out.push_back('(');
                solve(ans,out,open+1,close,n);
                out.pop_back();//backtracking
            }

            //valid paranthesis ke liye
            if(close<open)
            {
                out.push_back(')');
                solve(ans,out,open,close+1,n);
                out.pop_back();//backtracking
            }

        }

        vector<string> generateParenthesis(int n) 
        {
            vector<string>ans;
            string out;
            solve(ans,out,0,0,n);
            for(auto it:ans)
            {
                cout << it << " ";
            }
            return ans;
        }
    };
    int main()
    {
        Solution S;
        S.generateParenthesis(2);
        
        return 0;
    } 