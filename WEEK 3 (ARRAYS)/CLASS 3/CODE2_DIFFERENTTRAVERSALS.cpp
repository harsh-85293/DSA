    #include <iostream>
    using namespace std;
    int main()
    {
        int arr[3][3]={{10,20,30},{110,120,130},{210,220,230}};
        int m=3;//row size
        int n=2;//column size

        //row wise
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                cout << arr[i][j]<< " ";
            }
            cout << endl;
        }

         //column wise
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout << arr[i][j]<< " ";
            }
            cout << endl;
        }

        
        //diagonal wise
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==j)
                {
                    cout << arr[i][j]<< " ";
                }
            }
            cout << endl;
        }


        return 0;
    }