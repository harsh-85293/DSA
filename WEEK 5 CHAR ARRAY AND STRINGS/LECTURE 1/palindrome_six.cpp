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

    bool checkpalindrome(char arr[],int size)
    {
        int len=getlength(arr,size);
        int i=0;
        int j=len-1;

        while(i<=j)
        {
            if(arr[i]==arr[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;//yaha tak aane ka matlab saare chaeracter check ho chuke hai
    }

    int main()
    {
        char word1[1000];

        cout << "enter the word:" <<endl;
        cin >> word1;

        cout << "palindrome or not:" << (checkpalindrome(word1,1000)==1)?cout<<"a palindrome":cout << "not a palindrome" << endl;
        return 0;
    }