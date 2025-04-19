#include <bits/stdc++.h>
class Solution {
    public:
        double brute(vector<int>& nums, int k){
            int n = nums.size();
            int maxsum = INT_MIN;
    
            for(int i = 0; i <= n - k; i++) { // fix: include the last valid starting index
                int sum = 0;
                for(int j = i; j < i + k; j++) {
                    sum += nums[j];
                }
                maxsum = max(maxsum, sum);
            }
    
            double ans = double(maxsum) / k;
            return ans;
        }
    
        double slidingwindow(vector<int>& nums, int k){
            int i = 0;
            int j = k - 1;
            int n = nums.size();
            int maxsum = INT_MIN;
            int sum = 0;
    
            for(int y = i; y <= j; y++){
                sum += nums[y];
            }
            maxsum = sum;
            j++;
            while(j < n){
                sum = sum - nums[i] + nums[j]; 
                i++;
                j++;
                maxsum = max(maxsum, sum);
            }
            double ans = (double)(maxsum) / k;
            return ans;
        }
    
        double findMaxAverage(vector<int>& nums, int k) {
            //return brute(nums, k);
            return slidingwindow(nums, k);
        }   
    };
    