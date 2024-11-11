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

    int main()
    {
        char arr[1000];
        cout << "enter the characters:" << endl;
        cin >> arr;

        cout << getlength(arr,1000) << endl;
        return 0;
    }

