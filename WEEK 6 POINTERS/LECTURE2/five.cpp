    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        //array->stack memory
        int arr[5]={0};
        cout << arr[0] << arr[1] << arr[2] << endl;

        //array -> heap memory(dynamic memory)
        int *brr=new int[5];
        cout << brr[0] << brr[1] << brr[2];

        return 0;
    }