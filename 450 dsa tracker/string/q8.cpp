    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        string s="abc";
        vector<string>ans;

        int n=s.length();
        
        for (int i = 0; i < s.length(); i++) 
        {
            for (int j = i + 1; j <= s.length(); j++) 
            {
                ans.push_back(s.substr(i, j - i));
            }
        }

        for(string it:ans)
        {
            cout << it << endl;
        }
        return 0;
    }