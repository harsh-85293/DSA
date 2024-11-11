    #include <bits/stdc++.h>
    using namespace std;

    void printsubsequence(string str,int index,string output,vector<string> &ans)
    {
        //base case
        if(index==str.length())
        {
            ans.push_back(output);
            cout << output << endl;
            return;
        }
        //1 case mai karunga
        char ch=str[index];
        //include
        printsubsequence(str,index+1,output+ch,ans);
        //exclude
        printsubsequence(str,index+1,output,ans);
        //baki recursion karega
    }

    int main()
    {
        string str="abc";
        string output="";
        int index=0;
        vector<string> ans;
        printsubsequence(str,index,output,ans);
        
        for(auto it:ans)
        {
            cout << it << " ";
        }
        return 0;
    }