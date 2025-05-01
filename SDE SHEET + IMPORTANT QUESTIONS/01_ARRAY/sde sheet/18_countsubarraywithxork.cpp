class Solution {
    public:
        long subarrayXor(vector<int> &arr, int k) {
            int n = arr.size();
            int xr = 0;
            map<int, int> mpp;
            mpp[xr] = 1;
            long cnt = 0;
    
            for (int i = 0; i < n; i++) {
                xr ^= arr[i];
                int x = xr ^ k;
                cnt += mpp[x];
                mpp[xr]++;
            }
    
            return cnt;
        }
    };
    
    