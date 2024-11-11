    #include <iostream>
    #include <cmath>
    using namespace std;
    
    int binarytodecimal(int n)
    {
        int decimalno=0;
        int bit;
        int i=0;

        while(n)//while n!=0
        {
            bit=n%10;
            decimalno=bit*pow(2,i++)+decimalno;
            n=n/10;   
        }
        return decimalno;
    }
    
    
    int main()
    {
        int n;
        cout << "enter binary number:" << endl;
        cin >> n;
        cout << "your number is:" << binarytodecimal(n) << endl;

        
        
        return 0;
    }