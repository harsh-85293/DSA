   //STORE AND COMPUTE APPROACH
    #include <bits/stdc++.h>
    using namespace std;
   
    void findFirstOccurrence(int arr[], int n, int target, int &ansIndex) 
    {
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;

        while(s <= e) 
        {
            if(arr[mid] == target) 
            {
                //ans found -> may or may not be first occurence
                //store and compute
                ansIndex = mid;
                //kyoki first occurence ki baat hori h
                //toh batao left me jau first occ k liye ya right me 
                //left me jao
                e = mid - 1;
            }

            if(target > arr[mid] ) 
            {
                ///right me jao
                s = mid + 1;
            }

            if(target < arr[mid]) 
            {
                //left me jao 
                e = mid-1;
            }

            //ye main bhul jata hu
            mid = s + (e-s)/2;
        }
    }
    

    void findLastOccurrence(int arr[], int n, int target, int &ansIndex) 
    {
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;

        while(s <= e) 
        {
            if(arr[mid] == target) 
            {
                //target k equal toh hai
                //but may or may not be last occurrence
                //store and compute
                ansIndex = mid;
                //right me jao
                s=mid+1;
            }

            if(target > arr[mid] ) 
            {
                //right me jao
                s = mid+1;
            }

            if(target < arr[mid] ) 
            {
                //left me jao 
                e = mid - 1;
            }

            //ye main bhul jata hu
            mid = s + (e-s)/2;
        }
    }

    int main()
    {
        int arr[]={10,20,20,20,20,20,20,20,30,40,50,60,70};
        int n=sizeof(arr)/sizeof(arr[0]);
        int target=20;

        int ansIndex=-1;
        
        findFirstOccurrence(arr,n,target,ansIndex);
        cout << "first occurence is:" << ansIndex << endl;
        
        findLastOccurrence(arr,n,target,ansIndex);
        cout << "last occurence is:" << ansIndex << endl;
        return 0;
    }