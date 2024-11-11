    #include <bits/stdc++.h>
    using namespace std;

    
    int main()
    {
        vector<string> bank = {"011001","000000","010100","001000"}; 

        int n=bank.size();
        vector<int>count(n);
        for(int i=0;i<bank.size();i++)
        {
            for(char ch:bank[i])
            {
                if(ch=='1')
                {
                    count[i]+=1;
                }
            }
            //cout << count[i] << " ";
        }    
        
        int i=0;
        int j=1;
        int finalans=0;
        while(j<count.size() && i<count.size())
        {
            if((count[i]!=0 && count[j]!=0) && i!=j)
            {
                finalans+=count[i]*count[j];
                i++;
                j++;
            }   
            else if(i==j)
            {
                j++;
            }
            else if(count[i]==0)
            {
                i++;
            }
            else if(count[j]==0)
            {
                j++;
            }
            // else if (count[i]==0 &&count[j]==0)
            // {
            //     i++;
            //     j++;
            // }
        }

        cout << endl<< finalans <<endl;;
        return 0;
    }
