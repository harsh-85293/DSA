class Solution {
    public:
      string calc_Sum(vector<int>& arr1, vector<int>& arr2) 
      {
          // Complete the function
          int i=arr1.size()-1;
          int j=arr2.size()-1;
          int carry=0;
          string ans;
          
          while(i>=0 && j>=0)
          {
              int x=arr1[i]+arr2[j]+carry;
              int digit=x%10;
              ans.push_back('0'+digit);
              carry=x/10;
              i--;
              j--;
          }
          
          while(i>=0)
          {
              int x=arr1[i]+carry;
              int digit=x%10;
              ans.push_back('0'+digit);
              carry=x/10;
              i--;
          }
           while(j>=0)
          {
              int x=arr2[j]+carry;
              int digit=x%10;
              ans.push_back('0'+digit);
              carry=x/10;
              j--;
          }
          if(carry!=0)
          {
              ans.push_back('0'+carry);
          }
          reverse(ans.begin(),ans.end());
          return ans;
          
      }
      
  };