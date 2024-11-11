    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
        //declaration
        queue<int>q;

        //insertion
        q.push(10);
        q.push(20);
        q.push(30);
        q.push(40);
        
        //front element
        cout << "Front element is:" << q.front() << endl;

        //rear end element or last element
        cout << "back/last element is:" << q.back() << endl;
        
        //pop element
        q.pop();//10 was inserted at first so it will be popped

        //now new front element
        cout << "Front element is:" << q.front() << endl;

        //size of queue
        cout << "size of queue is:" << q.size() << endl;

        //empty or not
        q.empty()==1?cout << "empty" << endl : cout << "not empty" << endl;

        //printing elements
        while(!q.empty())
        {
            cout << q.front() << endl;
            q.pop();
        }

        return 0;
    } 