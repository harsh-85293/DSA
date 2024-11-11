#include <bits/stdc++.h>
//brute approach tc=o(n^2)
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sumofranges=0;
        vector<int> temp;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int tempans;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i; j < nums.size(); j++)
            {
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);
                tempans = maxi - mini;
                temp.push_back(tempans);
            }
            mini = INT_MAX;
            maxi = INT_MIN;
        }

        for(int it:temp)
        {
            sumofranges += it;
        }

        return sumofranges;
    }
};

//optimal approach
class Solution {
public:
    vector<int> nextsmaller(vector<int>& v) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(v.size(), -1);
        
        for(int i = v.size() - 1; i >= 0; i--) {
            while(!s.empty() && s.top() != -1 && v[s.top()] > v[i])//here only > 
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;    
    }

    vector<int> prevsmaller(vector<int>& v) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(v.size(), -1);
        
        for(int i = 0; i < v.size(); i++) {
            while(!s.empty() && s.top() != -1 && v[s.top()] >= v[i]) //here >=
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i); 
        }
        return ans;   
    }

    vector<int> nextgreater(vector<int>& v) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(v.size(), -1);
        
        for(int i = v.size() - 1; i >= 0; i--) {
            while(!s.empty() && s.top() != -1 && v[s.top()] < v[i])//here only > 
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;    
    }

    vector<int> prevgreater(vector<int>& v) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(v.size(), -1);
        
        for(int i = 0; i < v.size(); i++) {
            while(!s.empty() && s.top() != -1 && v[s.top()] <= v[i]) //here >=
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i); 
        }
        return ans;   
    }
    long long sumSubarrayMins(vector<int>& arr) {
        auto nextSmaller = nextsmaller(arr);
        auto prevSmaller = prevsmaller(arr);

        long long sum = 0; // Sum of all subarray minimum elements
        // const int mod = 1e9 + 7;

        for(int i = 0; i < arr.size(); i++) {
            long long nexti = nextSmaller[i] == -1 ? arr.size() : nextSmaller[i];
            long long previ = prevSmaller[i];
            long long left = i - previ;
            long long right = nexti - i;
            // long long nooftimes = (left % mod * right % mod) % mod;
            // long long total = (nooftimes * arr[i]) % mod; 
            // sum = (sum + total) % mod;
            sum += left*right*arr[i];
        }
        return sum;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
       auto nextSmaller = nextgreater(arr);
        auto prevSmaller = prevgreater(arr);

        long long sum = 0; // Sum of all subarray minimum elements
        // const int mod = 1e9 + 7;

        for(int i = 0; i < arr.size(); i++) {
           long long nexti = nextSmaller[i] == -1 ? arr.size() : nextSmaller[i];
            long long previ = prevSmaller[i];
            long long left = i - previ;
            long long right = nexti - i;
            sum += left*right*arr[i];
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) 
    {
        auto sumofmaximums = sumSubarrayMaxs(nums);
        auto sumofminimums = sumSubarrayMins(nums);
        return sumofmaximums-sumofminimums;
    }
};