    //nearly sorted array    
    #include <bits/stdc++.h>
    using namespace std;

    int applybinarysearch(int arr[],int n,int target)
    {
        int start=0;
        int end=n-1;
        int mid=start+(end-start)/2;
        
        while(start<=end)
        {
            if(arr[mid]==target)
            {
                return mid;
            }

            else if(arr[mid-1]==target)
            {
                return mid-1;
            }

            else if(arr[mid+1]==target)
            {
                return mid+1;
            }

            else if(target>arr[mid])
            {
                start=mid+1;
            }

            else
            {
                end=mid-1;
            }
            mid=start+(end-start)/2;
        }
        return -1;
    }

    int main()
    {
        int arr[]={1,0,1,1,1};
        int n=sizeof(arr)/sizeof(arr[0]);
        int target=40;
        int ans=applybinarysearch(arr,n,target);
        
        cout << "ANS FOUND AT INDEX:" << ans;
        
        return 0;
    }