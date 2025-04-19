    #include <iostream>
    #include <queue>
    using namespace std;

    int main()
    {
        //creation
        queue<int> q;// follows FIFO 

        //insertion
        q.push(10);//10
        q.push(20);//10 20
        q.push(30);//10 20 30
        q.push(40);//10 20 30 40

        //no clear method

        //size
        cout << "size is:"<< q.size() <<endl; //4
        
        q.pop();//20 30 40 

        cout << "new size is:"<< q.size() <<endl;//3 

        cout << "front element is:" << q.front() << endl;//20 leftmost
        cout << "back element is:" << q.back() << endl;//40 rightmost
        
        //empty
        if(q.empty()==true)
        {
            cout << "vector is not empty" << endl;
        }
        else
        {
            cout << "vector is not empty" << endl;
        }

        queue<int> first;
        queue<int> second;

        first.push(10);    
        first.push(20);
        first.push(30);
        first.push(40);
        first.push(50);

        second.push(100);    
        second.push(200);
        second.push(300);
        second.push(400);
        second.push(500);

        cout << "old front element of first queue is:" << first.front() << endl;

        first.swap(second);

        cout << "new front element of first queue is:" << first.front() << endl;
        return 0;
    }