    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        //2d array->stack memory
        // int arr[2][4]={ {2,4,6,8} , {1,2,3,4} };
    
        //2d array->heap memory
        int **arr= new int*[4];//array of int*(pointer to integer) of size 10

        //4->row and 3->column 
        for(int i=0;i<4;i++)
        {
            //har ek pointer ke liye 1d array create hoga
            arr[i]=new int[3];
        }

        //taking input
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin >> arr[i][j] ; 
            }
        }

        //displaying output
        cout << "your 2d array is:" << endl;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout << arr[i][j] << ' '; 
            }
            cout << endl;
        }

        //for making eachn1d array in 2d array free otherwise memory leak will occur
        for(int i=0;i<4;i++)
        {
            delete[]arr[i];
        }
        return 0;
    }