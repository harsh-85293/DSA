    #include <bits/stdc++.h>
    using namespace std;

    bool checkifarraysorted(int arr[],int size,int index)
    {
        //base case
        if(index==size-1)//single element
        {
            return true;
        }
        // 1 case mai karunga
        if(arr[index]<arr[index+1])
        {
            return true;
        }
        else
        {
            return false;
        }
        //recursive relation
        //baaki kaam recursion karega
        checkifarraysorted(arr,size,index+1);
        //processing
    }

    int main()
    {
        int arr[]={70,20,30,40,50,60};
        int size=sizeof(arr)/sizeof(arr[0]);
        int index=0;
        
        bool ans=checkifarraysorted(arr,size,index);

        cout << ans << endl;
        return 0;
    }