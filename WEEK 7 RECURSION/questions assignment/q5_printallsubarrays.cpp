    #include <bits/stdc++.h>
    using namespace std;
    
    void printsubarray1(vector<int>&arr, int start, int end, int n)
    {
        //base case
        if(end==n)
        {
            return;
        }
        //1 case mai sambhalunga
        for(int i=start; i<=end; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        //baaki recursion sambhal lega
        printsubarray1(arr, start, end+1, n);
    }

    //s=1..., s=2... , s=3...
    void print_subarrays(vector<int>&arr)
    {
        int n=arr.size();
        for(int i=0; i<n; i++)
        {
            int j=i;
            printsubarray1(arr, i, j, n);
        }    
    }
        
    int main()
    {
        vector<int>arr = {1,2,3,4,5};   
        print_subarrays(arr);
        return 0;
    }