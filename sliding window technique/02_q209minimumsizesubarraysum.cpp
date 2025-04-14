//varaible size window
class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) 
        {
            int currsum=0;
            int window=INT_MAX;
            int i=0;
            int j=0;
    
            for(j=0;j<nums.size();j++)
            {
                currsum+=nums[j];
                while(currsum>=target)
                {
                    window=min(window,j-i+1);
                    currsum-=nums[i];
                    i++;
                }
            }
            return window==INT_MAX?0:window;
        }
    };