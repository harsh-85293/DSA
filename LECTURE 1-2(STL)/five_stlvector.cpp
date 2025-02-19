    #include <iostream>
    using namespace std;
    #include <vector>

    int main()
    {
        vector <int> v;//declaration of vector

        
        cout << "size of vector:" << v.size()<< endl;
        cout << "size:" << v.capacity() << endl;

        v.push_back(1);

        cout << "size:" << v.capacity();


        v.push_back(2);
        cout << "size of vector:" << v.size()<< endl;
        cout << "size:" << v.capacity() << endl;

        cout << "element at second index" << v.at(1)<< endl;

        cout << "front element:" << v.front() << endl;

        cout << "back element :" << v.back() << endl;

        cout << "before pop:" << endl;

        for(int i:v)
        {
            cout << i << " ";
        }
        cout << endl;

        v.pop_back();//follows queue order of pop

        cout << "after pop" << endl;

        for(int i:v)
        {
            cout << i << " ";
        }cout << endl;

        vector <int> a (5,1);

        vector <int> last(a);

        cout << "print last" <<endl;

        for(int i: last)
        {
            cout << i << " ";
        }cout << endl;
        return 0;
    }