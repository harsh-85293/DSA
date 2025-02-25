    //second approach
    #include <iostream>
    using namespace std;

    void printtrianglepairs(int arr[],int n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
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
        printtrianglepairs(arr,n);
        return 0;
    }