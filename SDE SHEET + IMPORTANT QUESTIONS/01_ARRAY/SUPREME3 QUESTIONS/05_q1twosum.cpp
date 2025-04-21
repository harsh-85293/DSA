//brute approach calculate all combinations
class Solution {

    public:
        vector<int> twoSum(vector<int>& nums, int target) {
           
           for(int i = 0; i < nums.size(); i++){
                for(int j = 0; j < i; j++){
                    if(nums[i] + nums[j] == target){
                        return {i, j};
                    }
                }
           }
           return {-1, -1};
        }
    };

    //better approach
    class Solution {
        public:
            vector<int> twoSum(vector<int>& nums, int target) {
                unordered_map<int, int>mp;
                for(int i =0; i < nums.size(); i++){
                    if( mp.find(target - nums[i]) != mp.end() ){
                        return {i, mp[target - nums[i]]};
                    }
                    mp[nums[i]] = i;
                }
                return {-1, -1};
            }
        };    

    //if map not allowed -> use 2 pointer approach
    class Solution {
        public:
            vector<int> twoSum(vector<int>& nums, int target) {
        
                vector<pair<int, int>> vec;
                
                for(int i = 0; i < nums.size(); i++) {
                    vec.push_back({nums[i], i});
                }
        
                sort(vec.begin(), vec.end());
        
                int i = 0, j = nums.size() - 1;
        
                while(i < j) {
        
                    int sum = vec[i].first + vec[j].first;
        
                    if(sum == target) {
                        return {vec[i].second, vec[j].second};
                    }
        
                    else if(sum < target) {
                        i++;
                    }
        
                    else {
                        j--;
                    }
                }
        
                return {-1, -1};
            }
        };
        