    //2 pointer approach
    #include <iostream>
    using namespace std;
    int main()
    {
        int n;
        int arr[]={10,20,30,40,50,60,70};
        n=sizeof(arr)/sizeof(arr[0]);

        int i=0;
        int j=n-1;

        cout << "elements are:" << endl;
        while(i<=j)//remember = here
        {
            if(i==j)
            {
                cout << arr[i];
                i++;
            }
            else
            {
                cout << arr[i] << " ";
                cout << arr[j] << " ";
                i++;
                j--;
            }
        }
        return 0;
    }