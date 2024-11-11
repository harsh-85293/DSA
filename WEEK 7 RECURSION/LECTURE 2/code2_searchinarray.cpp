    #include <bits/stdc++.h>
    using namespace std;

    bool search(int arr[],int size,int index,int target)
    {
        //base case=2
        //array found
        if(arr[index]==target)
        {
            //found->1 case
            return true;
        }
        //array not found
        if(index==size)
        {
             //invalid index->out of bound
            return false;
        }
        //recursive relation->baaki case
        bool ans=search(arr,size,index+1,target);
        return ans;
        //processing
    }

    int main()
    {
        int arr[]={10,20,30,40,50};
        int index=0;
        int size=5;
        int target=60;

        bool ans=search(arr,size,index,target);
        cout <<  ans << endl;

        return 0;
    }