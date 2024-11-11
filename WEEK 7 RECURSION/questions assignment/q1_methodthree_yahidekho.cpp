    #include <bits/stdc++.h>
    using namespace std;

    void findlastoccurence(string s,int index,char p,int &ans)
    {
        //base case
        if(s[index]==p &&  index!=s.length())
        {
            ans=index;
        }
        //termination condition
        if(index==s.length())
        {
            return ;
        }
        // 1 case mai solve karunga 

        //baaki recursion sambhal lega
        findlastoccurence(s,index+1,p,ans);
    }

    int main()
    {
        string s = "abcddefg";
        char p = 'd';
        int index=0;
        int ans=-1;
        findlastoccurence(s,index,p,ans);
        cout << p << " found at:" << ans << endl;
        return 0;
    }
