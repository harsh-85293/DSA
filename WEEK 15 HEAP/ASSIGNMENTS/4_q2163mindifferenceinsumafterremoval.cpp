class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        int len = 3 * n;
        
        vector<long long> leftSum(len, 0), rightSum(len, 0);
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0;
        
        // Compute leftSum: Minimum sum of first n elements from the left
        for (int i = 0; i < len; i++) {
            sum += nums[i];
            maxHeap.push(nums[i]);
            if (maxHeap.size() > n) {
                sum -= maxHeap.top();
                maxHeap.pop();
            }
            if (maxHeap.size() == n) leftSum[i] = sum;
        }

        sum = 0;
        
        // Compute rightSum: Maximum sum of last n elements from the right
        for (int i = len - 1; i >= 0; i--) {
            sum += nums[i];
            minHeap.push(nums[i]);
            if (minHeap.size() > n) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            if (minHeap.size() == n) rightSum[i] = sum;
        }
        
        long long minDiff = LLONG_MAX;
        
        // Compute the minimum difference
        for (int i = n - 1; i < 2 * n; i++) {
            minDiff = min(minDiff, leftSum[i] - rightSum[i + 1]);
        }
        
        return minDiff;
    }
};
