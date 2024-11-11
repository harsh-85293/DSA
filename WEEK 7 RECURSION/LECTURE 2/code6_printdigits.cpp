    #include <bits/stdc++.h>
    using namespace std;

    void printdigits(int n)
    {
        //base case
        if(n==0)
        {
            return;
        }

        //baaki recursion sambhal lega
        int newno=n/10;
        printdigits(newno);

        //recursive relation
        //1st case
        int digit=n%10;
        cout << digit << " ";

      
        //processing
    }

    int main()
    {
        int n;
        cout << "enter number:";
        cin >>n;

        printdigits(n);
        return 0;
    }
