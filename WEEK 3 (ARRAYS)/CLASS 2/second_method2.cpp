    //sort 0s and 1s
    #include <iostream>
    #include <algorithm>
    using namespace std;
     
    void print(int arr[],int size)//remember arr[]
    {
        for(int i=0;i<size;i++)
        {
            cout << arr[i] <<" ";
        }
        cout << endl;
    } 

    int main()
    {
        int arr[]={0,1,1,1,0,0,1,1};
        int n=sizeof(arr)/sizeof(arr[0]);

        cout << "before sort:" << endl;
        print(arr,n);

        int zerocount=0;
        int onecount=0;

        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            {
                zerocount++;
            }
            if(arr[i]==1)
            {
                onecount++;
            }
        }

        // for(int i=0;i<zerocount;i++)
        // {
        //     arr[i]=0;
        // }

        // for(int i=zerocount;i<n;i++)
        // {
        //     arr[i]=1;
        // }

        fill(arr,arr+zerocount,0);
        fill(arr+zerocount,arr+n,1);//here note arr+n should be there because fill demands iterators

        cout << "after sort:" << endl;
        print(arr,n);
       
        return 0;
    }