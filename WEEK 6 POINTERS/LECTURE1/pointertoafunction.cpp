    #include <bits/stdc++.h>
    using namespace std;

    int addint(int n,int m)
    {
        return n+m;
    }
    int main()
    {
        int (*p)(int,int);//function pointer
        int sum=(*p)(2,3);
        return 0;
    }