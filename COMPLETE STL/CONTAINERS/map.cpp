    //collection of key and values
    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        //creation
        unordered_map <string,string> table;

        //insertion
        table["in"]="India";//1
        
        //2
        table.insert(make_pair("en","England"));

        //3
        pair <string,string> pr;
        pr.first="br";//key
        pr.second="brazil";//value
        table.insert(pr);
        
        //size
        cout << "size of map:" << table.size() << endl;

        //clear
        //table.clear();
        
        //empty
        if(table.empty()==true)
        {
            cout << "map is not empty" << endl;
        }
        else
        {
            cout << "map is not empty" << endl;
        }

        //value at a particular key
        cout << table.at("in") << endl; //India 

        //modify
        table["in"]="harsh";
        table.at("in")="India2";

        unordered_map<string,string> ::iterator it=table.begin();
        while(it!=table.end())
        {
            pair<string,string> p=*it;
            cout << p.first  << " " << p.second << endl;;
            it++;
        }
        cout << endl;

        //size
        cout << "size:" << table.size() << endl;

        //erase
        table.erase(table.begin(),table.end());
        cout << "size of table:" << table.size() << endl;
        
        //find ->returns the iterator at which key is found
        if(table.find("in")!=table.end())
        {
            cout << "key found"  <<endl;
        }
        else
        {
            cout << "key not found" << endl;
        }

        //count-> 0(not found)  1(found)
        if(table.count("in")==0)
        {
            cout << "key not found" << endl;
        }
        else
        {
            cout << "key found" << endl;
        }

        //ordered map
        map <int,string> orderedmap;
        orderedmap[3]="lalita baby";
        orderedmap[2]="babitababy";
        orderedmap[1]="anitababy";


        map<int, string>::iterator it7 = orderedmap.begin();
        while (it7 != orderedmap.end())
        {
            // Correct type for p1 is pair<int, string>
            pair<int, string> p1 = (*it7);
            cout << p1.first << " " << p1.second << endl;
            it7++;
        }

        //find frequency of characters in a string using map
        string s="aasknsa";
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            mp[ch]++;
        }
        //find max and min frequency in a map
        int minf=INT_MAX;
        int maxf=INT_MIN;

        for(auto it:mp)
        {
            minf=min(minf,it.second);
            maxf=min(maxf,it.second);
        }

        return 0;
    }