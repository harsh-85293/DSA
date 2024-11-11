    #include <bits/stdc++.h>
    using namespace std;

    //printing count from n to 1
    void printcount(int n)
    {
        //base case
        if(n==0)
        {
            return ;
        }
        
        //processing
        cout << n << " ";

        //recursive call
        printcount(n-1); 
    }

    int main()
    {
        int n;
        cout << "enter the value of n:";
        cin >> n;

        printcount(n);
        return 0;
    }