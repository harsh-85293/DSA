    #include <bits/stdc++.h>
    
    using namespace std;
    int main()
    {
        // order is not maintained
        unordered_map<int ,int> table;
        table[1]=53;
        table[2]=54; 
        table[3]=55; 
        table[4]=56; 
        
        for(auto it:table)
        {
            int key=it.first;
            int value=it.second;

            cout << "key:" << key << "-> value->" << value << endl;
        }

        if(table.find(2)!=table.end())//key is available or not
        {
            //found
            int value=table[2];
            cout << "value found:" << value << endl;
        }

        else
        {
            //not found
            cout << "value not found" << endl;
        }

        table.erase(2);
        for(auto it:table)
        {
            int key=it.first;
            int value=it.second;

            cout << "key:" << key << "-> value->" << value << endl;
        }

        cout << "finding 2 again:" << endl;

        if(table.find(2)!=table.end())//key is available or not
        {
            //found
            int value=table[2];
            cout << "value found:" << value << endl;
        }

        else
        {
            //not found
            cout << "value not found" << endl;
        }

        return 0;
    }