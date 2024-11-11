    //finding maximum and minimum in array:

      #include <iostream>
      #include <algorithm>
      using namespace std;

      int FINDMAXIMUM(int arr[],int n)
      {
        int maxans=INT16_MIN;
        for(int i=0;i<n;i++)
        {
            // if(arr[i]>max)
            // {
            //     max=arr[i];
            // }
            maxans=max(arr[i],maxans);//max inbuilt present in #include <algorithm>
        }
        return maxans;
      }

      int FINDMINIMUM(int arr[],int n)
      {
        int minans=INT16_MAX;
        for(int i=0;i<n;i++)
        {
            // if(arr[i]<minans)
            // {
            //     max=arr[i];
            // }
            minans=min(arr[i],minans);//max inbuilt present in #include <algorithm>
        }
        return minans;
      }

      int main()
      {
        int m;
        cout << "enter no of elements of array:";
        cin >> m;

        int a[m];

        cout << "enter elements of array:" << endl;
        for(int i=0;i<m;i++)
        {
            cout << "enter the value of " << (i+1) << " element:" ;
            cin >> a[i];
        }

        int h=FINDMAXIMUM(a,m);
        cout << "maximum element is:" << h << endl;

        int z=FINDMINIMUM(a,m);
        cout << "minimum element is:" << z << endl;
        return 0;
      }