       //function and array
    #include <iostream>
    using namespace std;
    
    void print(int arr[],int size)//remember arr[]
    {
        for(int i=0;i<size;i++)
        {
            cout <<"element " << (i+1) << ":"<< arr[i] << endl;
        }
    }

    void solve(int arr[],int n)
    {
        for(int i=0;i<n;i++)
        {
            arr[i]=arr[i]*10;
        }
    }
    
    int main()
    {
        int arr[]={10,20,30,40,50};
        int size=5;
        solve(arr,size);
        print(arr,size);//remember arr
        return 0;
    }