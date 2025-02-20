class Solution {
    public:
      int maxLen(vector<int>& arr) {
          unordered_map<int, int>mp;
          int csum = 0;
          int ans = 0;
          
          for(int i = 0; i < arr.size(); i++){
              csum = csum + arr[i];
              
              if(csum == 0){
                  ans = max(ans, i + 1);
              }
              
              else if(mp.find(csum) == mp.end()){
                  mp[csum] = i;
              }
              
              else{
                  ans = max(ans, i - mp[csum]);
              }
          }
          return ans;
      }
  };
//question 2 : just replaced 0 with -1
  unordered_map<int, int>mp;
          int csum = 0;
          int ans = 0;
          
          for(int i = 0; i < arr.size(); i++){
              csum = csum + arr[i];
              
              if(csum == 0){
                  ans = max(ans, i + 1);
              }
              
              else if(mp.find(csum) == mp.end()){
                  mp[csum] = i;
              }
              
              else{
                  ans = max(ans, i - mp[csum]);
              }
          }
          return ans;