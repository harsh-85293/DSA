    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        int arr[]={1,6,4,5,2,3};
        for(auto i:arr)
        {
            cout << i << " ";
        }

        int n=sizeof(arr)/sizeof(arr[0]);
        sort(arr,arr+n);
        cout << endl;

        for(auto i:arr)
        {
            cout << i << " ";
        }


        return 0;
    }