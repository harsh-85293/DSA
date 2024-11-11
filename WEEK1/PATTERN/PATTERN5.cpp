    //hollow rectangle pattern
    #include <iostream>
    using namespace std;
    int main()
    {
        int r,c;

        cout << "enter no of rows:" <<endl;
        cin >> r;

        cout << "enter no of columns:" << endl;
        cin >> c;

        for(int row=0;row<r;row++)
        {
            for(int col=0;col<c;col++)
            {
                if(row==0 || row==r-1)
                {
                    cout << "*";
                }
                else
                {
                    if(col==0 || col==c-1)
                    {
                        cout << "*";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
            }
            cout << endl;
        }

        return 0;
    }