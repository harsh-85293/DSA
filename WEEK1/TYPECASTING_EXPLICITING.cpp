    //EXPLICIT TYPE
    #include <iostream>
    using namespace std;
    int main()
    {
        float n1=10;
        float n2=5.5;
        float res=n1+(int)n2;//explicit type
        cout << res << endl;

        double pi=3.14529436;
        int intpi=(int)pi;
        cout << intpi << endl;

        float floatn=65.35;
        char chr=(char)floatn;
        cout << chr << endl;

        int a=10;
        int b=3.0;
        float c=a/(float)b;//int /float =float
        cout << c << endl;
        return 0;
    }