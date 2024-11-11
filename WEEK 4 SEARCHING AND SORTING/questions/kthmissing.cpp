class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int missing_count = 0;
        int current = 1;  // Start checking from number 1
        
        for (int i = 0; i < arr.size(); ++i) 
        {
            while (current < arr[i]) 
            {
                missing_count++;
                if (missing_count == k)
                    return current;
                current++;
            }
            current = arr[i] + 1;
        }
        
        // If kth missing is beyond the largest number in arr
        return arr.back() + (k - missing_count);
    }
};
