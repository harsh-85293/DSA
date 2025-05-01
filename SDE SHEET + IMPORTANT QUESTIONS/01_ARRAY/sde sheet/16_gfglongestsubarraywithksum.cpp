//for +ve numbers
class Solution {
    public:
      int brute(vector<int>& arr, int k){
          int n = arr.size();
          int ans = 0;
          
          
          for(int i = 0; i < n; i++){
              int sum  = 0;
              for(int j = i; j < n; j++){
                  sum += arr[j];
                  if(sum == k){
                      ans = max(ans, j - i + 1);
                  }
              }
          }
          return ans;
      }
      
      
      int better(vector<int>& arr, int k){
          
          int n = arr.size();
          unordered_map<int, int> mpp; 
          int maxi = 0;
          int sum = 0; 
      
          for(int i = 0; i < n; i++) {
              sum += arr[i]; 
      
              if(sum == k) {
                  maxi = i + 1; 
              }
      
              if(mpp.find(sum - k) != mpp.end()) {
                  maxi = max(maxi, i - mpp[sum - k]);
              }
      
              if(mpp.find(sum) == mpp.end()) {
                  mpp[sum] = i;
              }
          }
      
          return maxi; 
      }
      
      int optimal(vector<int>& arr, int k){
          int i  = 0;
          int j = 0;
          int n = arr.size();
          int ans = 0;
          long long sum = arr[0];
          
          while(j < n){
              
              while(i <= j && sum >k){
                  sum = sum - arr[i];
                  i++;
              }
              
              if(sum == k){
                  ans = max(ans, j - i + 1);
              }
              j++;
              
              if(j < n){
                  sum += arr[j];
              }
          }
          return ans;
      }
      
      int longestSubarray(vector<int>& arr, int k) {
          // code here
          //return brute(arr, k);
          //return better(arr, k);
          return optimal(arr, k);
      }
  };