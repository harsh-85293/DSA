    #include <iostream>
    using namespace std;
    #include <array>

    int main()
    {
        int basic[3]={1,2,3};
        array<int,4> a={1,2,3};

        int size=a.size();
        for(int i=0;i<size;i++)
        {
            cout <<  a[i] << endl;
        }

        cout << "element at 2nd index:" << a.at(2) << endl;

        cout << "empty or not:" << a.empty() << endl;

        cout << "1st element:" << a.front() <<endl;

        cout << "last element:" <<a.back() << endl;//if no element is there so 0 will be there default

        return 0;
    }