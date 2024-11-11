    #include <iostream>
    using namespace std;

    int FINDMINIMUM(int arr[][4],int rowsize,int colsize)
    {
        int minvalue=INT_FAST16_MAX;
        for(int i=0;i<rowsize;i++)
        {
            for(int j=0;j<colsize;j++)
            {
                minvalue=min(minvalue,arr[i][j]);
            }
       }
        return minvalue;
       
    }

     int FINDMAXIMUM(int arr[][4],int rowsize,int colsize)
    {
        int maxvalue=INT_FAST16_MIN;
        for(int i=0;i<rowsize;i++)
        {
            for(int j=0;j<colsize;j++)
            {
                maxvalue=max(maxvalue,arr[i][j]);
            }
        }
        return maxvalue;
    }

    int main()
    {   
        int m=3;
        int n=4;
       
        int arr[3][4]={{1,2,3,4},
                       {5,6,7,8},
                       {9,10,11,12}
        };
        
        int ans=FINDMINIMUM(arr,m,n);
        cout << "minimum value is:" << ans << endl;

        
        int res=FINDMAXIMUM(arr,m,n);
        cout << "maximum value is:" << res << endl;

        return 0;
    }