    //creating 2d array with the help of vector   
    #include <iostream>
    #include <vector>
    using namespace std;

    bool search2darray(vector<vector<int>> &arr,int target)//& makes pass by reference
    {
        int rowsize=arr.size();
        int colsize=arr[0].size();

        for(int i=0;i<rowsize;i++)
        {
            for(int j=0;j<colsize;j++)
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
        vector<vector<int>> arr(4,vector<int>(3,0));
        int rowsize=arr.size();
        int colsize=arr[0].size();

        for(int i=0;i<rowsize;i++)
        { 
            for(int j=0;j<colsize;j++)
            {
                cin >> arr[i][j];
            }
            cout << endl;
        }
        int target=23;
        bool ans=search2darray(arr,target);

        cout << "answer is:" << ans << endl;

        return 0;
    }