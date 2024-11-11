class Solution {
public:
    int beautySum(string s) 
    {
        int beautysum=0;
        unordered_map<char,int> mp;

        //finding all substrings
        for(int i=0;i<s.size();i++)
        {
            mp.clear();
            for(int j=i;j<s.size();j++)
            {
                char &ch=s[j];
                mp[ch]++;//frequency updation of each character

                int mini=INT_MAX;
                int maxi=INT_MIN;

                for(auto it:mp)
                {
                    maxi=max(maxi,it.second);
                    mini=min(mini,it.second);
                }
                int beauty=maxi-mini;
                beautysum+=beauty;
            }
        }
            return beautysum;
    }
};