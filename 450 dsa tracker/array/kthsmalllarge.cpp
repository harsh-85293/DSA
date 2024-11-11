    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        int k=4;
        int g=k;
        vector<int> arr={5, 6, 7, 2};
        int n=sizeof(arr)/sizeof(arr[0]);

        sort(arr.begin(),arr.end());

        int mini=1;//smallest index
        int maxi=n-1;//largest index

        for(int i=1;i<n;i++)
        {
            if(i==k)
            {
                mini=k;
            }
            k--;
        }

        for(int j=n-1;j>=0;j--)
        {  
            if(j==k)

            {
                maxi=k;
            }
            g--;
        }
        vector<int> ans;

        ans.push_back(arr[mini]);
        ans.push_back(arr[maxi]);

        for(auto it:ans)
        {
            cout << it << " ";
        }
        return 0;
    }