    //stored in sorted manner and with o duplicates
    #include <bits/stdc++.h>
    using namespace std;
    
    int main()
    {
        set<int>st;
        st.insert(10);
        st.insert(15);
        st.insert(8);
        st.insert(14);
        st.insert(10);
        
        set<int>::iterator it=st.begin();
        while(it!=st.end())
        {
            cout << *(it) << " ";
            it++;
        }

        //clear
        // st.clear();
        
        if(st.empty()==true)
        {
            cout << "set is not empty" << endl;
        }
        else
        {
            cout << "set is not empty" << endl;
        }

        st.insert(st.begin(),100);

        st.erase(st.begin(),st.end());

        if(st.find(10)!=st.end())
        {
            cout << "not found" << endl;
        }
        else
        {
            cout << "found" << endl;
        }
        return 0;
    }