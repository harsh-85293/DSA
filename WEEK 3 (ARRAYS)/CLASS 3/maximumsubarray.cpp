//maximum subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
           int ans =INT_MIN;
           int sum=0;
           for(int i=0;i<nums.size();i++)
           {
                int num=nums[i];
                sum+=num;
                ans=max(ans,sum);
                if(sum<0)
                {
                    sum=0;
                }
           }
           return ans;
    }
};