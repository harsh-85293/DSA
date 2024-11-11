    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        vector<int> arr={1, 2, 3, 4, 5};
        int target=6;
        int n=5;
        int ans=-1;
        int count=0;

        int i=0;
        int j=n-1;

        while (i < j) 
        {
            if(arr[i]+arr[j]==target)
            {
                count++;
                i++;
                j--;
            } 
            else if (arr[i] + arr[j] < target) 
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        if (count > 0) 
        {
            ans=count;
        }
        cout << ans;
        return 0;
    }