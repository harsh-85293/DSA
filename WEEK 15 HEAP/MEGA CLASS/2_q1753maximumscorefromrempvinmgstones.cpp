   #include <bits/stdc++.h>
   using namespace std;
   class Solution {
  public:
      int maximumScore(int a, int b, int c) {
          //form a maximum heap
          priority_queue<int, vector<int>>maxHeap;
          maxHeap.push(a);
          maxHeap.push(b);
          maxHeap.push(c);
          
          int ans = 0;

          while(maxHeap.size() > 1){
              int pile1 = maxHeap.top();
              maxHeap.pop();
              int pile2 = maxHeap.top();
              maxHeap.pop();

              pile1--;
              pile2--;
              
              ans++;
              
              if(pile1 > 0){
                  maxHeap.push(pile1);
              }
              
              if(pile2 > 0){
                  maxHeap.push(pile2);
              }
          }
          return ans;
      }
  };
   int main()
   {
     return 0;
   }
