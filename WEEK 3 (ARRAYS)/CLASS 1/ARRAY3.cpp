    //linear search
    #include <iostream>
    using namespace std;
    
    //function and array
    void print(int arr[],int size)//remember arr[]
    {
        for(int i=0;i<size;i++)
        {
            cout <<"element " << (i+1) << ":"<< arr[i] << endl;
        }
    }

    bool checkelement(int arr[],int size,int target)
    {
        for(int i=0;i<size;i++)
        {
            int g=arr[i];
            if(g==target)
            {
                return true;//return breaks automatically
                break;
            }
        }
        return false;

        
       }
    
    int main()
    {
        int arr[]={10,20,30,40,50};
        int size=5;
        bool k=checkelement(arr,size,60);
        cout  << "answer:"<< k << endl;
        print(arr,size);//remember arr
        return 0;
    }