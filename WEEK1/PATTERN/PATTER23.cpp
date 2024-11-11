    #include <iostream>
    using namespace std;

    int main()
    {
        int n;
        char s='A';
        cout  << "enter n:";
        cin >> n;

        for(int row=0;row<n;row++)
        {
            char s='A';
            for(int col=0;col<=row;col++)
            {
                cout << char(s) ;
                s++;
            }

            s--;

            while(s>'A')
            {
                s--;
                cout << s;
            }

            cout << endl;
        }
        return 0;
    }