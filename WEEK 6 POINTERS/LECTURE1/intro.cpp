    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        int a=5;
        cout << &a << endl;
        cout << a << endl;
        int b=a;

        //int c=&a;error as int can't store address
        int *ptr=&a;// a pointer ptr is created which is pointing to an integer a
        
        return 0;
    }