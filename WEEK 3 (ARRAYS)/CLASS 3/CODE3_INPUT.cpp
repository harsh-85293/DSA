        #include <iostream>
        using namespace std;
        int main()
        {
            int arr[2][3];
            int m=2;
            int n=3;
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout << "enter input for row " << i << " and column " << j << ":" << " ";
                    cin >> arr[i][j]; 
                }
            }
            cout << "PRINTING 2D ARRAY:" << endl;
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout << "element at row "<< i <<  " and column " << j << " is:" << arr[i][j] << " "; 
                    cout << endl;
                }
            }      
              
            return 0;
        }