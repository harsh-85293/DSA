    class Solution 
    {
    public:
        int findPairs(vector<int>& nums, int k) 
        {
            int ans = 0;
            sort(nums.begin(), nums.end());

            int i = 0;
            int j = 1;  // Start j from the next element to avoid i == j

            while (j < nums.size()) 
            {
                if (i == j || nums[j] - nums[i] < k) 
                {
                    j++;
                } 

                else if (nums[j] - nums[i] > k) 
                {
                    i++;
                } 

                else 
                {
                    ans++;
                    i++;
                    j++;
                    while (j < nums.size() && nums[j] == nums[j - 1]) //skip duplicates
                    {
                        j++;
                    }
                }
            }

            return ans;
        }
    };