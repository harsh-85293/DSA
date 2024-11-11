class Solution {
public:
 int getPivotIndex(vector<int>& arr) {
        int s = 0;
        int n = arr.size();
        int e = n-1;
        int mid = s+(e-s)/2;

        while(s <= e) {
            if(s == e) {
                //single element k case me 
                //humne usse hi pivot maaanlia hai
                return s;
            }
            if(mid+1 < n && arr[mid] > arr[mid+1]) {
                return mid;
            }
            //kab left or kab right
            if(arr[s] > arr[mid] ) {
                e = mid-1;
            }
            else {
                //right
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        return -1;
    }

    int findMin(vector<int>& nums) 
    {
      int n=nums.size();
      int pivotindex=getPivotIndex(nums);
      if(pivotindex==(n-1))
      {
        return nums[0];
      }
      else
      {
        return nums[pivotindex+1];
      }
    }
};