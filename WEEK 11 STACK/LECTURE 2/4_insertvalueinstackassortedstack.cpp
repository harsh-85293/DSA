    #include <bits/stdc++.h>
    using namespace std;

    void insertsortedstack(stack<int> &s, int val)
    {
        //base case
        if(val>s.top() && !s.empty())
        {
            s.push(val);
            return;
        }
        //ek case mera
        int tope=s.top();
        s.pop();

        //baaki recursion sambhal lega
        insertsortedstack(s, val);

        //backtracking
        s.push(tope);
    }
    
    void printstack(stack<int> s)
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
        cout << "before insertion:" << endl;
        printstack(s);
        int val;
        cout << "enter value of n:";
        cin >> val;
        insertsortedstack(s,  val);
        cout << endl << "after insertion:" << endl;
        printstack(s);
        return 0;   
    } 