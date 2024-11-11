    #include <bits/stdc++.h>
    using namespace std;

    int sum_calculator(std::vector<int>& nums, int divisor) 
    {
        int n = nums.size();
        int sum = 0;  // Use int for sum as the return type is int

        for (int i = 0; i < n; i++) 
        {
            // Perform floating-point division and apply ceil
            int g = ceil(double(nums[i]) / divisor);
            sum += g;  // Sum the integer ceiling result
        }
        cout << sum;
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int i=0;
        int j=1;
        int m=INT_MIN;
        int ans;
        for(int i=0;i<nums.size();i++)
        {
            m=max(m,nums[i]);
        }
        for(int j=1;j<=m;j++)
        {
            int g=sum_calculator(nums,j);
            if(g<threshold)
            {
                ans=j;
            }
            else
            {
                break;
            }
        }
        return ans;
    }

    int main()
    {
        vector<int> nums={44,22,33,11,1};
        int threshold=5;
        //smallestDivisor(nums,threshold);
        //cout <<
        sum_calculator(nums,44);
        return 0;
    }