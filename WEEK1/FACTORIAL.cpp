    #include<iostream>
    using namespace std;

    int main() 
    {
        int fact=1;
        int n;

        cout << "enter number whose factorial you want:";
        cin >> n;

        for(int i=1;i<=n;i++)
        {
            fact=fact*i;
        }
        
        if(n==0 || n==1)
        {
            cout << "factorial is 1"  << endl;
        }
        
        else
        {
            cout << "factorial is :"<<  fact;
        }
        return 0;
    }
