    #include <iostream>
    #include <string>
    using namespace std;
    
    string calc_Sum(int *a,int n,int *b,int m)
        {
        // Complete the function
            int n1=0;
            for(int i=0;i<n;i++)
            {
                n1=(n1*10)+a[i];
            }
            
            int n2=0;
            for(int i=0;i<m;i++)
            {
                n2=(n2*10)+b[i];
            }
            
            int res=n1+n2;
            return res;
            
        }

        int main()
        {
            int a[]={1,2};
            int b[]={2,1};
            int m=2;
            int n=2;
            string calc_sum(a,n,b,m);   
            return 0;
        }