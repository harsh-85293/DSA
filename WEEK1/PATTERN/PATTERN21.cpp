    //min pyramid
    #include<iostream>
    using namespace std;

    void minpyramid(int n)
    {
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<n-row;col++)//1
            {
                cout << "*";
            }
            for(int col=0;col<(2*row+1);col++)
            {
                cout << " ";
            }
            for(int col=0;col<n-row;col++)//same as 1
            {
                cout << "*";
            }

            cout << endl;
        }
        
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<(row+1);col++)
            {
                cout << "*";
            }
            for(int col=0;col<2*(n-row)-1;col++)
            {
                cout << " ";
            }
            for(int col=0;col<row+1;col++)
            {
                cout << "*";
            }

            cout << endl;
        }
    }

    

    int main() 
    {
        int n;
        cout << "enter N:"<< endl;
        cin >>n;        
        minpyramid(n);
        return 0;
    }
