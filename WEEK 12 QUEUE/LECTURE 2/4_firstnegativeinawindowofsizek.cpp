//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int k) 
{
    deque<long long int>q;
    vector<long long>ans;
    //index store karenge hum queue ke andar kyoki o hume bata dega
    //ki current element current window me hai ya nahi
    
    //step1 process first window
    for(int i=0; i<k; i++)
    {
        int ele=A[i];
        
        if(ele < 0)
        {
            q.push_back(i);
        }
    }
    //above window stores all the indexes of negative element inside
    //step2 process remaining window->ans removal / addition
    for(int i=k; i<N; i++)
    {
        //ans store
        if(q.empty())
        {
            ans.push_back(0);
        }
        else
        {
            int index=q.front();
            int ele=A[index];
            ans.push_back(ele);
        }
        //removal of elemeents which are not inside current window
        if(!q.empty() && i-q.front() >= k)
        {
            q.pop_front();
        }
        //now adition of eleement
        int ele=A[i];
        if(ele < 0)
        {
            q.push_back(i);
        }
    }
    //step 3
    //lastt window ka ans store karo manually
    if(q.empty())
    {
        ans.push_back(0);
    }
    else
    {
        int index=q.front();
        int ele=A[index];
        ans.push_back(ele);
    }
    return ans;
    
}