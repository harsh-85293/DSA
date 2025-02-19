   //scoops in arrays
    #include <iostream>
    using namespace std;

    void printarray(int arr[],int n)
    {
        for(int i=0;i<n;i++)
        {
            cout << arr[i] << endl;
        }
        cout << "printing done" << endl;
    }

    void update (int arr[],int n)
    {
        cout << "inside the function" << endl;
        arr[0]=120;

        for(int i=0;i<n;i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "coming back to main function" << endl;
    }

    int main()
    {
        int arr[3]={1,2,3};
        update(arr,3);

        cout << "printing inside main function" << endl;

        for(int i=0;i<3;i++)
        {
            cout << arr[i] << " ";
        }
        return 0;
    }

