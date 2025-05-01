class Solution {
    public:
        bool ls(vector<int> &nums, int target){
            bool ans = false;
    
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == target){
                    ans = true;
                    break;
                }
            }
            return ans;
        }
    
        int brute(vector<int>& nums){
    
            if(nums.size() == 0){
                return 0;
            }
            int ans = INT_MIN;
            for(int i = 0; i < nums.size(); i++){
                int x = nums[i];
                int count = 1;
               
                while(ls(nums, x + 1) == true){
                    x += 1;
                    count += 1;
                }
                ans = max(ans, count);
            }
            return ans;
        }
        
        int better(vector<int>& nums){
    
            if(nums.size() == 0){
                return 0;
            }
    
            int lastsmaller = INT_MIN;
            int countcurr = 0;
            int longest = 1;
            int n = nums.size();
    
            sort(nums.begin(), nums.end());
    
            for(int i = 0; i < n; i++){
                
                if(nums[i] == lastsmaller){
                    continue;
                }
    
                else if(nums[i] - 1 ==  lastsmaller){
                    lastsmaller = nums[i];
                    countcurr++;
                   
                }
    
                else if(nums[i] != lastsmaller){ 
                    countcurr = 1;
                    lastsmaller = nums[i];
                }
    
                longest = max(longest, countcurr);
            }
            return longest;
        }
        
        int optimal(vector<int>& nums){
            int n = nums.size();
            if(n == 0){
                return 0;
            }
    
            unordered_set<int>st;
            int longest = 1;
            for(int i = 0; i < n; i++){
                st.insert(nums[i]);
            }
    
            for(auto it:st){
                if(st.find(it - 1) == st.end()){
                    int cnt = 1;
                    int x = it;
                    while(st.find(x + 1) != st.end()){
                        x += 1;
                        cnt++;
                    }
                    longest = max(longest, cnt);
                }
            }
            return longest;
        }
    
        int longestConsecutive(vector<int>& nums) {
            //return brute(nums);
            //return better(nums);
            return optimal(nums);
        }
    };