    #include <iostream>
    using namespace std;

    int fib(int n)
    {
        return (n-1)+(n-2);
    }
    int main()
    {
        int n;
        cout << "enter n:";
        cin >>n;

        int a,b;

        a=0;
        b=1;
        cout << a << " " << b << " ";

        for(int i=1;i<=n;i++)
        {
            int sum=a+b;
            cout << sum << " ";
            a=b;
            b=sum;
        }
        return 0;
    }