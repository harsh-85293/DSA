    #include <iostream>
    using namespace std;
    int main()
    {
        int n=234;
        int a=1;
        int b=0;
        int u;

        while(n>0)
        {
            u=n%10;
            a=a*u;
            b=b+u;
            n=n/10;
        }
        int c=a-b;
        cout << c;

        return 0;
    }