    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        vector<int>arr={1,2,3,4,5};
        int k=3;
        int n=arr.size();

        vector<int> nums;

        for (int i = k; i < n; i++) 
        {
            nums.push_back(arr[i]);
        }

        for (int i = 0; i < k; i++) 
        {
            nums.push_back(arr[i]);
        }

        for(auto it:nums)
        {
            cout << it << " ";
        }
        cout << endl;
        return 0;
    }