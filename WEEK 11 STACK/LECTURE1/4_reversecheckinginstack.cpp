    #include <bits/stdc++.h>
    using namespace std;

    int main(){
        stack<char>s;
        string name="falguni";

        // insertion of characters in stack
        for(int i = 0; i < name.length(); i++){
            s.push(name[i]);
        }

        // retrieval of characters in stack s
        while(!s.empty()){
            cout << s.top();
            s.pop();
        } 
        return 0;
    } 