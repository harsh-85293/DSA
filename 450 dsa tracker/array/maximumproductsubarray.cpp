    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        vector<int>arr={6, -3, -10, 0, 2};

        int posn=0;
        int negn=0;
        int posp=1;
        int negp=1;
        int minno=INT_MAX;

        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<minno && arr[i]!=0)
            {
                minno=arr[i];
            }
            if(arr[i]<0)
            {
                negn++;
            }
            else
            {
                posn++;
            }
        }

        int p=1;
        if(negn%2==0)
        {   
            for(int i=0;i<arr.size();i++)
            {
                if(arr[i]==0)
                {
                    continue;
                }
                else
                {  
                    p*=arr[i];
                }
            }
            cout <<  p;
        }

        else
        {   
            int g=p/minno;
            cout << g;
        }
        
        return 0;
    }