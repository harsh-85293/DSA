    #include <iostream>
    using namespace std;
    int main()
    {
        int n;
        cout << "enter n:";
        cin>>n;
        char ch='x';
    
        for(int i=1;i<=n;i++)
        {
            for(int j=n;j>=i;j--)
            {
                cout << ch;
            }
            for(int j=1;j<=(n-j);j++)
            {
                cout <<" ";
            }
            cout << endl;
        }
        return 0;
    }