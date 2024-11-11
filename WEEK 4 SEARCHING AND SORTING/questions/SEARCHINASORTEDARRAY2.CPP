class Solution {
public:

    int getpivotindex(vector<int>& arr) 
    {
        int s = 0;
        int n = arr.size();
        int e = n-1;
        int mid = s+(e-s)/2;

        while(s <= e) {
            if(s == e) {
                //single element ke case me 
                //humne usse hi pivot maaanlia hai
                return s;
            }
            if(mid+1 < n && arr[mid] > arr[mid+1]) {
                return mid;
            }
            //kab left or kab right
            if(arr[s] > arr[mid]){
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
     
    bool binarySearch(int s, int e, int target, vector<int> arr) 
    {
        int mid = s+(e-s)/2;
        while(s<=e) 
        {
            if(arr[mid] == target) 
            {
               // cout << mid;
                return true;
            }
            if(target > arr[mid]) 
            {
                s = mid+1;
            }
            else 
            {
                e = mid-1;
            }
            mid = s+(e-s)/2;
        }
        return false;
    }

    bool search(vector<int>& nums, int target) 
    {
        set<int> temp(nums.begin(),nums.end());
        vector<int> final_nums(temp.begin(),temp.end());
        int pivotindex=getpivotindex(final_nums);
        cout << pivotindex;
        int n = final_nums.size();
        bool ans;
        if(target >= final_nums[0] && target <= final_nums[pivotindex]) {
            ans = binarySearch(0, pivotindex, target, final_nums);
        }
        else{
            ans = binarySearch(pivotindex+1, n-1, target, final_nums);
        }
        return ans;
    }
        
};