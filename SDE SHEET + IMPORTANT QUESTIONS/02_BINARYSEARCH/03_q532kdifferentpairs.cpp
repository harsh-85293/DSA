class Solution {
    public:
        int brute(vector<int>& nums, int k){
            sort(nums.begin(), nums.end());
            int n = nums.size();
            int ans = 0;
            set<pair<int, int>>st;
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    if(nums[j] - nums[i] == k){
                        vector<pair<int, int> >temp;
                        temp.push_back( { nums[i], nums[j] } );
                        st.insert(temp.begin(), temp.end());
                    }
                }
            }
            return st.size();
        }
        // nums[j] == nums[i] + k  →  (nums[j] - nums[i] == k) 
        int optimalusingbs(vector<int>&nums, int start, int x){
            int end = nums.size() - 1;
            while (start <= end)
            {
                int mid = (start + end) / 2;
                if (nums[mid] == x)
                {
                    return mid;
                }
                else if (x > nums[mid])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            return -1;
        }
    
        int findPairs(vector<int>& nums, int k) {
            //return brute(nums, k);
            sort(nums.begin(), nums.end());
            set<pair<int, int>> ans;
            for (int i = 0; i < nums.size(); i++)
            {
                // nums[i];
                // search->a[i]+k[right subarray];
                if (optimalusingbs(nums, i + 1, nums[i] + k) != -1)
                {
                    ans.insert({nums[i], nums[i] + k});
                }
            }
            return ans.size();
        }
    }; 