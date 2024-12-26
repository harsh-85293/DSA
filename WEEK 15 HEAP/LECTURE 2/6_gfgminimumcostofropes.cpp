   #include <bits/stdc++.h>
   using namespace std;

    class Solution {
    public:
        // Function to return the minimum cost of connecting the ropes.
        int minCost(vector<int>& arr) {
            // code here
            priority_queue< int, vector<int>, greater<int> > pq;
            for(int i = 0; i < arr.size(); i++){
                int val = arr[i];
                pq.push(val);
            }
            
            int cost = 0;
            while(pq.size() != 1){
                int first  = pq.top();
                pq.pop();
                
                int second = pq.top();
                pq.pop();
                
                int sum = first + second;
                
                cost += sum;
                pq.push(sum);
            }
            return cost;
        }
    };


   int main()
   {
        return 0;
   }
