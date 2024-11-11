    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
        int arr[]={10,20,30,40};
        // arr=arr+1;->cannot be modified
        int *ptr=arr;
        ptr=ptr+1;
        cout << *ptr << endl;

        return 0;
    }