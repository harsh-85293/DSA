    class Solution 
    {
    public:
        //this gives count of palindromic substrings
        int expandaroundcenter(string str,int i,int j)
        {
            int count=0;
            while(i>=0 && j<str.length() && str[i]==str[j])
            {
                count++;
                i--;
                j++;
            }
            return count;
        }

        int countSubstrings(string s) 
        {
            int totalcount=0;//palindromic substrings ka count

            for(int center=0;center<s.length();center++)
            {
                //odd
                int i=center;
                int j=center;
                int oddpalindromicsubstring=expandaroundcenter(s,i,j);//givingpositions already
                
                //even
                i=center;
                j=i+1;
                int evenpalindromicsubstring=expandaroundcenter(s,i,j);

                totalcount = totalcount + oddpalindromicsubstring + evenpalindromicsubstring;
            }
            return totalcount;
        }
    };