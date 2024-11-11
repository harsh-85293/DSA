    #include <bits/stdc++.h>
    using namespace std;

    void removealloccurences(string &s,string sub)
    {
        //sub mil gaya 
        while(s.find(sub)!=string::npos)//starting index->given by find
        {
            //erae(starting index,length)
            s.erase(s.find(sub),sub.length());
        }
    }

    int main()
    {
        string s="harshramchandani";
        string sub="chand";
        removealloccurences(s,sub);
        cout << s;
        return 0;
    }