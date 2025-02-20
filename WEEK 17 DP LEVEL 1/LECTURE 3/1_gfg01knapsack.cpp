//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solveusingrecursion(vector<int> &val, vector<int> &wt, int capacity, int index){
        //base case
        //single item
        if(index == 0){
            if(wt[0] <= capacity){
                return val[0];
            }
            else{
                return 0;
            }
        }
        
        //include exclude pattern:
        //include 
        int incl = 0;
        if(wt[index] <= capacity){
            incl = val[index]  + solveusingrecursion(val, wt, capacity - wt[index], index - 1);
        }
        
        //exclude
        int exc = 0 + solveusingrecursion(val, wt, capacity , index - 1);
        
        int finalans = max(incl, exc);
        return finalans;
    }//2-d dp
    
    int solveusingMem(vector<int> &val, vector<int> &wt, int capacity, int index, vector<vector<int>>&dp){
        //base case
        //single item
        if(index == 0){
            if(wt[0] <= capacity){
                return val[0];
            }
            else{
                return 0;
            }
        }
        
        //check if answer already exist
        if(dp[capacity][index] != -1){
            return dp[capacity][index];
        }
        
        //include exclude pattern:
        //include 
        int incl = 0;
        if(wt[index] <= capacity){
            incl = val[index]  + solveusingMem(val, wt, capacity - wt[index], index - 1, dp);
        }
        
        //exclude
        int exc = 0 + solveusingMem(val, wt, capacity , index - 1, dp);
        
        dp[capacity][index] = max(incl, exc);
        return dp[capacity][index];
    }
    
    int solveusingtab(int capacity, vector<int> &val, vector<int> &wt){
        
        //step 1 : create and pass 2-d dp array
        
        int n = val.size();
        vector<vector<int>>dp(capacity + 1, vector<int>(n, 0));
        //step 2 : analyze base case 
        for(int w = wt[0]; w <= capacity; w++){
            dp[w][0] = val[0];
            
        }
        
        //step 3 : parameter range reverse logic
        // capacity : W to 0 and index n-1 to 0
        for(int w = 0; w <= capacity; w++){
            
            for(int index = 1; index <= n-1; index++){
                
                int incl = 0;
                if(wt[index] <= w){
                    incl = val[index]  + dp[w - wt[index]][index - 1];
                }
                
                //exclude
                int exc = 0 + dp[w][index - 1];
                
                //step 2 : in final answer store and return answer
                dp[w][index] = max(incl, exc);
            }
        }
        return dp[capacity][n-1];
    }
    
    int solveusingso(int capacity, vector<int> &val, vector<int> &wt){
        //step 1 : create and pass 2-d dp array
        
        int n = val.size();
        
        vector<int>prev(capacity + 1, 0);
        vector<int>curr(capacity + 1, 0);
        
        //step 2 : analyze base case 
        for(int w = wt[0]; w <= capacity; w++){
            prev[w] = val[0];
            
        }
        
        //step 3 : parameter range reverse logic
        // capacity : W to 0 and index n-1 to 0
        for(int index = 1; index <= n-1; index++){
            for(int w = 0; w <= capacity; w++){
                int incl = 0;
                if(wt[index] <= w){
                    incl = val[index]  + prev[w - wt[index]];
                }
                //exclude
                int exc = 0 + prev[w];
                //step 2 : in final answer store and return answer
                curr[w] = max(incl, exc);
            }
            prev = curr;
        }
        return prev[capacity];
    }
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        int index = n - 1;
        // return solveusingrecursion(val, wt, capacity, index);
        
        //step 1 : create and pass 2-d dp array
        // vector<vector<int>>dp(capacity + 1, vector<int>(n, -1));
        // return solveusingMem(val, wt, capacity, index, dp);
        
        return solveusingso(capacity,val, wt);
    }
};

//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapSack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends