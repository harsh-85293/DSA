    //IMPLICIT TYPE CASTING(CONVERSION AUTOMATICALLY TO LARGE)
    #include <iostream>
    using namespace std;

    int main()
    {
        int n1=10;
        float n2=5.5;

        float res;
        int result;

        res=n1+n2;
        result =n1+n2;

        cout << res << endl;//implicit
        cout << result << endl;

        return 0;
    }