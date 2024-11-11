    #include <iostream>
    using namespace std;
    #include <algorithm>
    int main()
    {
        int arr[]={10,20,30,40,50,60,70,80,90};
        int n=9;
        int target=80;

        bool ans=binary_search(arr,arr+n,target);
        cout << "answer is:" << (ans==1?"true":"false") << endl;
        return 0;        
    }