    // reverse an array:
    #include <iostream>
    using namespace std;

    void printarray(int array[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    void reverse(int arr[], int n)
    {
        int i = 0;
        int j = n - 1;

        while (i < j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    int main()
    {
        int a[] = {1, 2, 3, 4, 5, 6};
        int n = sizeof(a) / sizeof(a[0]);
        printarray(a, n);
        reverse(a, n);
        printarray(a, n);
        return 0;
    }