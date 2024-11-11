class Solution 
{
public:
    bool solve(vector<int>& nums,int i)
    {
        if(i==nums.size()-1) return true;
        if(i>=nums.size()) return false;
        if(nums[i]==0 ) return false;//stuck at that position

        bool recursans=false;//manlo nahi pahuch payenge
        for(int jump=1;jump<=nums[i];jump++)
        {
            recursans=recursans||solve(nums,i+jump);
        }
        return recursans;
    }

    bool canJump(vector<int>& nums) 
    {
        return solve(nums,0);
    }
};