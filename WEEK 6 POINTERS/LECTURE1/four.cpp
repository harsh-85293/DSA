//question3
    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
        int a=5;
        int *p=&a;
        //copying pointers
        int *q=p;

        cout << "a:" << a << endl;
        cout << "&a" << &a  << endl;
        // cout << "*a" << *a  << endl;->error
        cout << "p" << p  << endl;
        cout << "&p" << &p  << endl;
        cout << "*p" << *p  << endl;
        cout << "q" << q  << endl;
        cout << "&q" << &q  << endl;
        cout << "*q" << *q  << endl;
        return 0;
    }