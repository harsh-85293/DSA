//BRUTE APPROACH
class Solution {
    public:
        int pivotIndex(vector<int>& nums) {
            int n = nums.size();
    
            int lsum = 0;
            int rsum = 0;
            int ans = -1;
    
            for(int i = 0; i < n; i++){
    
                for(int j = 0; j < i; j++){
                    lsum += nums[j];
                }
    
                for(int j = i + 1; j < n; j++){
                    rsum += nums[j];
                }
    
                if(lsum == rsum){
                    ans = i;
                    break;
                }
                //i forgot the below step
                lsum = 0;
                rsum = 0;
            }
            return ans;
        }
    };

//OPTIMAL APPROACH
class Solution {
    public:
        int prefixsumapproach(vector<int>& nums){
            int n = nums.size();
            vector<int>lsum(n, 0);
            vector<int>rsum(n, 0);
            int ans = -1;
    
            for(int i = 1; i < n; i++){
                lsum[i] = lsum[i - 1] + nums[i - 1];
            }
    
            for(int i = n - 2; i >= 0; i--){
                rsum[i] = rsum[i + 1] + nums[i+1];
            }
    
            for(int i = 0; i < n; i++){
                if(lsum[i] == rsum[i]){
                    ans = i;
                    break;
                }
            }
            return ans;
        }
    
        int pivotIndex(vector<int>& nums) {
            return prefixsumapproach(nums);
        }
    };