   #include <bits/stdc++.h>
   using namespace std;
      class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            //min heap create
            priority_queue<int, vector<int>, greater<int>>pq;

            //initial state maintain by inserting k elements in priority queue
            for(int i = 0; i < k; i++){
                pq.push(nums[i]);
            }

            //process remaining elements
            //we want in end of pq k large ho to sirf bade element ko insert karo
            for(int i = k; i < nums.size(); i++){
                int ele = nums[i];
                if(ele > pq.top()){
                    pq.pop();
                    pq.push(ele);
                }
            }
            int ans = pq.top();
            return ans;
        }
    };
   int main()
   {
     return 0;
   }
