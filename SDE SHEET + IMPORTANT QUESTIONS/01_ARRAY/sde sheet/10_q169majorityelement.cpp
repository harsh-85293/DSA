//using map
class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            unordered_map<int, int>mp;
            int n = nums.size();
    
            for(int i = 0; i < n; i++){
                mp[nums[i]]++;
            }   
    
            int ans = -1;
            for(auto it : mp){
                if(it.second > n / 2){
                    ans = it.first;
                    break;
                }
            }
            return ans;
        }
    };

//optimal -> moores voting algorithm
class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int count = 0;
            int ele;
            int ans = -1;
            for(int i = 0; i < nums.size(); i++){
                if(count == 0){
                    count = 1;
                    ele = nums[i];
                }
    
                else if(nums[i] == ele){
                    count++;
                }
    
                else{
                    count--;
                }
            }
    
            int cnt = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == ele){
                    cnt++;
                }
            }
    
            if(cnt > nums.size()/2){
                ans = ele;
            }
            return ans;
        } 
    };