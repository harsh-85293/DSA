    // swap two numbers:
    #include <iostream>
    using namespace std;

    void swap(int *c, int *d)
    {
        int temp = *c;
        *c = *d;
        *d = temp;
    }

    int main()
    {
        int a, b;
        cout << "enter two numbers:" << endl;

        cin >> a;
        cin >> b;

        cout << "before swap:" << endl;
        cout << a << " ";
        cout << b << endl;
        

        swap(&a, &b);

        cout << "after swap:" << endl;
        cout << a << " ";
        cout << b;

        return 0;
    }