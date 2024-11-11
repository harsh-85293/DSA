void normalize(string &s)
{
    unordered_map<char,char>mpp;
    char start='a';
    int index=0;

    //map each character of s ,x->a y->b
    for(int i=0;i<s.length();i++)
    {
        char curr=s[i];
        if(mpp.find(curr)==mpp.end())
        {
            mpp[curr]=start;
            start++;
        }
    }

    //assigning values of string to a mapped character
    for(int i=0;i<s.length();i++)
    {
        char mappedchar=mpp[s[i]];//x->a y->b y->b
        s[i]=mappedchar;//xyy x->a y->b y->b
    }
}
bool areIsomorphic(string &str1, string &str2)
{
    // Write your code here
    normalize(str1);
    normalize(str2);

    if(str1.compare(str2)==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}