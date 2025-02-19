    #include <iostream>
    using namespace std;

    #include <array>

    int main()
    {
       int basic[3]={1,2,3};// basic array

       // stl array:-
       
       //declaration
       array<int,4> a={1,2,3,5};

       //size of array
       int size=a.size();
       
       //accessing array
       for(int i=0;i<size;i++)
       {
          cout << a[i] << endl;
       }

       cout << "element at index 2:" << a.at(2) << endl;
       
       cout << "empty or not:" << a.empty() << endl;

       cout << "first element:" << a.front() << endl;

       cout << "empty or not:" << a.front() << endl;

       cout << "last element:" << a.back() << endl;

       return 0;  
    }