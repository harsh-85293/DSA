    #include <bits/stdc++.h>
    using namespace std;

    vector<int> findcomplement(vector<int> binary)
    {
        int n=binary.size();
        vector<int> twoscomplement(n+1,0);
        
    }

    int main()
    {
        vector <int> binary={0,0,0,0};
        vector <int> twoscomplement=findcomplement(binary);

        for(auto i:binary)
        {
            cout << i << " ";
        }
        return 0;
    }