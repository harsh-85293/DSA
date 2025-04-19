class Solution {
    public:
        int solveusingmap(vector<int>& nums){
            unordered_map<int, int>mp;
    
            for(int i = 0; i < nums.size(); i++){
                mp[nums[i]]++;
            }
    
            int ans = -1;
            for(auto it:mp){
                if(it.second > 1){
                    ans = it.first;
                    break;
                }
            }
            return ans;
        }
    
        //Floyd's Tortoise and Hare (Cycle Detection) algorithm
        int slowandfastpointerapproach(vector<int>& nums){
            int n = nums.size();
            int slow = nums[0];
            int fast = nums[0];
    
           do{
                slow = nums[slow];
                fast = nums[nums[fast]];
            }while (slow != fast);
    
    
            fast = nums[0];
            while(slow != fast){
                slow = nums[slow];
                fast = nums[fast];
            }
            return slow;
        }
    
        int findDuplicate(vector<int>& nums) {
            //return solveusingmap(nums);
            return slowandfastpointerapproach(nums);
        }
    };