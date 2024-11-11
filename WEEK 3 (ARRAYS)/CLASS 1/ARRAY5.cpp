    //count 1s and 0s in an array
    #include <iostream>
    using namespace std;

    int count_of_zero(int arr[],int n)
    {
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            {
                count++;
            }
        }
        return count;
    }

    int count_of_one(int arr[],int n)
    {
        int count=1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==1)
            {
                count++;
            }
        }
        return count;
    }

    int main()
    {
        int arr[]={1,0,1,0,1,0,1,0,1,0};
        int n=sizeof(arr)/sizeof(arr[0]);

        int o=count_of_zero(arr,n);
        int i=count_of_one(arr,n);

        cout << "no of zeroes:" << o << endl;
        cout << "n of ones:" << i;

        return 0;
    }