    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        //creation
        priority_queue<int> pq;

        //insertion
        pq.push(10);//10
        pq.push(20);//20 10
        pq.push(30);//30 20 10
        pq.push(40);//40 30 20 10

        //top element->highest priority
        cout << pq.top() << endl;//40

        //40 popped out as it is the eleement with highest priority
        pq.pop();

        cout << "now top:" << pq.top() << endl;//30

        cout << "size of deque:" << pq.size() << endl;

        if(pq.empty()==true)
        {
            cout << "priority queue is not empty" << endl;
        }
        else
        {
            cout << "priority queue is not empty" << endl;
        }

        return 0;
    }