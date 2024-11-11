    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        string s="BANANA";
        int n=s.length();
        unordered_map <char,int> mpp;

        for (int i = 0; i < n; i++) 
        {
            mpp[s[i]]++;
        }
        vector<pair<char,int>>ans;

        for(auto it:mpp)
        {
            if(it.second>1)
            {
                ans.push_back(it);
            }
        }

        for (const auto it : ans)
        {
            cout << it.first << ": " << it.second << endl;
        }
        return 0;
    }