    #include <bits/stdc++.h>
    using namespace std;

    int getfactorial(int n)
    {
        //base case
        if(n==0 || n==1)
        {
            return 1;
        }
        //recursive call
        //fact(n)=n*fact(n-1)
        //bigproblem->fact(n)
        //small problem->fact(n-1)
        int recursionkaans = getfactorial(n-1);
        
        //processing
        int finalans = n * recursionkaans;
        
        return finalans;
    }

    int main()
    {
        int n;
        cout << "enter the value of n:";
        cin >> n;

        int ans=getfactorial(n);

        cout << "factorial of " << n << " is:" << ans;

        return 0;
    }