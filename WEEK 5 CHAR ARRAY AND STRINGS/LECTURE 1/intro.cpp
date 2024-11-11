    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        //creation 
        char arr[100];

        cout << "enter your name:" << endl;

        //input
        //cin >> arr;

        // cin.getline(arr,100);//to remove delimeter of character array
        // cin.getline(arr,8);//will only take 8 characters for input

        cin.getline(arr,12,'a');//delimeter='a

        //output
        cout << "your name is " << arr << endl;

    //depicting chracter's ascii value to show null character;s ascii value (ascii value=0)
        cout << (int)arr[0] << endl;
        cout << (int)arr[1] << endl;
        cout << (int)arr[2] << endl;
        cout << (int)arr[3] << endl;
        cout << (int)arr[4] << endl;
        cout << (int)arr[5] << endl;

        return 0;
    }