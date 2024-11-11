#include <bits/stdc++.h>
using namespace std;

string second_repeat(vector<string> &arr, int n) {
    // Handle empty array case
    if (arr.empty()) 
    {
        return "";
    }

    unordered_map<string, int> mp;

    // Count the frequency of each string
    for (int i = 0; i < n; ++i) 
    {
        mp[arr[i]]++;
    }

    // Find the first and second maximum frequencies
    int first_max = INT_MIN, second_max = INT_MIN;

    for (auto it : mp) 
    {
        int current = it.second;

        if (current > first_max) 
        {
            second_max = first_max;
            first_max = current;
        } 
        else if (current > second_max && current != first_max) 
        {
            second_max = current;
        }
    }

    // Find the string with the second maximum frequency
    for (auto  it : mp) 
    {
        if (it.second == second_max) 
        {
            return it.first;
        }
    }

    return ""; // Return empty string if no second maximum frequency found
}
