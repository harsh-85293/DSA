    #include <bits/stdc++.h>
    using namespace std;
    class Solution {
    public:

        void solve(vector<vector<int>>&ans, vector<int>curr, int k, int start, int n)
        {
            //base case
            if(k==0)
            {
                ans.push_back(curr);
                return;
            }

            for(int i=start;i<=n;i++)
            {
                curr.push_back(i);
                solve(ans, curr, k-1, i+1, n);
                curr.pop_back();//backtracking
            }
        }

        vector<vector<int>> combine(int n, int k) {
            vector<vector<int>>ans;
            vector<int>curr;
            solve(ans, curr, k, 1, n);

            for (const auto& row : ans) 
            {        // Loop through each row (a vector itself)
                for (const auto& elem : row) 
                {   // Loop through each element in the row
                    cout << elem << " ";         // Access element
                }
                cout << endl;
            }
            return ans;
        }
    };
    int main()
    {
        Solution S;
        S.combine(4,2);
        return 0;
    } 

    