    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        vector<int>arr={6,1,2,1};
        int k=4;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        vector<int>olm;
        int i=0;
        int j=n-1;

        while(i<j)
        {
            if(arr[i]+arr[j]==k)
            {
                olm.push_back(arr[i]);
                i++;
                j--;
            }
            else if(arr[i]+arr[j] < k)
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        for(auto it:olm)
        {
            cout << it << " ";
        }
        return 0;
    }