    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        //integer creation using stack memory
        int a=5;
        cout << a << endl;

        //integer->heap memory
        int *p=new int;  
        *p=5;
        cout << *p << endl;

        //deallocate memory in heap
        delete p;
        
        return 0;
    }