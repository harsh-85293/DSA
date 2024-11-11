    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        char arr1[1000];
        cout << "enter input:" << endl;
        cin >> arr1;
        cout << arr1;

        char arr2[1000];
        cout << "enter input:" << endl;
        cin >> arr2;
        cout << arr2;
        
        cout << strcat(arr1,arr2) << endl;//first function

        cout << strlen(arr1);//for length

        cout<< strcmp(arr1,arr2);
        return 0;
    }