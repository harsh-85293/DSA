  #include <bits/stdc++.h>
  using namespace std;
  //optimal approach
    class Solution {
    public:
        void solve(vector<int>&v, int n, int &ans, int currnum){
            if(currnum == n+1){
                for(auto it:v){
                  cout << it << endl;
                }
                ans++;
                return ;
            }

            for(int i = 1; i <= n; i++)
            {
                if( (v[i] == 0) && ( (currnum % i == 0) || (i % currnum == 0) ) )
                {
                    v[i] = currnum;
                    solve(v, n, ans, currnum+1);
                    v[i] = 0;///backtracking=== restoring
                }
            }
        }
        int countArrangement(int n) {
            vector<int>v(n+1);
            int ans = 0;
            solve(v, n, ans, 1);
            return ans;   
        }
    };
  int main()
  {
      Solution S;
      S.countArrangement(5);
      return 0;
  }