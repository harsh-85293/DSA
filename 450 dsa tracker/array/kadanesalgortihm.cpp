//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) 
    {
        // code here...
        long long sum=0;
        long long finalans=INT_MIN;
        int negativecount=0;
        int maxi=INT_MIN;
        
        for (int i = 0; i < arr.size(); i++) 
        {
            sum+=arr[i];
            
            if (sum < 0) 
            {
                sum=0;
            }
            finalans=max(finalans,sum);
            
            if(arr[i]<0)
            {
                negativecount++;
            }
            maxi=max(maxi,arr[i]);
        }
        
        if(negativecount==arr.size())
        {
            finalans=maxi;
        }
        return finalans;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}
// } Driver Code Ends