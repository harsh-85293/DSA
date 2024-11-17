    #include <bits/stdc++.h>
    using namespace std;

    void insertatbottom(stack<int> &s, int value){
        //base case
        if(s.empty()){
            s.push(value);
            return;
        }

        //ek case mai karunga
        int topelement=s.top();
        s.pop();

        //baaki recursion sambhal lega
        insertatbottom(s, value);

        //backtrack
        s.push(topelement);
    }

    int main(){
        stack<int>s;
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);
        
        int value=13;

        insertatbottom(s, value);
        
        while(!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }cout << endl;
        return 0;
    } 