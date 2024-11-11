#include <bits/stdc++.h> 


vector<int> findCommonElements(vector<int> &a, vector<int> &b, vector<int> &c)
{
     int i = 0, j = 0, k = 0;
    int n = a.size();
    int m = b.size();
    int l = c.size();

    vector<int> ans;

    while (i < n && j < m && k < l)
    {
        if (a[i] == b[j] && b[j] == c[k])
        {
            // Found a common element
            ans.push_back(a[i]);
            i++;
            j++;
            k++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else if (b[j] < c[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }
    
    set<int>s(ans.begin(),ans.end());
    vector<int>finalans(s.begin(),s.end());
    return finalans;
}