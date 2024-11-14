    //question in hacker rank
    #include <bits/stdc++.h>
    using namespace std;

    /*
    * Complete the 'countInversions' function below.
    *
    * The function is expected to return a LONG_INTEGER.
    * The function accepts INTEGER_ARRAY arr as parameter.
    */
    //TIME LIMIT WILL BE EXCEEDED
    //TC = O(N^2)
    //SC = O(1)
    long countInversions(vector<int> arr) {
        long n = arr.size();
        long count = 0;
        for(long i=0; i<n; i++)
        {
            for(long j = i+1; j<n; j++)
            {
                if(arr[i] > arr[j])
                {
                    count++;
                }
            }
        }
        return count;
    }

