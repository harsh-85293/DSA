   //scoops in arrays
    #include <iostream>
    using namespace std;

    void printarray(int arr[],int n)
    {
        for(int i=0;i<n;i++)
        {
            cout << arr[i] << endl;
        }
    }

    void reverse(int arr[],int n)
    {
        int start=0;
        int end=n-1;
        while(start<end)
        {
            swap(arr[start],arr[end]);
            start++;
            end--;
        }
    }

    int main()
    {
        int arr[3]={1,2,3};

        cout << "printing before reversing" <<  endl;
        printarray(arr,3);
        
        reverse(arr,3);
        
        cout << "printing after reversing" << endl;
        printarray(arr,3);
        
        return 0;
    }

