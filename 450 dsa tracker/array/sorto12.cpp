    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        int arr[]={0 ,1 ,2 ,2, 1 ,0};
        int n=sizeof(arr)/sizeof(arr[0]);
        
        int countofzero=0,countofone=0,countoftwo=0;

        for (int i = 0; i < n; i++)  
        {
            if (arr[i] == 0) 
            {
                countofzero++;
            }
            if (arr[i] == 1) 
            {
                countofone++;
            }
            if (arr[i] == 2) 
            {
                countoftwo++;
            }
        }

        for (int i = 0; i < countofzero; i++) 
        {
            arr[i]=0;
        }

        for (int i = countofzero; i < countofone+countofzero; i++) 
        {
            arr[i]=1;
        }

        for (int i = countofone+countofzero; i < countoftwo+countofone+countofzero; i++) 
        {
            arr[i]=2;
        }


        for(int i=0;i<n;i++)
        {
            cout << arr[i] << " ";
        }

        return 0;
    }