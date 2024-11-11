        class Solution 
        {
        public:
            void normalize(string &str)
            {
                char start='a';
                unordered_map <char,char>mapping;

                for(int i=0;i<str.length();i++)
                {
                    char stringkachar=str[i];
                    if(mapping.find(stringkachar)==mapping.end())//character is not been found
                    {
                        mapping[stringkachar]=start;
                        start++;
                    }
                }

                //normslise
                for(int i=0;i<str.length();i++)
                {
                    char mappedcharacter=mapping[str[i]];
                    str[i]=mappedcharacter;
                }
                //humne str wali string ko normalize kar diya hai

            }
            vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
            {
                vector<string> ans;
                normalize(pattern);

                for(int i=0;i<words.size();i++)
                {
                    string currword=words[i];
                    string currwordcopy=currword;

                    normalize(currwordcopy);

                    // The compare function returns:
                    // 0 if the two strings are equal.
                    // A negative value if currwordcopy is lexicographically less than pattern.
                    // A positive value if currwordcopy is lexicographically greater than pattern.
                    if(currwordcopy.compare(pattern))
                    {
                        ans.push_back(currword);
                    }
                }
                return ans;
            }
        };