class Solution {
public:
    bool solve(vector<int> &nums,int target,int index)
    {
        if(target<0 || index==nums.size())
        {
            return false;
        }
        if(target==0)
        {
            return true;
        }
        bool include=solve(nums,target-nums[index],index+1);
        bool exclude=solve(nums,target,index+1);

        bool res=include || exclude;
        return res;
    }

    bool canPartition(vector<int>& nums) 
    {
        int sum=accumulate(nums.begin(),nums.end(),0);

        if((sum%2)!=0)
        {
            return false;
        }   
        int target=sum/2;
        return solve(nums,target,0);
    }
};