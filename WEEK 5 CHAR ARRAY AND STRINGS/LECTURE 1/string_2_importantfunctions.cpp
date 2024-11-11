    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        string name="Maharana Pratap";
        
        auto it=name.begin();

        while(it!=name.end())
        {
            cout << *it << " ";s
            it++;
        }
        cout << endl;

        cout << name[0] << endl;
        cout << name.at(0) << endl; 

        cout << name.back() << endl;//right most character=p
        cout << name.front() << endl;//leftmost character=M

        cout << name.length() << endl;
        
        //name.clear();
        if(name.empty())
        {
            cout << "string is empty" << endl;
        }
        else
        {
            cout << "string is not empty" << endl;
        }

        //append no need
        string fname="harsh";
        string lname="ramchandani";
        string ans=fname+" "+lname;
        cout << ans << endl;

        //substr
        string s="hello ji kaise jho saare";
        string l="kaise";
        
        //starting and length given
        cout << s.substr(0,2) << endl;

        //starting index defined
        cout << s.substr(5) << endl;

        int answer=s.find(l);//return -1 if not found
        cout << answer << endl;

        if(s.find(l)!=string::npos)//same for defining not found
        {
            cout << "found" << endl;
        }
        else
        {
            cout << "not found" << endl;
        }

        //return value
        string s1="love";
        string s2="love";
        cout << s1.compare(s2) << endl;

        //to check empty
        string v="";
        if (v.empty()==1)
        {
            cout << "string is empty";
        }
        else
        {
            cout << "string is not empty";
        }

        //
        return 0;
    }