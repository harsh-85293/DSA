    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        vector<int>v ={1,1,2,3,5,5};
        set<int> s(v.begin(),v.end());//transferring eleemnts of vector to set

        //maximumsum
        int n=s.size()+1;
        int maximumsum=n*(n+1)/2;

        //uniquesum:sum in set
        int uniquesum=0;
        for(int it:s)
        {
            uniquesum+=it;
        }

        //missingelement finding
        int finalanswer=maximumsum-uniquesum;
        cout << "missing element is:" << finalanswer << endl;

        return 0;
    }