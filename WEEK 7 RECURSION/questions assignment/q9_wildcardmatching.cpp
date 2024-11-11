    #include <bits/stdc++.h>
    using namespace std;
    class Solution 
    {
        public:
            bool ans(string &s, int i, string &p, int j)
            {
                //base case
                if(i==s.size() && j==p.size())
                {
                    return true;
                }
                
                if(i==s.size() && j<p.size())
                {
                    while(j<p.size())
                    {
                        if(p[j]!='*')
                        {
                            return false;
                            
                        }
                        j++;
                    }
                    return true;
                }

                //single char matching
                if(s[i]==p[j] || p[j]=='?')
                {
                    return ans(s,i+1,p,j+1);
                }

                if(p[j]=='*')
                { 
                    //treat * as empty or null
                    bool caseA=ans(s,i,p,j+1);

                    //let * consume one char
                    bool caseB=ans(s,i+1,p,j);

                    return caseA||caseB;
                }
                //characrter does not match
                return false;
        } 

        bool isMatch(string s, string p) 
        {
            int i=0;//starting index for s string
            int j=0;//starting index for p string
            return ans(s,i,p,j);
        }
    };

    int main()
    {
        Solution S;
        string s="aa";
        string p="a";
        cout << S.ans(s,s.length(),p,p.length());
        return 0;
    }