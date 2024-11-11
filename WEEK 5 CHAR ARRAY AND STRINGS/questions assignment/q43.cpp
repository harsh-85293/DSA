    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
        vector<string> strs={"eat","tea","tan","ate","nat","bat"};
        vector<string>ans(strs.size());

        for(int i=0;i<strs.size();i++)
        {
            string s=strs[i];
            sort(s.begin(),s.end());
            ans[i]=s;
        }

        for(auto it:ans)
        {
            cout << it << " ";
        }
        return 0;
    }