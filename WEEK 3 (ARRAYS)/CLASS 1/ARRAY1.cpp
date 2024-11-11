    #include <iostream>
    using namespace std;
    int main()
    {
        ///declarations
        int g[9];//int arr[];<-worng
        int h[]={1,2,3};
        int arr[3]={10,20,30};

        //input and output:
        int n;
        cout << "enter n:";
        cin >>n;
        for(int i=0;i<n;i++)
        {
            cout << "enter " << i+1 << " element:";
            cin >> arr[i];
        }

         for(int i=0;i<n;i++)
        {
            cout << i+1 << " element:" << arr[i];
            cout << endl;
        }
        
        //fill:
        fill(arr,arr+3,23);
        cout <<  "elements are:"<< endl; 
        for(int i=0;i<3;i++)
        {
            cout << arr[i] << endl;
            cout << i[arr] << endl;
        }


        return 0;
    }