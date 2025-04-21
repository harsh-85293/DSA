//brute generate all permutations
class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            int n = nums.size();
            int i = 0;
            vector<vector<int>> permutations;
    
            // Generate all permutations using recursion (brute-force)
            sort(nums.begin(), nums.end());  // Start with the smallest
            do {
                permutations.push_back(nums);
            } while (nextPermutationHelper(nums));  // Custom next permutation
    
            // Find the current permutation
            for (i = 0; i < permutations.size(); i++) {
                if (permutations[i] == nums) break;
            }
    
            // If last permutation, wrap around to first
            if (i + 1 == permutations.size()) {
                nums = permutations[0];
            } else {
                nums = permutations[i + 1];
            }
        }
    
        bool nextPermutationHelper(vector<int>& nums) {
            int n = nums.size();
            int i = n - 2;
    
            // Step 1: Find first decreasing element from end
            while (i >= 0 && nums[i] >= nums[i + 1]) i--;
    
            if (i < 0) {
                reverse(nums.begin(), nums.end());
                return false;
            }
    
            // Step 2: Find just bigger element and swap
            int j = n - 1;
            while (nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
    
            // Step 3: Reverse the rest
            reverse(nums.begin() + i + 1, nums.end());
            return true;
        }
    };

//better solution
class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            next_permutation(nums.begin(), nums.end());
        }
    };

//optimal approach
class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            int n = nums.size();
    
            int ind = -1;
            for(int i = n - 2; i >= 0; i--){
                if(nums[i] < nums[i + 1]){
                    ind = i;
                    break;
                }
            }
    
            if(ind == -1){
                reverse(nums.begin(), nums.end());
            }
    
            else{
                for(int i = n-1; i >= ind; i--){
                    if(nums[i] > nums[ind]){
                        swap(nums[i], nums[ind]);
                        break;
                    }
                }
                reverse(nums.begin() + ind + 1, nums.end());
            }
        }
    };