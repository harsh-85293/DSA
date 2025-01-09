   #include <bits/stdc++.h>
   using namespace std;

    class Solution {
    public:
        class Info{
            public:
                int data;
                int cindex;
                int rindex;
                
                Info(int x, int y, int z){
                    this -> data = x;
                    this -> cindex = y;
                    this -> rindex = z;
                }
        };

        class compare{
            public:
                bool operator()(Info* a, Info* b){
                    return a->data > b->data;//if <m min heap
                }
        };

        vector<int> smallestRange(vector<vector<int>>& nums) {
            priority_queue<Info*, vector<Info*>, compare > pq; 
            vector<int>ans;
            int maxi = INT_MIN;
            int mini = INT_MAX;

            //process first k elements
            int totalrows = nums.size();

            for(int row = 0; row < totalrows; row++){
                int ele = nums[row][0];
                Info* temp = new Info(ele, 0, row);
                pq.push(temp);
                maxi = max(maxi, ele);
                mini = min(mini, ele);
            }
            
            int ans_start = mini;
            int ans_end = maxi;

            //main logic
            //tab tak aage bado jab tak priority queue empty na ho
            while(!pq.empty()){
                Info* front = pq.top();
                pq.pop();
                
                int frontdata = front->data;
                int front_cindex = front->cindex;
                int front_rindex = front->rindex;
                
                //ye bhul jata hoon
                mini = frontdata;

                //ans update
                if( (maxi - mini) < (ans_end - ans_start) ){
                    ans_start = mini;
                    ans_end = maxi;
                }

                //aage elemeent ho to insert karo
                int currtotalcolumns = nums[front_rindex].size();
                if(front_cindex + 1 < currtotalcolumns){
                    int ele = nums[front_rindex][front_cindex + 1];
                    Info* temp = new Info(ele, front_cindex + 1, front_rindex);
                    pq.push(temp);
                    maxi = max(maxi, ele);
                }
                else{
                    break;
                }
                
            }
            ans.push_back(ans_start);
            ans.push_back(ans_end);
            return ans;
        }
    };

   int main()
   {
     return 0;
   }
