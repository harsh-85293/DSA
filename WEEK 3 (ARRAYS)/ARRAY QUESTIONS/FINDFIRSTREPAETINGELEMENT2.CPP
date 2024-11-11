    //optimal solution
    #include <iostream>
    #include <unordered_map>
    #include <cmath>
    using namespace std;

   int firstRepeated(int arr[], int n) 
    {
        // code here
        unordered_map<int,int> hash;
        
        for(int i=0;i<n;i++)
        {
            hash[arr[i]]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(hash[arr[i]]>1)
            {
                return i+1;
            }
        }
        
        return -1;
        
    }
    int main()
    {
        int a[]={1,5,3,4,3,5,6};
        int n=sizeof(a)/sizeof(a[0]);
        int ans=firstRepeated(a,n);
        cout << ans;
        cout << (1/0);
        return 0;
    }