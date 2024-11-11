class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int n=nums.size();
        int j=0;
        int i=1;
        while(i<n)
        {
            if(nums[i]==nums[j])
            {
                i++;
            }    
            else
            {
                j++;
                nums[j]=nums[i];
                i++;
            }
        }
        int k=j+1;
        return k;
    }
};