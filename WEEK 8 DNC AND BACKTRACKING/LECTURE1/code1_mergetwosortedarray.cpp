    #include <bits/stdc++.h>
    using namespace std;

    void mergetwosortedarray(int arr[],int n,int brr[],int m,vector<int>&ans)
    {
        int i=0;
        int j=0;

        while(i<n && j<m)
        {
            if(arr[i]<brr[j])
            {
                ans.push_back(arr[i]);
                i++;           
            }
            else
            {
                ans.push_back(brr[j]);
                j++;
            }
        }

        //arr me element bache hai
        while(i<n)
        {
            ans.push_back(arr[i]);
            i++;
        }
        //brr mai element bache hua hai
        while(j<m)
        {
            ans.push_back(brr[j]);
            j++;
        }
        
    }

    int main()
    {
        int arr[]={10,30,50,70};
        int n=4;

        int brr[]={20,40,60,80,90,100};
        int m=6;

        vector<int> ans;
        mergetwosortedarray(arr,n,brr,m,ans);

        for(auto it:ans)
        {
            cout << it << " ";
        }
        return 0;
    }