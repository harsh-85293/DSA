    //inverrted hollow diamond
    #include<iostream>
    using namespace std;

    void invertedhollowpyramid(int n)
    {
        for(int row=0 ; row<n ; row++)
        {
            for(int col=0 ; col< row+1 ; col++)
                cout << " ";

            for(int col=0 ; col< n-row ; col++)
            {
                if(row==n-1 || col==0 || col==n-row-1)
                {
                    cout << "* ";//note the space after * to not make stars adjacent
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }
    void hollowpyramid(int n)
    {
        for(int row=0 ; row<n ; row++)
        {
            for(int col=0 ; col< n-row-1 ; col++)
                cout << " ";

            for(int col=0 ; col< row+1 ; col++)
            {
                if(row==0 ||col==0 || col==row)
                {
                    cout << "* ";
                }
                else
                {
                    cout << "  ";
                }
            }

            cout << endl;
        }
    }

    void hollowdiamond(int n)
    {
        hollowpyramid(n);
        invertedhollowpyramid(n);
    }


    int main() 
    {
        int n;
        cout << "enter N:"<< endl;
        cin >>n;        
        hollowdiamond(n);
        return 0;
    }
