#include <bits/stdc++.h>

int noofstudents(vector<int>& arr, int pages){
    int student = 1;
    int pageststudent = 0;
    int n = arr.size();

    for(int i = 0; i <= n - 1; i++){
        if(pageststudent + arr[i] <= pages){
            pageststudent += arr[i];
        }

        else{
            student++;
            pageststudent = arr[i];
        }
    }
    return student;
}

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m > n){
        return -1;
    }
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while(low <= high){
        int mid = low + (high - low)/2;
        int noofstudent = noofstudents(arr, mid);

        if(noofstudent > m){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}