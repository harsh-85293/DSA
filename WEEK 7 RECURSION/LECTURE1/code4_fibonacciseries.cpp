    #include <bits/stdc++.h>
    using namespace std;

    int fib(int n)
    {
        //base case
        if(n==0 || n==1)
        {
            return n;
        }

        //recursive relation
        // fib(n)=fib(n-1) +fib(n-2)
        int ans=fib(n-1) +fib(n-2);
        return ans;
        // processing
    }

    int main()
    {
        int s=fib(9) ;
        cout << s << endl;
        return 0;
    }