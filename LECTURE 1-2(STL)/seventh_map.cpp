    #include <iostream>
    using namespace std;
    #include <map>

    int main()
    {
        map<int,string>m;

        m[1]="harsh";
        m[2]="ramchandani";
        m[13]="lal";

        for(auto i:m)
        {
            cout << i.first<< endl;
        }

        m.insert({5,"bheem"});

        for(auto i:m)
        {
            cout<< i.first<< " " << i.second << endl;
        }
        
        cout << "finding 13" << m.count(13) << endl;

        cout << "before erase:" <<endl;
        for(auto i:m)
        {
            cout<< i.first<< " " << i.second << endl;
        }
        
        m.erase(13);
        cout << "after erase:"<< endl;
        for(auto i:m)
        {
            cout<< i.first<< " " << i.second << endl;
        }

        auto it=m.find(5);
        for(auto i=it;i!=m.end();i++)
        {
            cout << (*i).first << endl;
        }
        return 0;
    }