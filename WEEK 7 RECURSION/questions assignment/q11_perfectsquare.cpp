    #include <bits/stdc++.h>
    using namespace std;
    class Solution 
    {
        public:
            int numbersquarehelper(int n)
            {
                if(n==0) return 1;
                if(n<0) return 0;

                int ans=INT_MAX;
                int i=1;
                int end=sqrt(n);

                while(i<=end)
                {
                    int perfectsquare=i*i;
                    int numberofperfectsquares=1+numbersquarehelper(n-perfectsquare);
                    if(numberofperfectsquares<ans)
                    {
                        ans=numberofperfectsquares;
                    }
                    ++i;
                }
                return ans;
            }

            int numSquares(int n) 
            {
                return numbersquarehelper(n)-1;
            }
    };
    int main()
    {
        Solution S;
        cout << S.numSquares(12) << endl;
        return 0;
    } 