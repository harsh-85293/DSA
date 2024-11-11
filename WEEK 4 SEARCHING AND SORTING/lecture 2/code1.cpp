    class Solution 
    {
    public:
        int peakIndexInMountainArray(vector<int>& arr) 
        {

            int s = 0;
            int n = arr.size();
            int e = n-1;
            int mid = s + (e-s)/2;
            int ansIndex = -1;

            while(s <= e) 
            {
                if(arr[mid] < arr[mid+1])//line a pai hai to answer right mai hoga 
                {
                    s = mid+1;
                }
                else //nahi to ya to peek pe hoga yaa left mai
                {
                    //may or may not be 
                    ansIndex = mid;
                    e = mid-1;
                }
                mid = s + (e-s)/2;
            }
            return ansIndex;
            
            // while(s<e) {
            //     if(arr[mid] < arr[mid+1]) {
            //         ///move right
            //         s = mid+1;
            //     }
            //     else {
            //         ////ya toh main line B pr hu
            //         //ya toh main ans pr hi hu 
            //         e = mid;
            //     }
            //     mid = s+(e-s)/2;
            // }
            // return mid;

            // int max = INT_MIN;
            // int maxIndex = -1;
            // for(int i=0; i<arr.size(); i++) {
            //     if(arr[i] > max) {
            //         max = arr[i];
            //         maxIndex = i;
            //     }
            // }
            // return maxIndex;
        }
    };