    //full pyramid
    #include<iostream>
    using namespace std;

    void fullpyramid(int n)
    {
        for(int row=0 ; row<n ; row++)
        {
            for(int col=0 ; col< n-row-1 ; col++)
                cout << " ";

            for(int col=0 ; col< row+1 ; col++)
                cout << "* ";//note the space after * to not make stars adjacent

            cout << endl;
        }
    }

    int main() 
    {
        int n;
        cout << "enter N:"<< endl;
        cin >>n;        
        fullpyramid(n);
        return 0;
    }
