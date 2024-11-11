    #include <iostream>
    using namespace std;

    int main()
    {
        int  n;
        cout << "enter n:";
        cin >>n;
        for(int row=0;row<n;row++)
        {
            for(int col=1;col<=2*row+1;col++)
            {
                if(col%2==0)
                {
                    cout << "*";
                }
                else
                {
                    cout << (row+1);
                }
            }

            cout << endl;
        }
        return 0;
    }