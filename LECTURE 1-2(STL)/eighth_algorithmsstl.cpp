    #include <iostream>
    #include <algorithm>
    #include <vector>
    using namespace std;

    int main()
    {
        vector <int>v;

        v.push_back(1);
        v.push_back(3);
        v.push_back(5);
        v.push_back(6);
        v.push_back(7);

        cout << "binary search:" << endl;

        cout << binary_search(v.begin(),v.end(),5)<< endl;

        cout <<"finding out 6:" <<binary_search(v.begin(),v.end(),6)<< endl;

        cout << "lower bound->" << lower_bound(v.begin(),v.end(),6) -v.begin() << endl;

        cout << "upper bound->"<< upper_bound(v.begin(),v.end(),4)-v.begin() << endl;

        int a=4;
        int b=3;

        cout << "max->" <<max(a,b);

        cout << "minimum:" <<min(a,b);

        swap(a,b);

        cout << " a and b:" << a << b << endl; 

        string s ="abcd";
        
        reverse(s.begin(),s.end());

        cout << "string :" << s<< endl;

        rotate(v.begin(),v.begin()+1,v.end());

        cout <<"after rotate:" << endl;
        for(int i:v)
        {
            cout << i << "";
        }cout << endl;
        

        return 0;
    }