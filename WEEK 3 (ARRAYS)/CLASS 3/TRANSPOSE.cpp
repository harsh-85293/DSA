    #include <iostream>
    using namespace std;

    // void transpose(int arr[][3],int rowsize,int colsize)
    // {
    //     int ans[100][100];
    //     for(int i=0;i<rowsize;i++)
    //     {
    //         for(int j=0;j<colsize;j++)
    //         {
    //             ans[i][j]=arr[j][i];
    //         }
    //     }

    //     for(int i=0;i<rowsize;i++)
    //     {
    //         for(int j=0;j<colsize;j++)
    //         {
    //             cout << ans[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    void tranposewithoriginalswap(int arr[][3],int rowsize,int colsize)
    {
       for(int i=0;i<rowsize;i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(arr[i][j],arr[j][i]);
            }
        }
        
        for(int i=0;i<rowsize;i++)
        {
            for(int j=0;j<colsize;j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    int main()
    {
        int m=3;
        int n=3;
       
        int arr[3][3]={{10,11,12},
                       {20,21,22},
                       {30,31,32}
        };

        tranposewithoriginalswap(arr,m,n);
        //transpose(arr,m,n);
        return 0;
    }