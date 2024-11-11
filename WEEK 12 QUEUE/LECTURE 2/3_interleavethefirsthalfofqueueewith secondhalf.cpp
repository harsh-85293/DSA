//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        vector<int>ans;
        queue<int>q2;
        
        int n = q.size();
        int half = n/2;
        
        while(half--)
        {
            int ele = q.front();
            q.pop();
            
            q2.push(ele);
        }
        //first half->q1 second half->q2
        int size=q.size();
        while(size--)
        {
            ans.push_back(q2.front());
            q2.pop();
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends