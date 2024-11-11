    #include <bits/stdc++.h>
    using namespace std;
    
    int main()
    {
        string s="aab";

        int hash[26]={0};

        for(int i=0;i<s.size();i++)
        {
            hash[s[i]-'a']++;
        }
        //find the most occurent character
        char mostfrequentchar;
        int max_freq=INT_MIN;
        for(int i=0;i<26;i++)
        {
            if(hash[i]>max_freq)
            {
                max_freq=hash[i];
                mostfrequentchar=i+'a';
            }
        }

        //placing mostoccuring character
        int index=0;
        while(max_freq>0 && index<s.size())
        {
            s[index]=mostfrequentchar;
            max_freq--;
            index+=2;
        }

        if(max_freq!=0)
        {
            return "";
        }
        
        hash[mostfrequentchar-'a']=0;
        
        //lets place rest of characters
        for(int i=0;i<26;i++)
        {
            while(hash[i]>0)
            {
                index=index>=s.size()?1:index;
                s[index]=i+'a';
                hash[i]--;
                index+=2;
            }
        }
        return s;

        return 0;
    }