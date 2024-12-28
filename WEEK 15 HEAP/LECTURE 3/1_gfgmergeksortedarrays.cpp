    //{ Driver Code Starts
    //Initial Template for C++

    #include<bits/stdc++.h>
    #define N 105
    using namespace std;

    //data inside priority queue
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

    //min heap creation ->stl
    class compare{
        public:
            bool operator()(Info* a, Info* b){
                return a->data > b->data;//if <  min heap
            }
    };

    class Solution
    {
        public:
            //Function to merge k sorted arrays.
            vector<int> mergeKArrays(vector<vector<int>> arr, int K){
                //code here
                priority_queue<Info*, vector<Info*>, compare > pq;
                vector<int>ans;
                
                //process first k elements
                //har row ka first element
                int totalrows = arr.size();
                int totalcolumns = arr[0].size();
                for(int row = 0; row < totalrows; row++){
                    int ele = arr[row][0];
                    Info* temp = new Info(ele, 0, row);
                    pq.push(temp);
                }
                
                //main logic
                //tab tak aage bado jab tak priority queue empty na ho
                while(!pq.empty()){
                    Info* front = pq.top();
                    pq.pop();
                    
                    int frontdata = front->data;
                    int front_cindex = front->cindex;
                    int front_rindex = front->rindex;
                    ans.push_back(frontdata);
                    
                    //check if aage data hai fornt ke ,then push it to priority queue
                    if(front_cindex + 1 < totalcolumns){
                        int ele = arr[front_rindex][front_cindex + 1];
                        Info* temp = new Info(ele, front_cindex + 1, front_rindex);
                        pq.push(temp);
                    }
                    delete front;
                }
                return ans;
        }
    };