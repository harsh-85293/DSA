    #include <bits/stdc++.h>
    using namespace std;

    void insertatbottom(stack<int>& s, int val)
    {
        //base case
        if(s.empty())
        {
            s.push(val);
            return; 
        }

        //1 case mera
        int topelement=s.top();
        s.pop();

        //baaki recursion sambhal lega
        insertatbottom(s, val);

        //backtracking
        s.push(topelement);
    }

    void reversestack(stack<int>&s)
    {
        if(s.empty())
        {
            return;
        }
        
        // 1 case mera hai
        int tope=s.top();
        s.pop();

        //baaki recursion sambhal lega
        reversestack(s);

        //jab mai vaapas aaunga
        insertatbottom(s,tope);
    }

    void printstack(stack<int>&s)
    {
        while(!s.empty())
        {
            cout << s.top() << endl;
            s.pop();
        }    
    }
    int main()
    {
        stack<int>s;
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);
        cout << "before stack reversal:" << endl; 
        printstack(s);
        reversestack(s);
        cout << "after stack reversal:" << endl;
        printstack(s);
        return 0;
    } 