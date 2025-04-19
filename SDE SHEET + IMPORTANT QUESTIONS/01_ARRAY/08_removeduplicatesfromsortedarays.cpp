class Solution {
    public:
        int brute(vector<int>&nums){
            set<int>st(nums.begin(), nums.end());
            int index = 0;
            for(auto it:st){
                nums[index] = it;
                index++;
            }
            return st.size();
        }
    
        int twopointerapproach(vector<int>&nums){
            int i = 0;
            int j = i+1;
            int n = nums.size();
            while(j < n){
                if(nums[i] == nums[j]){
                    j++;
                }
                else{
                    i++;
                    nums[i] = nums[j];
                }
            }
            return i + 1 ;
        }
    
        int removeDuplicates(vector<int>& nums) {
            //return brute(nums);
            return twopointerapproach(nums);
        }
    };