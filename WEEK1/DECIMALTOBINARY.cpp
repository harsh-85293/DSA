    #include <iostream>
    #include <cmath>
    using namespace std;
    
    //method1
    int decimaltobinary1(int n)
    {
        int binaryno=0;
        int bit;
        int i=0;

        while(n>0)
        {
            bit=n%2;
            binaryno=bit*pow(10,i++)+binaryno;
            n=n/2;   
        }
        return binaryno;
    }
    //method2
    int decimaltobinary2(int n)
    {
        int binaryno=0;
        int bit;
        int i=0;

        while(n>0)
        {
            bit=n&1;
            binaryno=bit*pow(10,i++)+binaryno;
            n=n>>1;   
        }
        return binaryno;
    }
    
    int main()
    {
        int n;
        cout << "enter decimal number:" << endl;
        cin >> n;
        cout << "your number is:" << decimaltobinary1(n) << endl;

        cout << "enter decimal number:" << endl;
        cin >> n;
        cout << "your number is:" << decimaltobinary2(n) << endl;
        
        return 0;
    }