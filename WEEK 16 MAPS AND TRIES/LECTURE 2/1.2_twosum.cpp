class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>>mp;

        //values and index mapping
        for(int i = 0; i < nums.size(); i++){
            int value = nums[i];
            mp[value].push_back(i);
        }

        for(int i = 0; i < nums.size(); i++){
            int current = nums[i];
            int required = target - current;
            if(mp.find(required) != mp.end()){
                //found
                //1 element ko 1 hi baar use karna hai
                //handle duplicate case also

                //duplicate case
                if(required == current && mp[current].size() == 1){
                    //iska matlab same element 2 baar use karna hai
                    continue;
                }

                if(required == current && mp[current].size() > 1){
                    //duplicate case
                    return {mp[current][0], mp[current][1] };
                }

                else{
                    //required  is current 
                    return {i, mp[required][0]};
                }
            }
        }
        return {-1, -1};
    }
};