    //second approach
    #include <iostream>
    using namespace std;

    // void pattern1(int arr[],int n)
    // {
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<n;j++)
    //         {
    //             cout << arr[i] << "," << arr[j];
    //             cout << endl;
    //         }   
    //     }
    // }

    // void pattern2(int arr[],int n)
    // {
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<i;j++)
    //         {
    //             cout << arr[i] << "," << arr[j];
    //             cout << endl;
    //         }   
    //     }
    // }

    //   void pattern3(int arr[],int n)
    // {
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<=i;j++)
    //         {
    //             cout << arr[i] << "," << arr[j];
    //             cout << endl;
    //         }   
    //     }
    // }

    // void pattern4(int arr[],int n)
    // {
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=n-1;j>=0;j--)
    //         {
    //             cout << arr[i] << "," << arr[j];
    //             cout << endl;
    //         }   
    //     }
    // }

      void pattern5(int arr[],int n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>i;j--)
            {
                cout << arr[i] << "," << arr[j];
                cout << endl;
            }   
        }
    }


    int main()
    {
        int n=4;
        int arr[n]={10,20,30,40};
        //pattern1(arr,n);
        pattern5(arr,n);
        return 0;
    }