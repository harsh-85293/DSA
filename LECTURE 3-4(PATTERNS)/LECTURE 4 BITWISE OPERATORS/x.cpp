#include <iostream>
    int reverse(int x) 
    {
        int n=0;
        int a;
        if(x>0)
        {
            while(x>0)
            {
                a=x%10;
                n=(n*10)+a;
                x=x/10;
            }  
            return n;  
        }
        else
        {
            int m=0;
            int b;
            int y=-(x);
            if(y>0)
            {
                while(y>0)
                {
                    b=y%10;
                    m=(m*10)+b;
                    y=y/10;
                }  
                return (-m);
            } 
        }
        return 0;
    }