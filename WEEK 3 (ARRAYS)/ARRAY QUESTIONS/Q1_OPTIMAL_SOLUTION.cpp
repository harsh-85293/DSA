 class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        // Create a vector of pairs to store the original indices
        vector<pair<int, int>> numWithIndex;
        for (int i = 0; i < nums.size(); ++i) {
            numWithIndex.push_back({nums[i], i});
        }

        // Sort the vector of pairs based on the values
        sort(numWithIndex.begin(), numWithIndex.end());

        int l = 0;
        int h = numWithIndex.size() - 1;
        int csum = 0;

        while (l < h)
        {
            csum = numWithIndex[l].first + numWithIndex[h].first;

            if (csum == target)
            {
                // Return the original indices of the two numbers
                return {numWithIndex[l].second, numWithIndex[h].second};
            }
            else if (csum > target)
            {
                h--;
            }
            else
            {
                l++;
            }
        }
        return {};
    }
};

