//fixed size wiondow
class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            deque<int>dq;
            vector<int>ans;
    
            //process first window
            for(int i=0; i<k; i++)
            {
                int ele = nums[i];
                //yele element to queue ke insert hoga hi hoga
                //but mai ekkaam kar sakta hu
                //jitne element bane hue hai queue mai unme se check kar lo 
                //ki konse chote hai unhe pop kar lo
                while(!dq.empty() && nums[dq.back()] < ele )
                {
                    dq.pop_back();
                }
                //current element insert karna hai
                dq.push_back(i);
            }
            //get answer for first window
            int index = dq.front();
            int ele = nums[index];
            ans.push_back(ele);
    
            //process remaining window
            for(int i=k; i<nums.size(); i++)
            {
                //process remaining window
                if(!dq.empty() && dq.front() < i-k+1)
                {
                    dq.pop_front();
                }
                //add item
                int ele=nums[i];
                while(!dq.empty() && nums[dq.back()] < ele )
                {
                    dq.pop_back();
                }
                //current element insert karna hai
                dq.push_back(i);
    
                //ans store
                int index = dq.front();
                int ansele = nums[index];
                ans.push_back(ansele);
            }
            return ans;
        }
    };