    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        // minimum value as higher priority
        priority_queue<int,vector<int>,greater<int>>pq;

        pq.push(10);//10
        pq.push(20);//20 10
        pq.push(30);//10 20 30
        pq.push(40);//10 20 30 40

        //top element->highest priority
        cout << pq.top() << endl;//10

        //10 popped out as it is the eleement with highest priority
        pq.pop();

        cout << "now top:" << pq.top() << endl;//20

        return 0;
    }