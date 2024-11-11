class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        int ans;
        unordered_map<int,int> hashmap;
        for(int i=0;i<nums.size();i++)
        {
            int num=nums[i];
            hashmap[num]=hashmap[num]+1;
        }

        for(auto it:hashmap)
        {
            int key=it.first;
            int value=it.second;

            if(value==1)
            {
                ans=key;
                break;
            }
        }
        return ans;
    }
};