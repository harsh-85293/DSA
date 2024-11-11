long long maxSubarraySum(vector<int> arr, int n)
{
    // Write your code here.
    long long sum=0;
    long long finalans=INT_MIN;
    for (int i = 0; i < n; i++) 
    {
        sum+=arr[i];
        
        if (sum < 0) 
        {
            sum=0;
        }
        finalans=max(finalans,sum);
    }
    return finalans;
}