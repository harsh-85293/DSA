    #include <bits/stdc++.h>
    using namespace std;

    class Solution {
        public:
            string FirstNonRepeating(string A)
            {
                // Code here
                unordered_map<char, int>freq;
                string ans="";
                queue<int> q;
                
                for(int i=0; i<A.length(); i++)
                {
                    char ch = A[i];
                    //intital state maintain karne ke liye
                    freq[ch]++;
                    q.push(ch);
                    //lets finfd the answer now
                    while(!q.empty())
                    {
                        char frontelement = q.front();
                        //check whether front element is answer
                        if(freq[frontelement] == 1)
                        {
                            ans.push_back(frontelement);
                            break;
                        }
                        else
                        {
                            q.pop(); 		            
                        }
                    }
                    
                    //agar duplicate element the to q empty hogi
                    //agar nahi hai unique eleement h toh q empty nahi hogi
                    if(q.empty())
                    {
                        ans.push_back('#');
                    }
                }
                return ans;
                
            }
    };

    int main()
    {
        Solution s;
        string A="aabc";
        cout << s.FirstNonRepeating(A);
        return 0;
    }