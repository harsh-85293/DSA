    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        vector<string> arr={"aaa", "bbb", "ccc", "aaa", "bbb", "aaa"};
        int n=arr.size();
        string s="";
        unordered_map<string,int>mp;
        vector<int>ansvector;
        
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }

        for(auto it:mp)
        {
            cout << it.first << ":" << it.second << endl;
            ansvector.push_back(it.second);
        }

        sort(ansvector.begin(),ansvector.end());
        int ans=ansvector[0];
        for(int i=1;i<ansvector.size()-1;i++)
        {
            if(ansvector[i]>ans)
            {
                ans=ansvector[i];
            }
        }

        unordered_map<int, string> reverseMap;
        for (auto pair : mp) 
        {
            reverseMap[pair.second] = pair.first;
        }
        string fans=reverseMap[ans];
        cout << fans;
        return 0;
    }