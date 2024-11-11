    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
        char ch[100]="Racecar";
        char *ptr=&ch[0];

        cout << "ch:" << ch << endl;//Racecar
        cout << "&ch:" << &ch << endl;//Racecar
        cout << "&ch[0]:" << &ch[0] << endl;//
        cout << "*(ch+3):" << *(ch+3) << endl;//e
        cout << "ptr:" << ptr << endl;//Racecar
        cout << "*ptr:" << *ptr << endl;//420
        cout << "*(ptr+3):" << *(ptr+3) << endl;//e
        cout << "ptr+2:" << ptr+2 << endl;//car
        cout << "ptr+4:" << ptr+4 << endl;//cecar
        return 0;
    }