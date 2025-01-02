    #include <bits/stdc++.h>
    using namespace std;

    void printarray(int arr[], int size, int index)
    {
        //base case
        if(index == size)
        {
            //array se bahar
            return;
        }
        //recursive relation
        cout << arr[index] << " ";//1 case mai sambhalunga
        printarray(arr, size, index + 1);//baaki case recursion sambhal lega
        //processing
    }
   
    int main()
    {
        int arr[]={10, 20, 30, 40, 50, 60};
        int size = 6;
        int index = 0;

        printarray(arr, size, index);
        return 0;
    }