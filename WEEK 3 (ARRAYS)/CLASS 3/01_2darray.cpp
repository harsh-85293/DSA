    //2-d array
    #include <iostream>
    using namespace std;
    int main()
    {
        //declaration
        int arr[4][3]={10,20};

        //initialize
        int a[3][2]={{10,20},{30,40},{50,60}};

        cout << a[0][0]<< endl;

        //traversing array
        int m=3;//row size
        int n=2;//column size

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout << a[i][j] <<" ";
            }
            cout << endl;
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout << arr[i][j] <<" ";
            }
            cout << endl;
        }
        return 0;
    }