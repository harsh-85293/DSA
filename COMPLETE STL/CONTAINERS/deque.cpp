    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        //creation
        deque<int> dq;

        //insertion
        dq.push_back(10);//10
        dq.push_back(20);//10 20
        dq.push_back(30);//10 20 30 
        dq.push_back(40);//10 20 30 40

        dq.push_front(100);//100 10 20 30 40
        dq.push_front(300);//300 100 10 20 30 40

        //deletion
        dq.pop_front();//100 10 20 30 40
        dq.pop_back();//100 10 20 30
    
        cout << "size of deque:" << dq.size() << endl;

        cout << dq.front() <<endl;//leftmost element=100
        cout << dq.back() << endl;//right most element=30

        //empty
        if(dq.empty()==true)
        {
            cout << "empty" << endl;
        }
        else
        {
            cout << "not empty" << endl;
        }

        //iterator
        deque<int> :: iterator it=dq.begin();
        while(it!=dq.end())
        {
            cout << *it << " ";
            it++;
        }
        cout << endl;

        //accesing as index
        cout << "first value" << dq[0] << endl;
        
        //at method
        cout << "first value" << dq.at(0) << endl;
        
        //clear
        //dq.clear()

        dq.insert(dq.begin(),101);

        dq.erase(dq.begin(),dq.end());
        cout << "size" << dq.size() << endl;

        
        return 0;
    }