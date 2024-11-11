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

    void converttouppercase(char arr[],int n)
    {
        int len=getlength(arr,n);
        for(int i=0;i<len;i++)
        {
            char ch=arr[i];
            //if letter is lowercase then only convert it
            if(ch>='a' && ch <='z')
            {
                ch=ch- 'a' + 'A' ;
            }
             arr[i]=ch;
        }
    }

    void converttolowercase(char arr[],int n)
    {
        int len=getlength(arr,n);
        for(int i=0;i<len;i++)
        {
            char ch=arr[i];
            //if letter is uppercase then only convert it
            if(ch>='A' && ch <='Z')
            {
                ch=ch- 'A' + 'a' ;
            }
             arr[i]=ch;
        }
    }

    int main()
    {
        char arr[1000];

        cout << "enter input:" << endl;
        cin >>arr;

       // converttouppercase(arr,1000);
        converttolowercase(arr,1000);

        cout << arr << endl;
        return 0;
    }