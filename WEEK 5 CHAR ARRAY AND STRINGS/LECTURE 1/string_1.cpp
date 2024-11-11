    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        //creation
        string str;
        str.push_back('h');
        str.push_back('a');
        str.push_back('r');
        str.push_back('s');
        str.push_back('h');

        cout << "string is:"  << str << endl;

        string name;
        //input
        cout << "enter the value of string:";;
        //cin >> str;
        getline(cin,name);//for whole sentence

        //output
        cout << "string:"<< name  << endl;
        cout << name[0] << endl;
        return 0;
    }