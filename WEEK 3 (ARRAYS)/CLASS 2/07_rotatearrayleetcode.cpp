#include <bits/stdc++.h>
class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int s=nums.size();
        k=k%s;
        if(k==0)
        {
            return ;
        }
        
        vector<int> temp(k);
        int index=0;

        for(int i=s-k;i<s;i++)
        {
            temp[index]=nums[i];
            index++;
        }

        for(int i=s-1;i>=0;i--)
        {
            if(i-k>=0)
            {
                nums[i]=nums[i-k];
            }
        }

        for(int i=0;i<k;i++)
        {
            nums[i]=temp[i];
        }
     }
};