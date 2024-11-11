    //LEETCODE Q136 SINGLE NUMBER
    #include <iostream>
    using namespace std;
    int find_unique_element(int arr[],int n)
    {
        int a=0;
        for(int i=0;i<n;i++)
        {
            a=(a^arr[i]);
        }
        return a;
    }
    int main()
    {
        int a=2;
        cout << (1 ^ 1 ^ 3) <<endl;//LOGIC IT WILL RETURN
        cout << (a^0);//return a
        cout << endl;

        int arr[]={1,2,1,2,3};
        int n=sizeof(arr)/sizeof(arr[0]);
        int x=find_unique_element(arr,n);
        cout << x << " is the unique element";
        return 0;
    }