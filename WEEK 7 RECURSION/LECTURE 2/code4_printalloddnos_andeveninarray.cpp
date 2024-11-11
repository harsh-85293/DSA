    #include <bits/stdc++.h>
    using namespace std;
    
    void printallodd(int arr[],int size,int index,vector<int>&store)
    {
        //basecase
        if(index==size)
        {
            return;
        }
        //recursive relation
        if((arr[index]&1)==1) //odd
        {
            store.push_back(arr[index]);
            cout <<  arr[index] << " ";
        }

        printallodd(arr,size,index+1,store);//recursion sambhal lega

        //processing
    }
    void printalleven(int arr[],int size,int index)
    {
        //basecase
        if(index==size)
        {
            return;
        }
        //recursive relation
        if((arr[index]&1)==0) 
        {
            cout <<  arr[index] << " ";
        }

        printalleven(arr,size,index+1);//recursion sambhal lega

        //processing
    }
    int main()
    {
        vector<int>store;
        int arr[]={1,2,3,4,5,6,7,8,9};
        int index=0;
        int size=9;
        printallodd(arr,size,index,store);
        cout << endl;
        printalleven(arr,size,index);cout << endl;
        for(auto it:store)
        {
            cout << it << " ";
        }
        
        return 0;
    }