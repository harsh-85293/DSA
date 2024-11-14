  #include <bits/stdc++.h>
  using namespace std;
  //TC = O(N!)
  class Solution 
  {
    public:
        void solve(vector<vector<int>>&ans, vector<int>& nums, int index){
            // 1 case mai sambhalunga
            
            if(index ==  nums.size()){
                ans.push_back(nums);
                return;
            }

            //baaki recursion sambhal lega
            for(int i = index; i < nums.size(); i++){
                if(i>index && nums[i] == nums[i-1]){
                    continue;
                } 
                swap(nums[i], nums[index]);
                solve(ans, nums, index + 1);
                swap(nums[i], nums[index]);
            }
        }

        vector<vector<int>> permuteUnique(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<vector<int>>ans;
            solve(ans, nums, 0);
            set<vector<int>>st;
            for(auto it:ans)
            {
                st.insert(it);
            }
            ans.clear();
            for(auto e:st)
            {
                ans.push_back(e);
            }
            for(auto it :ans)
            {
              cout << it << endl;
            }
            return ans;
        }
    };

    int main()
    {
      Solution S;
      vector<int> nums={1,2,3};
      S.permuteUnique(nums);
      return 0;
    }