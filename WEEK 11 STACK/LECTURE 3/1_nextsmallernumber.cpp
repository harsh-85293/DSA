    #include <bits/stdc++.h>
    using namespace std;
    void nextsmaller(stack<int>&s, vector<int>&arr, vector<int>&ans)
    {
        s.push(-1);
        int n = arr.size();
        for(int i = n-1; i >= 0; i--)
        {
            int ele=arr[i];
            //is element ke liye stack check karenge
            while(s.top() >=  ele)
            {
                s.pop();
            }
            //jab mai yaha phuchunga
            //aapke stack top par koi chota elkement pada hai
            // ya to wo -1 hai ya aur koi elemnent hai
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
        v.push_back(6);
        v.push_back(2);
        v.push_back(5);
        vector<int>ans;
        nextsmaller(s, v, ans);
        reverse(ans.begin(), ans.end());
        for(auto it:ans)
        {
            cout << it << endl;
        }
        return 0;
    } 