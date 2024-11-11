    #include <bits/stdc++.h>
    using namespace std;

    int getsum(int n)
    {
        //base case
        if(n==0 || n==1)
        {
            return n;
        }
        //recursive case
        int recursionkaanswer=getsum(n-1);
        int sum=n+recursionkaanswer;
        return sum;
    }
    int main()
    {
        int n;
        cout << "enter the value of n:" << endl;
        cin >>n;

        int f=getsum(n);

        cout << "sum is:" << f;
        return 0;
    }