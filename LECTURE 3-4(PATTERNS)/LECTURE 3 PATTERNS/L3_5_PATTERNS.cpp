    #include <iostream>
    using namespace std;
    int main()
    {
        int n;
        cout << "enter n:";
        cin>>n;
        int a=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout <<n-j+1;//reversed pattern
            }
            cout << endl;
        }
        return 0;
    }