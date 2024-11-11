class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        int i=0;
        int j=0;
        int n=s.length();
        vector<int>count(n);

        while(j<s.size())
        {
            s[i]=s[j];//duplicate hatane ke baad agle element ko vaha laya jaha pehle duplicate ka starting tha
            count[i]=1;//count ko reset karo

            if(i>0 && s[i]==s[i-1])
            {
                count[i]+=count[i-1];//duplicate ka count badhate jao
            }

            if(count[i]==k)
            {
                i-=k;//i ko vaha le gaya jaha pe koi duplicate nahi hai
            }

            i++;//i wahi tak jaega jaha tak answer mil jaye
            j++;//j last tak jaega
        }
        return s.substr(0,i);
    }
};