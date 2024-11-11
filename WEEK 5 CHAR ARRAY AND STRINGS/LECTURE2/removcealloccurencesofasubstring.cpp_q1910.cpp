class Solution {
public:
    string removeOccurrences(string s, string part) 
    {
        //jab tak s ke andar part na mile tab tak loop chalao
        while(s.find(part)!=string::npos)
        {
            //fullstring me erase karo
            //erase function ke 2 arguement hai
            //first arguement mai patern ka starting index dena hai
            //s.find(part) hume starting index deta hai 
            //2nd arguement me kitne character remove karne hai wo dalna hai
            s.erase(s.find(part),part.length());
        }
        return s;
    }
};