    #include <bits/stdc++.h>
    using namespace std;

    void maxinarray(int arr[],int size,int index,int &ans)
    {
        //basecase
        if(index==size)
        {
            return;
        }
        //recursive relation
        ans=max(ans,arr[index]);//1 case mera
        
        maxinarray(arr,size,index+1,ans);
    }

    void mininarray(int arr[],int size,int index,int &mini)
    {
        //base case
        if(index==size)
        {
            return;
        }
        //recursion relation
        mini=min(arr[index],mini);//1 case

        mininarray(arr,size,index+1,mini);//recursion sambhal lega
    }

    int main()
    {
        int arr[]={10,20,30,40,50,60};
        int index=0;
        int size=5;
        int ans=INT_MIN;
        maxinarray(arr,size,index,ans);
        cout << ans << endl;

        int mini=INT_MAX;
        mininarray(arr,size,index,mini);
        cout << mini << endl;
        return 0;
    }