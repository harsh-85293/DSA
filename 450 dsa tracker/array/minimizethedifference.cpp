    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        int K=2;
        vector<int> A={1, 2, 3, 4, 5};
        for (int i = 0; i < A.size(); i++) 
		{
			A[i]+=K;
		}
		int maxi=INT_MIN;
		int mini=INT_MAX;
		for (int i = 0; i < A.size(); i++) 
		{
			maxi=max(maxi,A[i]);
			mini=min(mini,A[i]);
		}
		cout << maxi-mini;
        return 0;
    }