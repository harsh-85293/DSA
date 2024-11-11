    #include <bits/stdc++.h>
    using namespace std;
    
    int getpivotindex(vector<int>arr)
    {
        int n=arr.size();
        int s=0;
        int e=n-1;
        int m=s+(e-s)/2;
        while(s<=e)
        {
            if(m<n-1 && arr[m]>arr[m+1])
            {
                return m;
            }
            if(m>0 && arr[s]<arr[m])
            {
                s=m+1;   
            }
            else
            {
                e=m-1;
            }
            m=s+(e-s)/2;
        }
        return -1;
    }

    int main()
    {
        vector<int> m={38 ,40 ,43, 44, 4 ,9 ,12 ,21, 32, 34};
        int ans=getpivotindex(m);
        cout << ans;
        return 0;
    }
  