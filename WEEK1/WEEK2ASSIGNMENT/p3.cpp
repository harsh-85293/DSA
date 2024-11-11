    #include <iostream>
    using namespace std;
    int main()
    {
        int n,row;
        cout << "enter n:";
        cin >>n;
        
        //p-1
        for(row=0;row<n;row++)
        {
            for(int col=0;col<row;col++)
            {
               cout << "*";
            }
            for(int col=0;col<2*(n-row);col++)
            {
               cout << " ";
            }
            for(int col=0;col<row;col++)
            {
               cout << "*";
            }
            cout << endl;
        }
        for(row=n;row>1;row--)
        {
            for(int col=0;col<row;col++)
            {
               cout << "*";
            }
            for(int col=0;col<2*(n-row);col++)
            {
               cout << " ";
            }
            for(int col=0;col<row;col++)
            {
               cout << "*";
            }
            cout << endl;
        }
        return 0;
    }