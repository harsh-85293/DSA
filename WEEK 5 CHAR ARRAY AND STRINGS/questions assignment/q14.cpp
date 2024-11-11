    class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) 
        {
            //find substring ka first occurence batata hai
            string ans=strs[0];
            for(int i=1;i<strs.size();i++)
            {
                while(strs[i].find(ans)!=0)
                {
                    ans=ans.substr(0,ans.length()-1);
                    cout << ans << " ";
                }
            }
            return ans;
        }
    };