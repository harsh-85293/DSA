    #include <iostream>
    using namespace std;
    int main()
    {
        for(int i=0;i<4;i++)
        {
            cout << "hello" << endl;
            cout << "hi" << endl;
            continue;
            cout << "this will never be printed";
        }
        return 0;
    }  