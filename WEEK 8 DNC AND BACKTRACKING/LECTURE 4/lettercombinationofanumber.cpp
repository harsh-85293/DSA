    class Solution 
    {
    public:

        void solvemapping(string output,unordered_map<char,string>mapping, vector<string>&ans,string digits,int i)
        {
            if(i>=digits.length())
            {
                if(output.length()>0)
                {
                    ans.push_back(output);

                }
                return;
            }
            // 1 case hum solve karenge 
            //baki recursion sambhal lega
            char digit=digits[i];
            string mappedstring=mapping[digit];
            for(char ch:mappedstring)
            {
                output.push_back(ch);
                solvemapping(output,mapping,ans,digits,i+1);
                output.pop_back();
            }
        }

        vector<string> letterCombinations(string digits) 
        {
            vector<string>ans;
            unordered_map<char,string>mapping;

            mapping['2']="abc";
            mapping['3']="def";
            mapping['4']="ghi";
            mapping['5']="jkl";
            mapping['6']="mno";
            mapping['7']="pqrs";
            mapping['8']="tuv";
            mapping['9']="wxyz";
            string output="";
            int i=0;
            solvemapping(output,mapping,ans,digits,i);
            return ans;
        }
    };