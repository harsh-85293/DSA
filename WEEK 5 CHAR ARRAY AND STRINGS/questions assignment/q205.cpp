    class Solution {
    public:
        void normalise(string &str)
        {
            char start='a';
            unordered_map <char,char>mapping;


            //just mapping the characters
            for(int i=0;i<str.length();i++)
            {
                char stringkachar=str[i];
                //key not found
                if(mapping.find(stringkachar)==mapping.end())
                {
                    mapping[stringkachar]=start;
                    start++;
                }
            }

            //normalise->value assigning of the string
            for(int i=0;i<str.length();i++)
            {
                char mappedcharacter=mapping[str[i]];
                str[i]=mappedcharacter;
            }
            //humne str wali string ko normalize kar diya hai

        }
        bool isIsomorphic(string s, string t) 
        {
            normalise(s);
            normalise(t);
            if(s.compare(t)==0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    };