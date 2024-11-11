    #include <bits/stdc++.h>
    using namespace std;

    void replacecharacter(char originalchar,char newchar,char arr[],int size)
    {
        for(int i=0;i<size;i++)
        {
            if(arr[i]==originalchar)
            {
                arr[i]=newchar;
            }
        }
    }
    
    int main()
    {
        char arr[100];

        cout << "enter the character array:" << endl;
        cin >> arr;

        cout << "array before replacement:" << arr << endl;

        replacecharacter('@',' ',arr,100);

        cout << "array after replacement is:"<< arr;
        return 0;
    }