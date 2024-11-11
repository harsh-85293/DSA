    #include <bits/stdc++.h>

    class Solution 
    {
    public:
        int singleNonDuplicate(vector<int>& nums) 
        {
            int s=0;
            int n=nums.size();
            int e=n-1;
            int m=s+(e-s)/2;

            while(s<=e)
            {
                if(s==e)
                {
                    return nums[s];
                }

                int currentvalue=nums[m];
                int leftvalue=-1;
                int rightvalue=-1;

                if((m-1)>=0)
                {
                    leftvalue=nums[m-1];
                }
                
                if((m+1)<n)
                {
                    rightvalue=nums[m+1];
                }

                if(currentvalue!=leftvalue && currentvalue!=rightvalue)
                {
                    return currentvalue;
                }

                else if(currentvalue==leftvalue && currentvalue!=rightvalue)
                {
                    int pairstartingindex=m-1;
                    if(pairstartingindex&1)//if index is odd  we landed on right and answer is on left
                    {
                        e=m-1;
                    }
                    else
                    {
                        s=m+1;
                    }
                }

                else if(currentvalue!=leftvalue && currentvalue==rightvalue)
                {
                    int pairstartingindex=m;
                    if(pairstartingindex&1)//if index is odd  we landed on right and answer is on left
                    {
                        e=m-1;
                    }
                    else
                    {
                        s=m+1;
                    }
                }
                m=s+(e-s)/2;
            }  
            return -1;  
        }
    };