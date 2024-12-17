   #include <bits/stdc++.h>
   using namespace std;

   

    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int>mp;
        
            for(int i = 0; i < nums.size(); i++){
                int curr = nums[i];
                int required = target - curr;
                if(mp.find(required) != mp.end()){
                    return {i, mp[required]};
                }

                mp[curr] = i;
            }
            return {-1, -1};
        }
    };

    int main()
   {
     return 0;
   }