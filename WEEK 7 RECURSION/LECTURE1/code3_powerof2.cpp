    #include <bits/stdc++.h>
    using namespace std;

    int pow(int n)
    {
        //base case 
        if(n==0)
        {
            return 1;
        }

        //recursive relation
        int recursionkaanswer=pow(n-1);
        int finalans=2*recursionkaanswer;
        return finalans; 

        //processing
    }
    int main()
    {
        cout << pow(10);
        return 0;
    }