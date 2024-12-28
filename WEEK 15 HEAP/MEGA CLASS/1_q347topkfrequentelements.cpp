   #include <bits/stdc++.h>
   using namespace std;

    class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> mp;
            // Count frequencies
            for(int i = 0; i < nums.size(); i++){
                mp[nums[i]]++;
            }
            
            vector<int> ans;
            // Store pairs of {frequency, number}
            priority_queue<pair<int,int>> maxHeap;
            
            // Push pairs into heap
            for(auto it : mp){
                maxHeap.push({it.second, it.first});  // {frequency, number}
            }
            
            // Get top k elements
            for(int i = 0; i < k; i++){
                ans.push_back(maxHeap.top().second);  // Push the number
                maxHeap.pop();
            }
            return ans;
        }
    };

    int main()
    {
        return 0;
    }