    //brute force solution
    #include <iostream>
    using namespace std;

    int findrepeatingelement(int arr[],int n)
    {
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<=n-1;j++)
            {
                if((arr[i])==(arr[j]))
                {
                    return i+1;
                }
            }
        }
        return -1;
    
    }
    int main()
    {
        int a[]={1,5,3,4,3,5,6};
        int n=sizeof(a)/sizeof(a[0]);
        int ans=findrepeatingelement(a,n);
        cout << ans;

        return 0;
    }