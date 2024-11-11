    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        vector<int> arr={2,1,3,2,4};
        int n=5;
        int i=0;
        int ans=-1;
        for (int jump = 0; jump < arr[i]; jump++) 
        {
            jump+=arr[i];
            if (jump == n) 
            {
                ans=jump;
            }
            i++;
        }
        cout <<  ans;
        return 0;
    }