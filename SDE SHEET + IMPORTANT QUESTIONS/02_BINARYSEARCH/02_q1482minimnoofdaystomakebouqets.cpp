class Solution {
    public:
    
        int maxele(vector<int>& bloomDay){
            int n = bloomDay.size();
            int ans = INT_MIN;
    
            for(int i = 0; i < n; i++){
                ans = max(ans, bloomDay[i]);
            }
            return ans;
        }
        
        int minele(vector<int>& bloomDay){
            int n = bloomDay.size();
            int ans = INT_MAX;
    
            for(int i = 0; i < n; i++){
                ans = min(ans, bloomDay[i]);
            }
            return ans;
        }
    
        bool possibleornot(vector<int>& bloomDay, int day, int m, int k){
            int n = bloomDay.size();
            int cnt = 0;
            int noofb = 0;
    
            for(int i = 0; i < n; i++){
                if(bloomDay[i] <= day){
                    cnt++;
                }
    
                else{
                    noofb += (cnt/k);
                    cnt = 0;
                }
            }
    
            noofb += cnt/k;
    
            if(noofb >= m){
                return true;
            }
    
            return false;
        }
    
        int brute(vector<int>& bloomDay, int m, int k){
            int n = bloomDay.size();
            if( (n/k) < m ){
                return -1;
            }   
            int maxi = maxele(bloomDay);
            int mini = minele(bloomDay);
    
            for(int i = mini; i <= maxi; i++){
                if(possibleornot(bloomDay, i, m, k)){
                    return i;
                }
            }
            return -1;
        }
    
        int optimalusingbs(vector<int>& bloomDay, int m, int k){
            int n = bloomDay.size();
            if( (n/k) < m ){
                return -1;
            }
            int maxi = maxele(bloomDay);
            int mini = minele(bloomDay);
            int low = mini;
            int high = maxi;
            int ans = high;
    
            while(low <= high){
                int mid = low + (high - low) / 2;
                if(possibleornot(bloomDay, mid, m, k)){
                    ans = mid;
                    high = mid - 1;
                }
                else{
                    low = mid + 1; 
                }
            }   
            return ans;
        }
    
        int minDays(vector<int>& bloomDay, int m, int k) {
            //return brute(bloomDay, m, k);
            return optimalusingbs(bloomDay, m, k);
    
        }
    };