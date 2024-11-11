#include <bits/stdc++.h> 
bool checkSubset(vector < int > & arr1, vector < int > & arr2, int n, int m) 
{
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    // Write your code here.
    if(m>n)
    {
        return false;
    }
    else
    {
        bool isSubset = includes(arr1.begin(), arr1.end(), arr2.begin(), arr2.end());

        if (isSubset) 
        {
            return true;
        } 
        else 
        {
            return false;
        }
    }
   
}