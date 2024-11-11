    #include <iostream>
    #include <vector>
    using namespace std;

    int main()
    {
        //vector as a 2d array
        vector < vector<int> > arr(5,        vector<int>(4,0));//4 columns
        //                     no of rows    (4,0)size of each row,initialization of values 

        int totalrows=arr.size();
        int totalcolumns=arr[0].size();//vector ke andar ke dabbe ka size

        vector<vector<int>> brr(4);

        brr[0] = vector<int>(4); 
        brr[1] = vector<int>(2); 
        brr[2] = vector<int>(5); 
        brr[3] = vector<int>(3); 

        int total_rows =brr.size();
        int total_columns=brr[0].size();
        return 0;
    }
