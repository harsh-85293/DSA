    #include <iostream>
    using namespace std;

    void rowsum(int arr[][3],int rowsize,int colsize)
    {
        for(int row=0;row<rowsize;row++)
        {
            int sum=0;
            for(int col=0;col<colsize;col++)
            {
                sum+=arr[row][col];
            }
            cout << "the sum of "<< row <<" row is:" << sum << endl;
        }
    }

     void diagonalsum(int arr[][3],int rowsize,int colsize)
    {
        int sum=0;
        for(int row=0;row<rowsize;row++)
        {    
            for(int col=0;col<colsize;col++)
            {
                if(row==col)
                {
                    sum+=arr[row][col];
                }
            }
        }
        cout << "the sum of diagonal is:" << sum << endl;
    }

    void columnsum(int arr[][3],int rowsize,int colsize)
    {
        for(int col=0;col<colsize;col++)
        {
            int sum=0;
            for(int row=0;row<rowsize;row++)
            {
                sum+=arr[row][col];
            }
            cout << "the sum of "<< col <<" column is:" << sum << endl;
        }
    }

    void ultadiagonalsum(int arr[][3],int rowsize,int colsize)
    {
        int sum=0;
        for(int row=0;row<rowsize;row++)
        {    
            for(int col=0;col<colsize;col++)
            {
                if((col+row+1)==rowsize)
                {
                    sum+=arr[row][col];
                }
            }
        }
        cout << "the sum of diagonal is:" << sum << endl;
    }

    int main()
    {
        int m=3;
        int n=3;
       
        int arr[3][3]={{10,20,30},
                       {40,80,80},
                       {20,40,60}
        };
        
        rowsum(arr,m,n);
        columnsum(arr,m,n);
        diagonalsum(arr,m,n);
        ultadiagonalsum(arr,m,n);
        return 0;
    }