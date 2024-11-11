    class Solution 
    {
    public:
        string decodeMessage(string key, string message) 
        {
            unordered_map<char,char> mapping;
            char space=' ';
            mapping[space]=space;
            char start='a';
            int index=0;
            
            while( start <='z' && index<key.length() ) 
            {
                char keykacurrentcharacter=key[index];
                // If the character is already in the map, skip it.
                 //find ->returns the iterator at which key is found
                if(mapping.find(keykacurrentcharacter)!=mapping.end())
                {
                    index++;
                }
                // Map the current key character to the current alphabet character.
                else
                {
                    mapping[keykacurrentcharacter]=start;
                    start++;
                    index++;
                }
            }

            string ans="";
            for(int i=0;i<message.length();i++)
            {
                char msgcharacter=message[i];
                char mappedcharacter=mapping[msgcharacter];
                ans.push_back(mappedcharacter);
            }
            return ans;
        }
    };