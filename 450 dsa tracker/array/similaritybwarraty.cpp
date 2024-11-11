    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        int n=5,m=4;
        int arr1[]={1,2,3,4,5};
        int arr2[]={2,4,6,8};
        int i=0;
        int j=0;
        vector<int>ans;

        for (int i = 0; i < n; i++) 
        {
            ans.push_back(arr1[i]);
        }
        for (int j = 0; j < m; j++) 
        {
            ans.push_back(arr2[j]);
        }

        sort(ans.begin(),ans.end());

        set<int>s(ans.begin(),ans.end());

        int a1=ans.size()-s.size();
        int a2=s.size();

        pair<int,int> finalans;

        finalans.first=a1;
        finalans.second=a2;

        cout << finalans.first << " " << finalans.second << endl;

        return 0;
    }