    //hollow square pattern
    #include <iostream>
    using namespace std;
    int main()
    {
        int r;
        cout << "enter number of sides:" ;
        cin >> r;

        for(int row=0;row<r;row++)
        {
            for(int col=0;col<r;col++)
            {
                if(row==0 || row==r-1)
                {
                    cout << "*";
                }
                else
                {
                    if(col==0 || col==r-1)
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