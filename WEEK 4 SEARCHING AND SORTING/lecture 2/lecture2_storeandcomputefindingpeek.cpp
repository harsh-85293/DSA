    class Solution {
    public:
        int peakIndexInMountainArray(vector<int>& arr) 
        {
            int n=arr.size();
            int s=0;
            int e=n-1;
            int mid=s+(e-s)/2;
            int ansIndex=-1;

            while(s<=e)
            {
                if(arr[mid]<arr[mid+1])
                {
                    s=mid+1;
                }
                else
                {
                    ansIndex=mid;
                    e=mid-1;
                }
                mid=s+(e-s)/2;
            }
            return ansIndex;
        }
    };