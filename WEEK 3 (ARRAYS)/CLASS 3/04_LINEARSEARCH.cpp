    #include <iostream>
    using namespace std;

    bool search2darray(int arr[][4],int m,int n,int target)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][j]==target)
                {
                    return true;
                }
            }
        }
        return false;
    }

    int main()
    {
        int arr[3][4]={ {10,11,12,13},
                        {20,21,22,23},
                        {31,32,44,55}
                      };
        int m=3;
        int n=4;
        int target=404;
        
        bool ans=search2darray(arr,m,n,target);

        cout << "answer is:" << ans << endl;
        
        return 0;
    }