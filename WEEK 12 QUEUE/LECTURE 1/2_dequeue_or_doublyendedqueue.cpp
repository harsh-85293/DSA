    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
        //declaration
        deque<int>dq;

        //insertion
        dq.push_front(10);
        //10
        dq.push_front(30);
        //10 30 
        dq.push_front(50);
        //10 30 50
        dq.push_back(70);
        //70 10 30 50
        dq.push_back(100);
        //100 70 10 30 50

        //size
        cout << "size:" << dq.size() << endl;

        //empty or not
        dq.empty()==1?cout << "empty" << endl : cout << "not empty" << endl;

        //front element
        cout << "front element is:" << dq.front() << endl;

        //back element
        cout << "back element is:" << dq.back() << endl;

        //removal
        dq.pop_front();
        cout << "front element is:" << dq.front() << endl;

        dq.pop_back();
        cout << "back element is:" << dq.back() << endl;
        return 0;
    } 