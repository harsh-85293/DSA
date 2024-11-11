    #include <bits/stdc++.h>
    using namespace std;
    void prevsmaller(stack<int>&s, vector<int>&arr, vector<int>&ans)
    {
        s.push(-1);
        int n=arr.size();
        for(int i=0; i<=n-1; i++)
        {
            int ele=arr[i];
            while(s.top()>ele)
            {
                s.pop();
            }       
            ans.push_back(s.top());
            s.push(ele);
        }
    }
    int main()
    {
        stack<int>s;
        vector<int>v;
        v.push_back(8);
        v.push_back(4);
        v.push_back(2);
        v.push_back(6);
        v.push_back(3);
        vector<int>ans;
        prevsmaller(s, v, ans);
        for(auto it:ans)
        {
            cout << it << endl;
        }
        return 0;
    } 