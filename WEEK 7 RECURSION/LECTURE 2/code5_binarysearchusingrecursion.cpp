    #include <bits/stdc++.h>
    using namespace std;

    int binarysearch(int arr[],int s,int e ,int target)
    {
        //base case
        if(s>e)
        {
            return -1;
        }
        
        //recursive relation
        //1 case mai karunga
        int mid=(s+e)/2;
        if(arr[mid]==target)
        {
            return mid;
        }

        //baki recursion sambhal lega
        if(target>arr[mid])//right mai jao
        {
            s=mid+1;
            return binarysearch(arr,s,e,target);
        }

        else//left mai jao
        {
            e=mid-1;
            return binarysearch(arr,s,e,target);
        }
    }

    int main()
    {        
        int arr[]={10,20,30,40,50,60,70,80,90};
        int n=sizeof(arr)/sizeof(arr[0]); 
        int target=70;
        int s=0;
        int e=n-1;
        int ans=binarysearch(arr,s,e,target);
        cout << "index of "<< target << " found at:" <<ans;
        return 0;
    }