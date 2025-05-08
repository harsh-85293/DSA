class Solution {
    public:
    
        int maxelement(vector<int>& piles){
            int maxele = INT_MIN;
            int n = piles.size();
            for(int i = 0; i < n; i++){
                maxele  = max(maxele, piles[i]);
            }
            return maxele;
        }
    
        double calculatetotalhours(vector<int>& piles, int h){
            double totalhr = 0;
            int n = piles.size();
            for(int i = 0; i < n; i++){
                totalhr += ceil( (double)piles[i] / (double)h );
            }
            return totalhr;
        }
    
        int minEatingSpeed(vector<int>& piles, int h) {
        
            int maxele = maxelement(piles);
            int low = 1;//The minimum possible eating speed should be 1, not piles[0], because Koko can eat as slowly as 1 banana/hour.
            int high = maxele;
            int ans = INT_MAX;
    
            while(low <= high){
                int mid = low + (high - low)/2;
                double totalhrs = calculatetotalhours(piles, mid);
    
                if(totalhrs <= h){
                    ans = mid;
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            return ans;
        }
    };