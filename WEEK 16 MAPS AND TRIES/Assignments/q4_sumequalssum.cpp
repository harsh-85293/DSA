class Solution {
    public:
      bool findPairs(vector<int>& arr) {
          // code here.
          unordered_map<int, bool>mp;
          int n = arr.size();
          
          for(int i = 0; i < n; i++){
              for(int j = i + 1; j < n; j++){
                  
                  int sum = arr[i] + arr[j];
                  
                  if(mp.find(sum) != mp.end()){
                      return true;
                  }
                  else{
                      mp[sum] = true;
                  }
              }
          }
          return false;
      }
  };