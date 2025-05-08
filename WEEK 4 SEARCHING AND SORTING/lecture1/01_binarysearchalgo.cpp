    // Binary search
    #include <bits/stdc++.h>
    using namespace std;

    bool binarysearch(int arr[], int n, int target) 
    {
        int start = 0;
        int end = n - 1;
        
        while (start <= end) 
        {
            int mid = start + (end - start) / 2; // Avoids overflow

            if (arr[mid] == target) 
            {
                return true;
            } 

            else if (target < arr[mid]) 
            {
                end = mid - 1;
            } 

            else 
            {
                start = mid + 1;
            }
        }
        return false;
    }

    int main() 
    {
        int n, target;
        
        cout << "Enter the size of the array: ";
        cin >> n;

        int arr[n];
        cout << "Enter the elements of the array in sorted order:\n";
        for (int i = 0; i < n; i++) 
        {
            cout << "Enter " << (i + 1) << " element: ";
            cin >> arr[i];
        }

        cout << "The sorted array is: ";
        for (int i = 0; i < n; i++) 
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "Enter the target: ";
        cin >> target;

        bool found = binarysearch(arr, n, target);

        cout << "The result of binary search is: " << found  << endl;

        return 0;
    }