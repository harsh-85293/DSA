    class Solution 
    {
    public:
        string removeDuplicates(string s) 
        {
            string ans="";//initialize string as empty
            int n=s.length();

            for(int i=0;i<n;i++)
            {
                char charcurrent=s[i];

                if(ans.empty()==1)
                {
                    //if ans is empty seedha push kardo
                    ans.push_back(charcurrent);
                }
                else if(charcurrent==ans.back())
                {
                    //rightmost character of ans=ans.back()
                    ans.pop_back();
                }
                else
                {
                    ans.push_back(charcurrent);
                }
            }
            return ans;
        }
    };