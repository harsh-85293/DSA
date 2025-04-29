//using map
class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            unordered_map<int, int>mp;
            int n = nums.size();
    
            for(int i = 0; i < n; i++){
                mp[nums[i]]++;
            }   
    
            vector<int>ans;
            for(auto it : mp){
                if(it.second > n / 3){
                    ans.push_back(it.first);
                }
            }
            return ans;
        }
    };

    //optimal made changes in moores voting algorithm
    class Solution {
        public:
            vector<int> majorityElement(vector<int>& nums) {
                int ele1;
                int ele2;
                int cnt1 = 0;
                int cnt2 = 0;
                int n = nums.size();
        
                for(int i = 0; i < n; i++){
                    
                    if(cnt1 == 0 && nums[i] != ele2){
                        cnt1 = 1;
                        ele1 = nums[i];
                    }
        
        
                    else if(cnt2 == 0 && nums[i] != ele1){
                        cnt2 = 1;
                        ele2 = nums[i];
                    }
        
                    else if(ele1 == nums[i]){
                        cnt1++;
                    }
        
                    else if(ele2 == nums[i]){
                        cnt2++;
                    }
        
                    else{
                        cnt1--;
                        cnt2--;
                    }
                }
                vector<int>ans;
                int cnt3 = 0;
                int cnt4 = 0;
                for(int i = 0; i < nums.size(); i++){
                    if(nums[i] == ele1){
                        cnt3++;
                    }
                    if(nums[i] == ele2) {
                        cnt4++;
                    }
                }
        
                if(cnt3 > n/3){
                    ans.push_back(ele1);
                }
                if(cnt4 > n/3){
                    ans.push_back(ele2);
                }
                return ans;
            }
        };