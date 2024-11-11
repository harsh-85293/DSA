    #include <iostream>
    #include <algorithm>
    using namespace std;

    //brute approach
    bool twosum(int arr[],int n,int x)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i]+arr[j]==x)
                {
                    return true;
                }
            }
        }
        return false;
    }

    //optimal approach
    bool twosum2(int arr[],int n,int x)
    {
        int i=0;
        int j=n-1;
        while(i<j)
        {
            int csum=arr[i]+arr[j];//current sum
            if(csum==x)
            {
                return true;
            }
            else if(csum>x)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }

   

    int main()
    {
        int arr[10]={1,4,2,4,2,4,2,44,5,1};
        int n=sizeof(arr)/sizeof(arr[0]);

        sort(arr,arr+n);

        bool ans1=twosum(arr,n,49);
        bool ans2=twosum2(arr,n,49);

        cout << ans1 << "  " << ans2 << endl;

        return 0;
    }