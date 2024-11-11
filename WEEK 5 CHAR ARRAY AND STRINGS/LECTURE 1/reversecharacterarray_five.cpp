    #include <bits/stdc++.h>
    using namespace std;

    int getlength(char arr[],int size)
    {
        int count=0;
        int index=0;
        while(arr[index]!='\0')
        {
            count++;
            index++;
            //jab tak array mai null chatracter nhi milta count ko increase karo fir stop
        }
        return count;
    }

    void reversecharacterarray(char arr[],int size)
    {
        int len=getlength(arr,size);
        int s=0;
        int e=len-1;

        while(s<e)
        {
            swap(arr[s],arr[e]);
            s++;
            e--;
        }
    }

    int main()
    {
        char arr[100];

        cout << "enter then character array:" << endl;
        cin >> arr;

        reversecharacterarray(arr,1000);

        cout << "array after reverse is:" << arr << endl;
        
        return 0;
    }