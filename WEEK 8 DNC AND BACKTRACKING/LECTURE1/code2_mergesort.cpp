    #include <bits/stdc++.h>
    using namespace std;

    void merge(int arr[], int s, int e, int mid)
    {
        //create left and right array
        int leftlength = mid-s+1;
        int rightlength = e-mid;

        int *leftarr = new int [leftlength];//heap is created because of good practise
        int *rightarr = new int [rightlength];

        //fill or copy the left and right arrays
        //copy original array->values
        int index=s;
        //copying into left wala array
        for(int i = 0;i<leftlength; i++)
        {
            leftarr[i]=arr[index];
            index++;
        }
        //copying into right wala arrayf 
        index=mid+1;
        for(int i = 0; i<rightlength; i++)
        {
            rightarr[i] = arr[index];
            index++;
        }
         
        //mergelogic->merget two sorted array wala same code
        int i = 0;
        int j = 0;
        int mainarrayindex = s;
        
        while(i<leftlength && j<rightlength)
        {
            if(leftarr[i]<rightarr[j])
            {
                arr[mainarrayindex] = leftarr[i];
                i++;
                mainarrayindex++;
            }
            else
            {
                arr[mainarrayindex] = rightarr[j];
                j++;
                mainarrayindex++;
            }
        }
        //copy rest of the elements
        while(i<leftlength)
        {
            arr[mainarrayindex] = leftarr[i];
            i++;
            mainarrayindex++;
        }
        while(j<rightlength)
        {
            arr[mainarrayindex] = rightarr[j];
            j++;
            mainarrayindex++;
        }

        //delete heap memory
        delete[] leftarr;
        delete [] rightarr;
    }

    void mergesort(int arr[], int s, int e)
    {
        //base case
        if(s>=e)//single element and invalid element
        {
            return ;
        }
        int mid = (s+e)/2;
        //left part recursion se solve karwao
        mergesort(arr, s, mid);
        //right part recursion se solve karwao
        mergesort(arr, mid+1, e);
        //dono parts ko merge karwa do
        merge(arr, s, e, mid);
    }

    int main()
    {
        int arr[] = {10,80,110,90,50,30,40,20};
        int n = sizeof(arr)/sizeof(arr[0]);

        cout<< "before sorting" << endl;
        for(int i = 0;i<n;i++)
        {
            cout << arr[i] << " ";
        }

        mergesort(arr,0,n-1);

        cout<< endl<<"after sorting" << endl;
        for(int i = 0;i<n;i++)
        {
            cout << arr[i] << " ";
        }
        return 0;
    }