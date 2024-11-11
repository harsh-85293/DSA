    //remember here stack elements shoul be not be popped after returning middle eleemnt
    #include <bits/stdc++.h>
    using namespace std;
    
    void printmiddle(stack<int> &s, int count)
    {
        //base case
        if(count == 0)
        {
            cout << "Middle element is "<< s.top() << endl;
            return;
        }
        
        //1 case mai karunga
        int topelement = s.top();
        s.pop();
        count--;

        //baaki recursion sambhal lega
        printmiddle(s, count);

        //backtracking
        s.push(topelement);
    }
   
    int main()
    {
        stack<int> s;
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);
        int count = s.size()/2;
        printmiddle(s, count);
        return 0;
    } 