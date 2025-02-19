    #include <iostream>
    using namespace std;
    int main()
    {
        int n;
        cout << "enter n:";
        int a;
        cin>>n;
    
        for(int i=1;i<=n;i++)
        {
            a=i;
            for(int j=1;j<=i;j++)
            {
                cout << i+1-j <<  " ";
                a++;
            }
            cout << endl;
        }
        return 0;
    }