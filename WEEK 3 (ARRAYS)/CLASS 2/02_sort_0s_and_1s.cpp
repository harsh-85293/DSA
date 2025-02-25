    //sort 0s and 1s
    #include <iostream>
    #include <algorithm>
    using namespace std;
     
    void print(int arr[],int size)//remember arr[]
    {
        for(int i=0;i<size;i++)
        {
            cout << arr[i] <<" ";
        }
        cout << endl;
    } 

    int main()
    {
        int arr[]={0,1,1,1,0,0,1,1};
        int n=sizeof(arr)/sizeof(arr[0]);
        cout << "before sort:" << endl;
        print(arr,n);
        sort(arr,arr+n);
        cout << "after sort:" << endl;
        print(arr,n);
       
        return 0;
    }