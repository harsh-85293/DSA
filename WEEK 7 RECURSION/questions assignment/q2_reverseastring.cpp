    #include <bits/stdc++.h>
    using namespace std;

    void reversestring(string &str,int s,int e)
    {
        //base case
        if(s>e)
        {
            return;
        }
        //1 case mai solve karunga
        swap(str[s],str[e]);
        
        //baaki recursion sambhal lega
        reversestring(str,s+1,e-1);
    }
    
    int main()
    {
        string str="harshr";
        int s=0;
        int e=str.length()-1;
        reversestring(str,s,e);
        cout <<  str;
        return 0;
    }